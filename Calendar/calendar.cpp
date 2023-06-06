#include "calendar.h"
#include "ui_calendar.h"
#include <QDate>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QMap>
#include <QVector>
#include <QTimeEdit>
#include <QLayout>
#include <QBoxLayout>
#include <QMainWindow>
#include <QTextCharFormat>
#include <QMessageBox>
#include <QDataStream>
#include <QIODevice>
#include <algorithm>
//#include <QList>
//#include <QLayout>


//std::map<QDate,std::vector<calendar_event>> cmap = new std::map<QDate,std::vector<calendar_event>>;
//QDate current_date = QDate(2023, 6, 1);
//Calendar::resizeEvent(QResizeEvent *event){
//    ui->verticalLayout_main->setGeometry(rect());
//    Calendar::resizeEvent(event);
//}

void Calendar::save(){
    QFile file("calendar_data.serialized");
    if (file.open(QIODevice::ReadWrite)) {
        QDataStream stream(&file);
        stream << c_map;
        file.close();
        return;
    }
}

// Loading the c_map from a file

void Calendar::load(){
    QFile file("calendar_data.serialized");
    if (file.open(QIODevice::ReadOnly)) {
        QDataStream stream(&file);
        stream >> c_map;
        file.close();
        return;
    }
}

Calendar::Calendar(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calendar)
    , c_map() // read it from file
{
    ui->setupUi(this);
    current_date = QDate::currentDate();
    selected_button = - 1; // using this while editing events
    ui->calendarWidget->setSelectedDate(current_date);
    ui->calendarWidget->setMaximumDate(QDate(2023,12,31));
    this->load();
    this->ui->centralwidget->setLayout(ui->verticalLayout_main);
    this->setCentralWidget(ui->centralwidget);
    this->resize(400, 400);
    this->update_ui();
}

Calendar::~Calendar()
{
    delete ui;
}

// more an update day??
// i should implement a nextpage and previous page
void Calendar::update_ui(){
    current_date = ui->calendarWidget->selectedDate();
    current_page = 0;
    ui->pushButton_previousPage->setEnabled(false);
    ui->pushButton_confirm_edit->setVisible(false);
    auto it = this->c_map.find(current_date);
    if (it != this->c_map.end()&&
        !c_map[current_date].empty())
    {
        qDebug() <<  "eventi presenti" ;
        ui->label_vecSize->setText(QString::number(c_map[current_date].size()));
        (c_map[current_date].size()<= 3)?
            ui->pushButton_nextPage->setEnabled(false):
            ui->pushButton_nextPage->setEnabled(true);
    }

    else {
        qDebug() << "nessun evento questo giorno" ;
        ui->label_vecSize->setText(QString::number(0));
        ui->pushButton_nextPage->setEnabled(false);
    }
    ui->label->setText(current_date.toString("dd/MM/yyyy"));
    this->setColors();
    this->go_to_page(current_page);
}


void Calendar::on_calendarWidget_selectionChanged(){
    qDebug() << "updating interface";
    this->update_ui();
}

calendar_event Calendar::create_event_from_ui(){
    event_type tmp_type;
    QString tmp_descr;
    QTime tmp_time_start;
    QTime tmp_time_end;
    event_repeat tmp_repeat;
    (ui->comboBox_evento->currentText() == "Evento")?
        tmp_type = EVENT: tmp_type = ACTIVITY;
    tmp_repeat = string_to_event_repeat
        (ui->comboBox_ripetizione->currentText());
    tmp_time_start = ui->timeEdit_start->time();
    tmp_time_end = ui->timeEdit_end->time();
    tmp_descr = ui->lineEdit->text();
    return calendar_event(tmp_type, tmp_descr, tmp_time_start,
                          tmp_time_end, tmp_repeat);
}

bool valid_event(calendar_event c_e){
    // label check
    if (c_e.descr.isEmpty()) {
        QMessageBox::critical(nullptr, "Error", "Description cannot be empty");
        return false;
    }

    // duration check
    if(c_e.time_end == QTime(0,0)){ // single event
        return true;
    }else if( c_e.time_start  >= c_e.time_end){
        QMessageBox::critical(nullptr, "Error",
                              ("duration not valid: use :00"
                               "if you don't want to specify end time"));
        return false;
    }
    return true;
}


void Calendar::on_pushButton_clicked(){
    calendar_event tmp = create_event_from_ui();
    qDebug() << "printing tmp";
    tmp.print();
    if (!valid_event(tmp))
        return;
    // check if date entry exists or create one
    auto it = this->c_map.find(current_date);
    if(it == this->c_map.end()){
        qDebug() << "creo una nuova pagina per " << current_date.toString() ;
        c_map[current_date] = QVector<calendar_event>();
    }
    insert_event(tmp, tmp.repeat);
    this->update_ui();
}

int Calendar::insert_event(calendar_event e, event_repeat rep){
    switch (rep){
    case WEEKLY:
        for (QDate d = current_date;
             d < ui->calendarWidget->maximumDate();
             d = d.addDays(7)){
            for (int i = 0; i < c_map[d].size(); i++){
                if (checkEventsOverlap(e, c_map[d][i])){
                    QMessageBox::information(nullptr, "Information",
                                             ("Event Overlapping on " +
                                              d.toString() ));
                    return -1;
                }
            }
        }
        for (QDate d = current_date;
             d < ui->calendarWidget->maximumDate();
             d = d.addDays(7))
        {
                c_map[d].push_back(e);
                std::sort(c_map[d].begin(),c_map[d].end());
        }
        break;

    case MONTHLY:
        for (QDate d = current_date;
             d < ui->calendarWidget->maximumDate();
             d = d.addMonths(1)){
            for (int i = 0; i < c_map[d].size(); i++){
                if (checkEventsOverlap(e, c_map[d][i])){
                    QMessageBox::information(nullptr, "Information",
                                             ("Event Overlapping on " +
                                              d.toString() ));
                    return -1;
                }
            }
        }
        for (QDate d = current_date;
             d < ui->calendarWidget->maximumDate();
             d = d.addMonths(1))
        {
                c_map[d].push_back(e);
            std::sort(c_map[d].begin(),c_map[d].end());
        }
        break;
    case YEARLY:
        for (QDate d = current_date;
             d < ui->calendarWidget->maximumDate();
             d = d.addYears(1)){
                for (int i = 0; i < c_map[d].size(); i++){
                    if (checkEventsOverlap(e, c_map[d][i])){
                        QMessageBox::information(nullptr, "Information",
                                             ("Event Overlapping on " +
                                              d.toString() ));
                        return -1;
                    }
                }     }
        for (QDate d = current_date;
             d < ui->calendarWidget->maximumDate();
             d = d.addYears(1))
        {
                c_map[d].push_back(e);
                std::sort(c_map[d].begin(),c_map[d].end());
        }
        break;

    default:
        for (int i = 0; i < c_map[current_date].size(); i++){
            if (checkEventsOverlap(e, c_map[current_date][i])){
                QMessageBox::information(nullptr, "Information",
                                             ("Event Overlapping on " +
                                              current_date.toString() ));
                return -1;
            }
        }
        c_map[current_date].push_back(e);
        //std::sort(c_map[current_date].begin(),
        //          c_map[current_date].end());
        std::sort(c_map[current_date].begin(), c_map[current_date].end());
    }
        save();
        return 0;
}

void Calendar::on_comboBox_evento_currentIndexChanged(int index){
    if (index == 1){
        qDebug() << "selected Evento";
        //ui->comboBox_ripetizione->setCurrentIndex(2);
        //ui->comboBox_ripetizione->setEnabled(false);
        ui->timeEdit_start->setEnabled(false);
        ui->timeEdit_end->setEnabled(false);
        ui->timeEdit_start->setTime(QTime(0 , 0));
        ui->timeEdit_end->setTime(QTime(23, 59));
    }
    if (index == 0){
        qDebug() << "selected Attività";
        //ui->comboBox_ripetizione->setCurrentIndex(0);
        //ui->comboBox_ripetizione->setEnabled(true);
        ui->timeEdit_start->setEnabled(true);
        ui->timeEdit_end->setEnabled(true);
        ui->timeEdit_start->setTime(QTime(0 , 0));
        ui->timeEdit_end->setTime(QTime(0, 0));
    }

}

// operator definition to sort
bool operator<(const calendar_event& lhs,
               const calendar_event& rhs){
    return lhs.time_start < rhs.time_start;
}


// check for ovarlapping -> true if overlaps
bool checkEventsOverlap(const calendar_event& event1,
                        const calendar_event& event2) {
    if (event1.type == EVENT || event2.type == EVENT)
        return false;
    if (event1.time_end == QTime(0,0)&&
        event2.time_end == QTime(0,0)){
        return event1.time_start == event2.time_start;
    }
    else if (event1.time_end == QTime(0,0)){
        return (event1.time_start > event2.time_start &&
                event1.time_start < event2.time_end);
    }
    else if (event2.time_end == QTime(0,0)){
        return (event2.time_start > event1.time_start &&
                event2.time_start < event1.time_end);
    }
    else if (event1.time_end <= event2.time_start ||
        event2.time_end <= event1.time_start) {
        return false;
    }
    else {
        return true;
    }
}



void Calendar::on_pushButton_nextPage_clicked()
{
    go_to_page(current_page + 1);
}


void Calendar::on_pushButton_previousPage_clicked()
{
    //assert(currentpage>=1);
    go_to_page(current_page - 1);
}


void Calendar::go_to_page(int page){
    current_page = page;
    ui->label_vecSize->setText(QString::number(c_map[current_date].size()));
    ui->label_page->setText(QString::number(page));
    (current_page > 1)?
        ui->pushButton_previousPage->setEnabled(true):
        ui->pushButton_previousPage->setEnabled(false);

    int number_of_events  = c_map[current_date].size();

    (number_of_events - (current_page * 3) > 3)?
        ui->pushButton_nextPage->setEnabled(true):
        ui->pushButton_nextPage->setEnabled(false);

    int shown_events = 0;

    QVector<QHBoxLayout*> layouts = {
        ui->centralwidget->findChild<QHBoxLayout*>("horizontalLayout_data_1"),
        ui->centralwidget->findChild<QHBoxLayout*>("horizontalLayout_data_2"),
        ui->centralwidget->findChild<QHBoxLayout*>("horizontalLayout_data_3")
    };
    //QLabel* labels[] = {} ma così sono piu tranquillo
    QVector<QLabel*> tipo_labels = {
        ui->label_tipo_1,
        ui->label_tipo_2,
        ui->label_tipo_3
    };
    QVector<QLabel*> descrizione_labels = {
        ui->label_descrizione_1,
        ui->label_descrizione_2,
        ui->label_descrizione_3
    };
    QVector<QLabel*> time_start_labels = {
        ui->label_start_1,
        ui->label_start_2,
        ui->label_start_3
    };
    QVector<QLabel*> time_end_labels = {
        ui->label_end_1,
        ui->label_end_2,
        ui->label_end_3
    };
    QVector<QLabel*> ripetizione_labels = {
        ui->label_ripetizione_1,
        ui->label_ripetizione_2,
        ui->label_ripetizione_3
    };

    for (const auto& lyt : layouts){
        if (lyt &&
            ((current_page*3) + shown_events) >=
                       (number_of_events)) {
            for (int i = 0; i < lyt->count(); ++i) {
                QWidget* widget = lyt->itemAt(i)->widget();
                if (widget){
                    widget->setVisible(false);
                }
            }
        }else{
            assert (lyt!= nullptr);
            descrizione_labels[shown_events]->setText(c_map[current_date]
                                               [(current_page*3)+shown_events]
                                                   .descr);
            time_start_labels[shown_events]->setText(c_map[current_date]
                                               [(current_page*3)+shown_events]
                                                   .time_start.toString());
            (c_map[current_date][(current_page*3)+shown_events]
                 .time_end !=   QTime(0,0))?
                time_end_labels[shown_events]->setText(c_map[current_date]
                                               [(current_page*3)+shown_events]
                                                   .time_end.toString()):
                time_end_labels[shown_events]->setText("-");
            tipo_labels[shown_events]->setText(event_type_to_string
                                                      (c_map[current_date]
                                               [(current_page*3)+shown_events]
                                                   .type));
            ripetizione_labels[shown_events]->setText(event_repeat_to_string
                                                      (c_map[current_date]
                                               [(current_page*3)+shown_events]
                                                   .repeat));

            for (int i = 0; i < lyt->count(); ++i) {
                QWidget* widget = lyt->itemAt(i)->widget();
                if (widget){
                    widget->setVisible(true);
                }
            }
        shown_events += 1;
        }
    }
    // sembra sbagliato
    //if (shown_events < 3){
    //    ui->pushButton_nextPage->setEnabled(false);
    //}
    if (current_page > 0){
        ui->pushButton_previousPage->setEnabled(true);
    }
}

// todo disable > button on some conditions
QString event_type_to_string(event_type e){
    switch(e){
    case ACTIVITY:
        return QString("Attività");
        //break;
    case EVENT:
        return QString("Event");
    default:
        qDebug() << "event parsing error";
        return QString("ERROR");
    }
}

QString event_repeat_to_string(event_repeat e){
    switch(e){
    case YEARLY:
        return QString("Annuale");
        //break;
    case MONTHLY:
        return QString("Mensile");
    case WEEKLY:
        return QString("Settimanale");
    case NOREPEAT:
    default:
        return QString("-");
    }
}
event_repeat string_to_event_repeat(QString s){
    if (s == "Mensile")
        return MONTHLY;
    if (s == "Annuale")
        return YEARLY;
    if (s == "Settimanale")
        return WEEKLY;
    return NOREPEAT;
}

void Calendar::on_pushButton_delete_1_clicked(){
    int index = current_page * 3;
    delete_entry(current_date, index);
    go_to_page(0);
}


void Calendar::on_pushButton_delete_2_clicked(){
    int index = current_page * 3 + 1;
    delete_entry(current_date, index);
    go_to_page(0);
}


void Calendar::on_pushButton_delete_3_clicked(){
    int index = current_page * 3 + 2;
    delete_entry(current_date, index);
    go_to_page(0);
}

// i could use current_date
calendar_event Calendar::delete_entry(QDate date, int index){
    assert(index >= 0);
    assert(index < c_map[current_date].size());
    return c_map[date].takeAt(index);
}

void Calendar::setColors(){
    QTextCharFormat format;
    format.setBackground(Qt::transparent);
    ui->calendarWidget->setDateTextFormat(QDate() , QTextCharFormat());
    format.setBackground(QColor(173, 216, 230));
    for (auto it = c_map.constBegin(); it != c_map.constEnd(); ++it) {
        if (it.value().length()>0)
            ui->calendarWidget->setDateTextFormat(it.key(), format);
    }
}


//  serialize

QDataStream& operator<<(QDataStream& out, const calendar_event& event)
{
    out << event.type;
    out << event.descr;
    out << event.time_start;
    out << event.time_end;
    out << event.repeat;
    return out;
}

QDataStream& operator>>(QDataStream& in, calendar_event& event)
{
    in >> event.type;
    in >> event.descr;
    in >> event.time_start;
    in >> event.time_end;
    in >> event.repeat;
    return in;
}

void Calendar::on_pushButton_edit_1_clicked()
{
    selected_button = 1;
    ui->pushButton_edit_1->setStyleSheet("background-color: lightblue;");
    edit_mode(true);
}


void Calendar::on_pushButton_edit_2_clicked()
{
    selected_button = 2;
    ui->pushButton_edit_2->setStyleSheet("background-color: lightblue;");
    edit_mode(true);
}


void Calendar::on_pushButton_edit_3_clicked()
{
    selected_button = 3;
    ui->pushButton_edit_3->setStyleSheet("background-color: lightblue;");
    edit_mode(true);
}

void Calendar::edit_mode(bool b){
    int index = current_page * 3 + (selected_button - 1);
    ui->pushButton_confirm_edit->setEnabled(b);
    b?
        ui->pushButton_confirm_edit->setStyleSheet
        ("background-color: lightblue;"):
        ui->pushButton_confirm_edit->setStyleSheet("");
    ui->calendarWidget->setEnabled(!b);
    ui->pushButton->setVisible(!b);
    ui->pushButton_edit_1->setEnabled(!b);
    ui->pushButton_edit_2->setEnabled(!b);
    ui->pushButton_edit_3->setEnabled(!b);
    ui->pushButton_delete_1->setEnabled(!b);
    ui->pushButton_delete_2->setEnabled(!b);
    ui->pushButton_delete_3->setEnabled(!b);
    ui->comboBox_ripetizione->setEnabled(!b);
    ui->pushButton_confirm_edit->setVisible(b);
    ui->pushButton_nextPage->setEnabled(!b);
    ui->pushButton_previousPage->setEnabled(!b);
    if (b) {
        ui->comboBox_ripetizione->setCurrentIndex(0);
        ui->timeEdit_start->setTime(c_map[current_date][index].time_start);
        ui->timeEdit_start->setTime(c_map[current_date][index].time_end);
    }else {
        ui->pushButton_edit_1->setStyleSheet("");
        ui->pushButton_edit_2->setStyleSheet("");
        ui->pushButton_edit_3->setStyleSheet("");
    }
}


void Calendar::on_pushButton_confirm_edit_clicked()
{
    int index = current_page * 3 + (selected_button - 1);
    calendar_event rmved = delete_entry(current_date, index);
    calendar_event tmp = create_event_from_ui();
    tmp.print();
    if (!valid_event(tmp))
        return;
    if (insert_event(tmp, tmp.repeat) == -1){ // if insert fails,
        insert_event(rmved, rmved.repeat);    // insert removed
    }
    edit_mode(false);
    this->update_ui();
}

void Calendar::clean(){
    for (auto it = c_map.begin(); it != c_map.end(); ){
        if (it.value().isEmpty())
            it = c_map.erase(it);
        else
            ++it;
    }
}

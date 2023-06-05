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
//#include <QList>
//#include <QLayout>


//std::map<QDate,std::vector<calendar_event>> cmap = new std::map<QDate,std::vector<calendar_event>>;
//QDate current_date = QDate(2023, 6, 1);


Calendar::Calendar(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calendar)
    , c_map() // read it from file
{
    ui->setupUi(this);
    current_date = QDate::currentDate();
    //current_date = QDate(2020, 6, 3);
    ui->calendarWidget->setSelectedDate(current_date);
    ui->calendarWidget->setMaximumDate(QDate(2023,12,31));

    QDate ev1 = QDate(2023, 6, 15);
    QDate ev2 = QDate(2023, 6, 30);
    c_map[ev1] = QVector<calendar_event>();
    c_map[ev2] = QVector<calendar_event>();
    qDebug() << "max date: " << ui->calendarWidget->maximumDate().toString();
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
    // pagina deve essere zero all'inizio
    current_page = 0;
    ui->pushButton_previousPage->setEnabled(false);
    auto it = this->c_map.find(current_date);
    if (it != this->c_map.end()) {
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
    this->go_to_page(0);
}


void Calendar::on_calendarWidget_selectionChanged(){
    qDebug() << "updating interface";
    this->update_ui();
}


void Calendar::on_pushButton_clicked(){
    // build item to store
    qDebug() << "tentativo aggiunta dati -> select and collect";
    qDebug() << ui->lineEdit->text();
    qDebug() << ui->comboBox_evento->currentText();
    qDebug() << ui->comboBox_ripetizione->currentText();
    qDebug() << ui->timeEdit_start->time().toString();
    qDebug() << ui->timeEdit_end->time().toString();
    // creo elemento temporaneo

    event_type tmp_type;
    QString tmp_descr;
    QTime tmp_time_start;
    QTime tmp_time_end;

    (ui->comboBox_evento->currentText() == "Evento")?
        tmp_type = EVENT: tmp_type = ACTIVITY;

    tmp_time_start = ui->timeEdit_start->time();
    tmp_time_end = ui->timeEdit_end->time();
    tmp_descr = ui->lineEdit->text();


    // gestisci ripetizione (non occorre controllare la chiave basta aggiungere)
    switch(ui->comboBox_ripetizione->currentIndex()){
    case 0: 	// "-"
        qDebug() << "evento singolo";
        break;
    case 1:		// "Mensile":
        qDebug() << "gestione mensile";
        break;
    case 2:		// "Annuale":
        qDebug() << "gestione annuale";
        break;
    default:
        qDebug() << "default in switch";

    }




    calendar_event tmp(tmp_type, tmp_descr, tmp_time_start, tmp_time_end);
    qDebug() << "printing tmp";
    tmp.print();

    // inner check for single event time coherence
    if (ui->timeEdit_start->time() >=
        ui->timeEdit_end->time()){
        qDebug() << "WARNING orario inserito non valido, vado lo stesso";
        return;
    }
    // check if date entry exists or create one
    auto it = this->c_map.find(current_date);
    if(it == this->c_map.end()){
        qDebug() << "creo una nuova pagina per " << current_date.toString() ;
        c_map[current_date] = QVector<calendar_event>();
    }
    // check overlapping
    for (int i = 0; i < c_map[current_date].size(); i++){
        if (checkEventsOverlap(tmp, c_map[current_date][i])){
            qDebug() << "event is overlapping";
        }
    }

    // se è montly o yearly controlla che non ci siano sovrapposizioni su tutte le chiavi della mappa

    // check on map

    c_map[current_date].push_back(tmp);
    //qSort(c_map[current_date]);
    std::sort(c_map[current_date].begin(),
              c_map[current_date].end());

    // azzerare page
    this->update_ui();
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
    return lhs.time_start < rhs.time_end;
}


// check for ovarlapping
bool checkEventsOverlap(const calendar_event& event1, const calendar_event& event2) {
    if (event1.time_end <= event2.time_start || event2.time_end <= event1.time_start) {
        return false;  // events do not overlap
    } else {
        return true; // events overlap
    }
}



void Calendar::on_pushButton_nextPage_clicked()
{

}


void Calendar::on_pushButton_previousPage_clicked()
{

}


void Calendar::go_to_page(int page){
    current_page = page;
    (current_page > 1)?
        ui->pushButton_previousPage->setEnabled(true):
        ui->pushButton_previousPage->setEnabled(false);

    int number_of_events  = c_map[current_date].size();
    int shown_events = 0;
    // start
    QVector<QHBoxLayout*> layouts = {
        ui->centralwidget->findChild<QHBoxLayout*>("horizontalLayout_data_1"),
        ui->centralwidget->findChild<QHBoxLayout*>("horizontalLayout_data_2"),
        ui->centralwidget->findChild<QHBoxLayout*>("horizontalLayout_data_3")
    };
    //QHBoxLayout* layout1 = ui->centralwidget->findChild<QHBoxLayout*>("horizontalLayout_data_1");
    //QHBoxLayout* layout2 = ui->centralwidget->findChild<QHBoxLayout*>("horizontalLayout_data_2");
    //QHBoxLayout* layout3 = ui->centralwidget->findChild<QHBoxLayout*>("horizontalLayout_data_3");
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
            qDebug()<< "fill event";
            for (int i = 0; i < lyt->count(); ++i) {
                QWidget* widget = lyt->itemAt(i)->widget();
                if (widget){
                    widget->setVisible(true);
                }
            }
        shown_events += 1;
        }
    }
}


    /*
    // Set the visibility of the contents within the layouts to false if they exist
    if (layout1 && ((current_page*3) + shown_events ) >= (number_of_events - 1)) {
        for (int i = 0; i < layout1->count(); ++i) {
            QWidget* widget = layout1->itemAt(i)->widget();
            if (widget)
                widget->setVisible(false);
        }
    }else{
        qDebug()<< "fill event 1";
        shown_events += 1;
    }

    if (layout2 && ((current_page*3) + shown_events ) >= (number_of_events - 1)) {
        for (int i = 0; i < layout2->count(); ++i) {
            QWidget* widget = layout2->itemAt(i)->widget();
            if (widget)
                widget->setVisible(false);
        }
    }else{
        qDebug()<< "fill event 2";
        shown_events += 1;
    }

    if (layout3 && ((current_page*3) + shown_events ) >= (number_of_events - 1)) {
        for (int i = 0; i < layout3->count(); ++i) {
            QWidget* widget = layout3->itemAt(i)->widget();
            if (widget)
                widget->setVisible(false);
        }
    }else{
        qDebug()<< "fill event 3";
        //shown_events += 1;
    }

}*/




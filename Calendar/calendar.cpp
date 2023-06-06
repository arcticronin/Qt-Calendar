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
//#include <QList>
//#include <QLayout>


//std::map<QDate,std::vector<calendar_event>> cmap = new std::map<QDate,std::vector<calendar_event>>;
//QDate current_date = QDate(2023, 6, 1);
//Calendar::resizeEvent(QResizeEvent *event){
//    ui->verticalLayout_main->setGeometry(rect());
//    Calendar::resizeEvent(event);
//}

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
    //qDebug() << "max date: " << ui->calendarWidget->maximumDate().toString();
    this->update_ui();

    //setLayout(ui->verticalLayout_main);

    //this->setLayout(ui->verticalLayout_main);
    //setCentralWidget(ui->centralwidget);
    //Set the main layout of the central widget to a vertical layout
    //QVBoxLayout* mainLayout = new QVBoxLayout(ui->centralwidget);
    //mainLayout->addWidget(ui->calendarWidget);
    //mainLayout->addWidget(ui->label);
    //mainLayout->addWidget(ui->label_vecSize);
    //mainLayout->addWidget(ui->pushButton_previousPage);
    //mainLayout->addWidget(ui->pushButton_nextPage);

    // Set the central widget of the main window to contain the main layout
    //QWidget* centralWidget = new QWidget(this);
    //centralWidget->setLayout(ui->verticalLayout_main);
    //this->setCentralWidget(centralWidget);
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
    event_repeat tmp_repeat;

    (ui->comboBox_evento->currentText() == "Evento")?
        tmp_type = EVENT: tmp_type = ACTIVITY;

    tmp_repeat = string_to_event_repeat
        (ui->comboBox_ripetizione->currentText());

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




    calendar_event tmp(tmp_type, tmp_descr, tmp_time_start, tmp_time_end,
                       tmp_repeat);
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

    // se è montly o yearly controlla che non ci siano sovrapposizioni
    // su tutte le chiavi della mappa

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
bool checkEventsOverlap(const calendar_event& event1,
                        const calendar_event& event2) {
    if (event1.time_end <= event2.time_start ||
        event2.time_end <= event1.time_start) {
        return false;  // events do not overlap
    } else {
        return true; // events overlap
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
    ui->label_page->setText(QString::number(page));
    (current_page > 1)?
        ui->pushButton_previousPage->setEnabled(true):
        ui->pushButton_previousPage->setEnabled(false);

    int number_of_events  = c_map[current_date].size();

    (number_of_events - (current_page * 3) > 0)?
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
            qDebug()<< "fill event";
            // fill labels
            descrizione_labels[shown_events]->setText(c_map[current_date]
                                               [(current_page*3)+shown_events]
                                                   .descr);
            time_start_labels[shown_events]->setText(c_map[current_date]
                                               [(current_page*3)+shown_events]
                                                   .time_start.toString());
            time_end_labels[shown_events]->setText(c_map[current_date]
                                               [(current_page*3)+shown_events]
                                                   .time_end.toString());
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
        return QString("Attività");
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
    default:
        return QString("-");
    }
}
event_repeat string_to_event_repeat(QString s){
    if (s == "Annuale")
        return MONTHLY;
    if (s == "Annuale")
        return YEARLY;
    return NOREPEAT;
}

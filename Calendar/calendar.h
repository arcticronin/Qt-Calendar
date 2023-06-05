#ifndef CALENDAR_H
#define CALENDAR_H

#include <QMainWindow>
#include <QDate>
#include <QString>
#include <QVector>
#include <QMap>
#include <QDebug>
//#include <QBoxLayout>

QT_BEGIN_NAMESPACE
namespace Ui { class Calendar; }
QT_END_NAMESPACE


enum event_type{
    ACTIVITY,	// 1
    EVENT		// 0
};



struct calendar_event{
    event_type type;
    QString descr;
    QTime time_start;
    QTime time_end;
    calendar_event(){}
    calendar_event(
            const event_type &t,
            const QString &de,
            const QTime &oi,
            const QTime &of):
        type(t),
        descr(de),
        time_start(oi),
        time_end(of)
        {}
    void print(){
        qDebug() << type;
        qDebug() << descr;
        qDebug() << time_start.toString();
        qDebug() << time_end.toString();
    }
};

bool operator<(const calendar_event& event1, const calendar_event& event2);
bool checkEventsOverlap(const calendar_event& event1, const calendar_event& event2);

class Calendar : public QMainWindow
{
    Q_OBJECT

public:
    Calendar(QWidget *parent = nullptr);
    ~Calendar();

private slots:
    void on_calendarWidget_selectionChanged();
    void on_pushButton_clicked();
    void on_comboBox_evento_currentIndexChanged(int index);

    void on_pushButton_nextPage_clicked();

    void on_pushButton_previousPage_clicked();

private:
    Ui::Calendar *ui;
    QMap<QDate,QVector<calendar_event>> c_map;
    //QMap<QDate,QVector<calendar_event>> c_map_weekly;
    //QMap<QDate,QVector<calendar_event>> c_map_monthly;
    //QMap<QDate,QVector<calendar_event>> c_map_yearly;

    QDate current_date;
    int current_page;
    void update_ui();
    void go_to_page(int page);
};


#endif // CALENDAR_H

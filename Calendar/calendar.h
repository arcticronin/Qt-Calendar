#ifndef CALENDAR_H
#define CALENDAR_H

#include <QMainWindow>
#include <QDate>
#include <QString>
#include <QVector>
#include <QMap>
#include <QDebug>
#include <QFile>
#include <QDataStream>

QT_BEGIN_NAMESPACE
namespace Ui { class Calendar; }
QT_END_NAMESPACE


enum event_type{
    ACTIVITY,
    EVENT
};


enum event_repeat{
    NOREPEAT,
    MONTHLY,
    WEEKLY,
    YEARLY
};

QString event_type_to_string(event_type e);
QString event_repeat_to_string(event_repeat e);
event_repeat string_to_event_repeat(QString s);

struct calendar_event{
    event_type type;
    QString descr;
    QTime time_start;
    QTime time_end;
    event_repeat repeat;
    calendar_event(){}
    calendar_event(
            const event_type &t,
            const QString &de,
            const QTime &oi,
            const QTime &of,
            const event_repeat &rep):
        type(t),
        descr(de),
        time_start(oi),
        time_end(of),
        repeat(rep)
        {}
    //calendar_event(const calendar_event& other)
    //                    : type(other.type),
    //                      descr(other.descr),
    //                      time_start(other.time_start),
    //                      time_end(other.time_end),
    //                      repeat(other.repeat)
    //    {}
    void print(){
        qDebug() << event_type_to_string(type);
        qDebug() << descr;
        qDebug() << time_start.toString();
        qDebug() << time_end.toString();
        qDebug() << event_repeat_to_string(repeat);
    }
};

bool valid_event(calendar_event c_e);
bool operator<(const calendar_event& event1, const calendar_event& event2);
bool checkEventsOverlap(const calendar_event& event1,
                        const calendar_event& event2);

QDataStream& operator<<(QDataStream& out, const calendar_event& event);
QDataStream& operator>>(QDataStream& in, calendar_event& event);


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
    void on_pushButton_delete_1_clicked();
    void on_pushButton_delete_2_clicked();
    void on_pushButton_delete_3_clicked();
    void on_pushButton_edit_1_clicked();
    void on_pushButton_edit_2_clicked();
    void on_pushButton_edit_3_clicked();
    void on_pushButton_confirm_edit_clicked();

private:
    Ui::Calendar *ui;
    QMap<QDate,QVector<calendar_event>> c_map;
    //QMap<QDate,QVector<calendar_event>> c_map_weekly;
    //QMap<QDate,QVector<calendar_event>> c_map_monthly;
    //QMap<QDate,QVector<calendar_event>> c_map_yearly;
    QDate current_date;
    int current_page;
    int selected_button; // used to edit events

    void update_ui();
    void go_to_page(int page);
    calendar_event delete_entry(QDate date, int index);
    calendar_event create_event_from_ui();
    int insert_event(calendar_event e, event_repeat rep);
    void setColors();
    void clean();
    void save();
    void load();
    void edit_mode(bool b);
};


#endif // CALENDAR_H

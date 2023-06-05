#include "calendar.h"

#include <QCalendarWidget>
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Calendar w;
    w.show();
    return a.exec();
}

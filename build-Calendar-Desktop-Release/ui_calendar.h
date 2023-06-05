/********************************************************************************
** Form generated from reading UI file 'calendar.ui'
**
** Created by: Qt User Interface Compiler version 5.15.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALENDAR_H
#define UI_CALENDAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Calendar
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QCalendarWidget *calendarWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_vecSize;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *pushButton_previousPage;
    QLabel *label_3;
    QPushButton *pushButton_nextPage;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_tipo_1;
    QLabel *label_descrizione_1;
    QLabel *label_start_1;
    QLabel *label_end_1;
    QLabel *label_ripetizione_1;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_edit_1;
    QPushButton *pushButton_delete_1;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_tipo_2;
    QLabel *label_descrizione_2;
    QLabel *label_start_2;
    QLabel *label_end_2;
    QLabel *label_ripetizione_2;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushButton_edit_2;
    QPushButton *pushButton_delete_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_tipo_3;
    QLabel *label_descrizione_3;
    QLabel *label_start_3;
    QLabel *label_end_3;
    QLabel *label_ripetizione_3;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *pushButton_edit_3;
    QPushButton *pushButton_delete_3;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBox_evento;
    QLineEdit *lineEdit;
    QTimeEdit *timeEdit_start;
    QTimeEdit *timeEdit_end;
    QComboBox *comboBox_ripetizione;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Calendar)
    {
        if (Calendar->objectName().isEmpty())
            Calendar->setObjectName(QString::fromUtf8("Calendar"));
        Calendar->resize(1199, 787);
        centralwidget = new QWidget(Calendar);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 559, 435));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        calendarWidget = new QCalendarWidget(verticalLayoutWidget);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));

        verticalLayout->addWidget(calendarWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setBold(true);
        label->setFont(font);

        horizontalLayout_2->addWidget(label);

        label_vecSize = new QLabel(verticalLayoutWidget);
        label_vecSize->setObjectName(QString::fromUtf8("label_vecSize"));

        horizontalLayout_2->addWidget(label_vecSize);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        pushButton_previousPage = new QPushButton(verticalLayoutWidget);
        pushButton_previousPage->setObjectName(QString::fromUtf8("pushButton_previousPage"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_previousPage->sizePolicy().hasHeightForWidth());
        pushButton_previousPage->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setBold(false);
        pushButton_previousPage->setFont(font1);

        horizontalLayout_9->addWidget(pushButton_previousPage);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setWordWrap(false);

        horizontalLayout_9->addWidget(label_3);

        pushButton_nextPage = new QPushButton(verticalLayoutWidget);
        pushButton_nextPage->setObjectName(QString::fromUtf8("pushButton_nextPage"));

        horizontalLayout_9->addWidget(pushButton_nextPage);


        horizontalLayout_2->addLayout(horizontalLayout_9);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_tipo_1 = new QLabel(verticalLayoutWidget);
        label_tipo_1->setObjectName(QString::fromUtf8("label_tipo_1"));

        horizontalLayout_4->addWidget(label_tipo_1);

        label_descrizione_1 = new QLabel(verticalLayoutWidget);
        label_descrizione_1->setObjectName(QString::fromUtf8("label_descrizione_1"));

        horizontalLayout_4->addWidget(label_descrizione_1);

        label_start_1 = new QLabel(verticalLayoutWidget);
        label_start_1->setObjectName(QString::fromUtf8("label_start_1"));

        horizontalLayout_4->addWidget(label_start_1);

        label_end_1 = new QLabel(verticalLayoutWidget);
        label_end_1->setObjectName(QString::fromUtf8("label_end_1"));

        horizontalLayout_4->addWidget(label_end_1);

        label_ripetizione_1 = new QLabel(verticalLayoutWidget);
        label_ripetizione_1->setObjectName(QString::fromUtf8("label_ripetizione_1"));

        horizontalLayout_4->addWidget(label_ripetizione_1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pushButton_edit_1 = new QPushButton(verticalLayoutWidget);
        pushButton_edit_1->setObjectName(QString::fromUtf8("pushButton_edit_1"));

        horizontalLayout_3->addWidget(pushButton_edit_1);

        pushButton_delete_1 = new QPushButton(verticalLayoutWidget);
        pushButton_delete_1->setObjectName(QString::fromUtf8("pushButton_delete_1"));

        horizontalLayout_3->addWidget(pushButton_delete_1);


        horizontalLayout_4->addLayout(horizontalLayout_3);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_tipo_2 = new QLabel(verticalLayoutWidget);
        label_tipo_2->setObjectName(QString::fromUtf8("label_tipo_2"));

        horizontalLayout_5->addWidget(label_tipo_2);

        label_descrizione_2 = new QLabel(verticalLayoutWidget);
        label_descrizione_2->setObjectName(QString::fromUtf8("label_descrizione_2"));

        horizontalLayout_5->addWidget(label_descrizione_2);

        label_start_2 = new QLabel(verticalLayoutWidget);
        label_start_2->setObjectName(QString::fromUtf8("label_start_2"));

        horizontalLayout_5->addWidget(label_start_2);

        label_end_2 = new QLabel(verticalLayoutWidget);
        label_end_2->setObjectName(QString::fromUtf8("label_end_2"));

        horizontalLayout_5->addWidget(label_end_2);

        label_ripetizione_2 = new QLabel(verticalLayoutWidget);
        label_ripetizione_2->setObjectName(QString::fromUtf8("label_ripetizione_2"));

        horizontalLayout_5->addWidget(label_ripetizione_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        pushButton_edit_2 = new QPushButton(verticalLayoutWidget);
        pushButton_edit_2->setObjectName(QString::fromUtf8("pushButton_edit_2"));

        horizontalLayout_6->addWidget(pushButton_edit_2);

        pushButton_delete_2 = new QPushButton(verticalLayoutWidget);
        pushButton_delete_2->setObjectName(QString::fromUtf8("pushButton_delete_2"));

        horizontalLayout_6->addWidget(pushButton_delete_2);


        horizontalLayout_5->addLayout(horizontalLayout_6);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_tipo_3 = new QLabel(verticalLayoutWidget);
        label_tipo_3->setObjectName(QString::fromUtf8("label_tipo_3"));

        horizontalLayout_7->addWidget(label_tipo_3);

        label_descrizione_3 = new QLabel(verticalLayoutWidget);
        label_descrizione_3->setObjectName(QString::fromUtf8("label_descrizione_3"));

        horizontalLayout_7->addWidget(label_descrizione_3);

        label_start_3 = new QLabel(verticalLayoutWidget);
        label_start_3->setObjectName(QString::fromUtf8("label_start_3"));

        horizontalLayout_7->addWidget(label_start_3);

        label_end_3 = new QLabel(verticalLayoutWidget);
        label_end_3->setObjectName(QString::fromUtf8("label_end_3"));

        horizontalLayout_7->addWidget(label_end_3);

        label_ripetizione_3 = new QLabel(verticalLayoutWidget);
        label_ripetizione_3->setObjectName(QString::fromUtf8("label_ripetizione_3"));

        horizontalLayout_7->addWidget(label_ripetizione_3);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        pushButton_edit_3 = new QPushButton(verticalLayoutWidget);
        pushButton_edit_3->setObjectName(QString::fromUtf8("pushButton_edit_3"));

        horizontalLayout_8->addWidget(pushButton_edit_3);

        pushButton_delete_3 = new QPushButton(verticalLayoutWidget);
        pushButton_delete_3->setObjectName(QString::fromUtf8("pushButton_delete_3"));

        horizontalLayout_8->addWidget(pushButton_delete_3);


        horizontalLayout_7->addLayout(horizontalLayout_8);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 5, -1, -1);
        comboBox_evento = new QComboBox(verticalLayoutWidget);
        comboBox_evento->addItem(QString());
        comboBox_evento->addItem(QString());
        comboBox_evento->setObjectName(QString::fromUtf8("comboBox_evento"));

        horizontalLayout->addWidget(comboBox_evento);

        lineEdit = new QLineEdit(verticalLayoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        timeEdit_start = new QTimeEdit(verticalLayoutWidget);
        timeEdit_start->setObjectName(QString::fromUtf8("timeEdit_start"));

        horizontalLayout->addWidget(timeEdit_start);

        timeEdit_end = new QTimeEdit(verticalLayoutWidget);
        timeEdit_end->setObjectName(QString::fromUtf8("timeEdit_end"));

        horizontalLayout->addWidget(timeEdit_end);

        comboBox_ripetizione = new QComboBox(verticalLayoutWidget);
        comboBox_ripetizione->addItem(QString());
        comboBox_ripetizione->addItem(QString());
        comboBox_ripetizione->addItem(QString());
        comboBox_ripetizione->setObjectName(QString::fromUtf8("comboBox_ripetizione"));

        horizontalLayout->addWidget(comboBox_ripetizione);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);

        Calendar->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Calendar);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1199, 26));
        Calendar->setMenuBar(menubar);
        statusbar = new QStatusBar(Calendar);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Calendar->setStatusBar(statusbar);

        retranslateUi(Calendar);

        QMetaObject::connectSlotsByName(Calendar);
    } // setupUi

    void retranslateUi(QMainWindow *Calendar)
    {
        Calendar->setWindowTitle(QCoreApplication::translate("Calendar", "Calendar", nullptr));
        label_2->setText(QCoreApplication::translate("Calendar", "Selected:", nullptr));
        label->setText(QCoreApplication::translate("Calendar", "TextLabel", nullptr));
        label_vecSize->setText(QCoreApplication::translate("Calendar", "TextLabel", nullptr));
        pushButton_previousPage->setText(QCoreApplication::translate("Calendar", "<", nullptr));
        label_3->setText(QCoreApplication::translate("Calendar", "0", nullptr));
        pushButton_nextPage->setText(QCoreApplication::translate("Calendar", ">", nullptr));
        label_tipo_1->setText(QCoreApplication::translate("Calendar", "TextLabel", nullptr));
        label_descrizione_1->setText(QCoreApplication::translate("Calendar", "TextLabel", nullptr));
        label_start_1->setText(QCoreApplication::translate("Calendar", "TextLabel", nullptr));
        label_end_1->setText(QCoreApplication::translate("Calendar", "TextLabel", nullptr));
        label_ripetizione_1->setText(QCoreApplication::translate("Calendar", "TextLabel", nullptr));
        pushButton_edit_1->setText(QCoreApplication::translate("Calendar", "Edit", nullptr));
        pushButton_delete_1->setText(QCoreApplication::translate("Calendar", "Delete", nullptr));
        label_tipo_2->setText(QCoreApplication::translate("Calendar", "TextLabel", nullptr));
        label_descrizione_2->setText(QCoreApplication::translate("Calendar", "TextLabel", nullptr));
        label_start_2->setText(QCoreApplication::translate("Calendar", "TextLabel", nullptr));
        label_end_2->setText(QCoreApplication::translate("Calendar", "TextLabel", nullptr));
        label_ripetizione_2->setText(QCoreApplication::translate("Calendar", "TextLabel", nullptr));
        pushButton_edit_2->setText(QCoreApplication::translate("Calendar", "Edit", nullptr));
        pushButton_delete_2->setText(QCoreApplication::translate("Calendar", "Delete", nullptr));
        label_tipo_3->setText(QCoreApplication::translate("Calendar", "TextLabel", nullptr));
        label_descrizione_3->setText(QCoreApplication::translate("Calendar", "TextLabel", nullptr));
        label_start_3->setText(QCoreApplication::translate("Calendar", "TextLabel", nullptr));
        label_end_3->setText(QCoreApplication::translate("Calendar", "TextLabel", nullptr));
        label_ripetizione_3->setText(QCoreApplication::translate("Calendar", "TextLabel", nullptr));
        pushButton_edit_3->setText(QCoreApplication::translate("Calendar", "Edit", nullptr));
        pushButton_delete_3->setText(QCoreApplication::translate("Calendar", "Delete", nullptr));
        comboBox_evento->setItemText(0, QCoreApplication::translate("Calendar", "Attivita", nullptr));
        comboBox_evento->setItemText(1, QCoreApplication::translate("Calendar", "Evento", nullptr));

        comboBox_ripetizione->setItemText(0, QCoreApplication::translate("Calendar", "-", nullptr));
        comboBox_ripetizione->setItemText(1, QCoreApplication::translate("Calendar", "Mensile", nullptr));
        comboBox_ripetizione->setItemText(2, QCoreApplication::translate("Calendar", "Annuale", nullptr));

        pushButton->setText(QCoreApplication::translate("Calendar", "Create", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Calendar: public Ui_Calendar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALENDAR_H

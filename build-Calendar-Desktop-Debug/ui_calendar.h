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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Calendar
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_main;
    QCalendarWidget *calendarWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_vecSize_2;
    QLabel *label_vecSize;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *pushButton_previousPage;
    QLabel *label_page;
    QPushButton *pushButton_nextPage;
    QHBoxLayout *horizontalLayout_data_1;
    QLabel *label_tipo_1;
    QLabel *label_descrizione_1;
    QLabel *label_start_1;
    QLabel *label_end_1;
    QLabel *label_ripetizione_1;
    QPushButton *pushButton_edit_1;
    QPushButton *pushButton_delete_1;
    QHBoxLayout *horizontalLayout_data_2;
    QLabel *label_tipo_2;
    QLabel *label_descrizione_2;
    QLabel *label_start_2;
    QLabel *label_end_2;
    QLabel *label_ripetizione_2;
    QPushButton *pushButton_edit_2;
    QPushButton *pushButton_delete_2;
    QHBoxLayout *horizontalLayout_data_3;
    QLabel *label_tipo_3;
    QLabel *label_descrizione_3;
    QLabel *label_start_3;
    QLabel *label_end_3;
    QLabel *label_ripetizione_3;
    QPushButton *pushButton_edit_3;
    QPushButton *pushButton_delete_3;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBox_evento;
    QLineEdit *lineEdit;
    QTimeEdit *timeEdit_start;
    QTimeEdit *timeEdit_end;
    QComboBox *comboBox_ripetizione;
    QPushButton *pushButton;
    QPushButton *pushButton_confirm_edit;
    QSpacerItem *verticalSpacer;

    void setupUi(QMainWindow *Calendar)
    {
        if (Calendar->objectName().isEmpty())
            Calendar->setObjectName(QString::fromUtf8("Calendar"));
        Calendar->resize(1199, 787);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Calendar->sizePolicy().hasHeightForWidth());
        Calendar->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(Calendar);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy1);
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(200, 50, 667, 441));
        verticalLayout_main = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_main->setObjectName(QString::fromUtf8("verticalLayout_main"));
        verticalLayout_main->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_main->setContentsMargins(0, 0, 0, 0);
        calendarWidget = new QCalendarWidget(verticalLayoutWidget);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        sizePolicy1.setHeightForWidth(calendarWidget->sizePolicy().hasHeightForWidth());
        calendarWidget->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(12);
        calendarWidget->setFont(font);

        verticalLayout_main->addWidget(calendarWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font1;
        font1.setPointSize(11);
        label_2->setFont(font1);

        horizontalLayout_2->addWidget(label_2);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(true);
        label->setFont(font2);

        horizontalLayout_2->addWidget(label);

        label_vecSize_2 = new QLabel(verticalLayoutWidget);
        label_vecSize_2->setObjectName(QString::fromUtf8("label_vecSize_2"));
        label_vecSize_2->setFont(font1);

        horizontalLayout_2->addWidget(label_vecSize_2);

        label_vecSize = new QLabel(verticalLayoutWidget);
        label_vecSize->setObjectName(QString::fromUtf8("label_vecSize"));
        label_vecSize->setFont(font1);

        horizontalLayout_2->addWidget(label_vecSize);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        pushButton_previousPage = new QPushButton(verticalLayoutWidget);
        pushButton_previousPage->setObjectName(QString::fromUtf8("pushButton_previousPage"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pushButton_previousPage->sizePolicy().hasHeightForWidth());
        pushButton_previousPage->setSizePolicy(sizePolicy3);
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(false);
        pushButton_previousPage->setFont(font3);

        horizontalLayout_9->addWidget(pushButton_previousPage);

        label_page = new QLabel(verticalLayoutWidget);
        label_page->setObjectName(QString::fromUtf8("label_page"));
        label_page->setFont(font);
        label_page->setWordWrap(false);

        horizontalLayout_9->addWidget(label_page);

        pushButton_nextPage = new QPushButton(verticalLayoutWidget);
        pushButton_nextPage->setObjectName(QString::fromUtf8("pushButton_nextPage"));
        pushButton_nextPage->setFont(font);

        horizontalLayout_9->addWidget(pushButton_nextPage);


        horizontalLayout_2->addLayout(horizontalLayout_9);


        verticalLayout_main->addLayout(horizontalLayout_2);

        horizontalLayout_data_1 = new QHBoxLayout();
        horizontalLayout_data_1->setObjectName(QString::fromUtf8("horizontalLayout_data_1"));
        label_tipo_1 = new QLabel(verticalLayoutWidget);
        label_tipo_1->setObjectName(QString::fromUtf8("label_tipo_1"));
        label_tipo_1->setFont(font1);

        horizontalLayout_data_1->addWidget(label_tipo_1);

        label_descrizione_1 = new QLabel(verticalLayoutWidget);
        label_descrizione_1->setObjectName(QString::fromUtf8("label_descrizione_1"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_descrizione_1->sizePolicy().hasHeightForWidth());
        label_descrizione_1->setSizePolicy(sizePolicy4);
        label_descrizione_1->setFont(font1);

        horizontalLayout_data_1->addWidget(label_descrizione_1);

        label_start_1 = new QLabel(verticalLayoutWidget);
        label_start_1->setObjectName(QString::fromUtf8("label_start_1"));
        label_start_1->setFont(font1);

        horizontalLayout_data_1->addWidget(label_start_1);

        label_end_1 = new QLabel(verticalLayoutWidget);
        label_end_1->setObjectName(QString::fromUtf8("label_end_1"));
        label_end_1->setFont(font1);

        horizontalLayout_data_1->addWidget(label_end_1);

        label_ripetizione_1 = new QLabel(verticalLayoutWidget);
        label_ripetizione_1->setObjectName(QString::fromUtf8("label_ripetizione_1"));
        label_ripetizione_1->setFont(font1);

        horizontalLayout_data_1->addWidget(label_ripetizione_1);

        pushButton_edit_1 = new QPushButton(verticalLayoutWidget);
        pushButton_edit_1->setObjectName(QString::fromUtf8("pushButton_edit_1"));
        pushButton_edit_1->setFont(font1);

        horizontalLayout_data_1->addWidget(pushButton_edit_1);

        pushButton_delete_1 = new QPushButton(verticalLayoutWidget);
        pushButton_delete_1->setObjectName(QString::fromUtf8("pushButton_delete_1"));
        pushButton_delete_1->setFont(font1);

        horizontalLayout_data_1->addWidget(pushButton_delete_1);


        verticalLayout_main->addLayout(horizontalLayout_data_1);

        horizontalLayout_data_2 = new QHBoxLayout();
        horizontalLayout_data_2->setObjectName(QString::fromUtf8("horizontalLayout_data_2"));
        label_tipo_2 = new QLabel(verticalLayoutWidget);
        label_tipo_2->setObjectName(QString::fromUtf8("label_tipo_2"));
        label_tipo_2->setFont(font1);

        horizontalLayout_data_2->addWidget(label_tipo_2);

        label_descrizione_2 = new QLabel(verticalLayoutWidget);
        label_descrizione_2->setObjectName(QString::fromUtf8("label_descrizione_2"));
        label_descrizione_2->setFont(font1);

        horizontalLayout_data_2->addWidget(label_descrizione_2);

        label_start_2 = new QLabel(verticalLayoutWidget);
        label_start_2->setObjectName(QString::fromUtf8("label_start_2"));
        label_start_2->setFont(font1);

        horizontalLayout_data_2->addWidget(label_start_2);

        label_end_2 = new QLabel(verticalLayoutWidget);
        label_end_2->setObjectName(QString::fromUtf8("label_end_2"));
        label_end_2->setFont(font1);

        horizontalLayout_data_2->addWidget(label_end_2);

        label_ripetizione_2 = new QLabel(verticalLayoutWidget);
        label_ripetizione_2->setObjectName(QString::fromUtf8("label_ripetizione_2"));
        label_ripetizione_2->setFont(font1);

        horizontalLayout_data_2->addWidget(label_ripetizione_2);

        pushButton_edit_2 = new QPushButton(verticalLayoutWidget);
        pushButton_edit_2->setObjectName(QString::fromUtf8("pushButton_edit_2"));
        pushButton_edit_2->setFont(font1);

        horizontalLayout_data_2->addWidget(pushButton_edit_2);

        pushButton_delete_2 = new QPushButton(verticalLayoutWidget);
        pushButton_delete_2->setObjectName(QString::fromUtf8("pushButton_delete_2"));
        pushButton_delete_2->setFont(font1);

        horizontalLayout_data_2->addWidget(pushButton_delete_2);


        verticalLayout_main->addLayout(horizontalLayout_data_2);

        horizontalLayout_data_3 = new QHBoxLayout();
        horizontalLayout_data_3->setObjectName(QString::fromUtf8("horizontalLayout_data_3"));
        label_tipo_3 = new QLabel(verticalLayoutWidget);
        label_tipo_3->setObjectName(QString::fromUtf8("label_tipo_3"));
        label_tipo_3->setFont(font1);

        horizontalLayout_data_3->addWidget(label_tipo_3);

        label_descrizione_3 = new QLabel(verticalLayoutWidget);
        label_descrizione_3->setObjectName(QString::fromUtf8("label_descrizione_3"));
        label_descrizione_3->setFont(font1);

        horizontalLayout_data_3->addWidget(label_descrizione_3);

        label_start_3 = new QLabel(verticalLayoutWidget);
        label_start_3->setObjectName(QString::fromUtf8("label_start_3"));
        label_start_3->setFont(font1);

        horizontalLayout_data_3->addWidget(label_start_3);

        label_end_3 = new QLabel(verticalLayoutWidget);
        label_end_3->setObjectName(QString::fromUtf8("label_end_3"));
        label_end_3->setFont(font1);

        horizontalLayout_data_3->addWidget(label_end_3);

        label_ripetizione_3 = new QLabel(verticalLayoutWidget);
        label_ripetizione_3->setObjectName(QString::fromUtf8("label_ripetizione_3"));
        label_ripetizione_3->setFont(font1);

        horizontalLayout_data_3->addWidget(label_ripetizione_3);

        pushButton_edit_3 = new QPushButton(verticalLayoutWidget);
        pushButton_edit_3->setObjectName(QString::fromUtf8("pushButton_edit_3"));
        pushButton_edit_3->setFont(font1);

        horizontalLayout_data_3->addWidget(pushButton_edit_3);

        pushButton_delete_3 = new QPushButton(verticalLayoutWidget);
        pushButton_delete_3->setObjectName(QString::fromUtf8("pushButton_delete_3"));
        pushButton_delete_3->setFont(font1);

        horizontalLayout_data_3->addWidget(pushButton_delete_3);


        verticalLayout_main->addLayout(horizontalLayout_data_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 5, -1, -1);
        comboBox_evento = new QComboBox(verticalLayoutWidget);
        comboBox_evento->addItem(QString());
        comboBox_evento->addItem(QString());
        comboBox_evento->setObjectName(QString::fromUtf8("comboBox_evento"));
        comboBox_evento->setFont(font);

        horizontalLayout->addWidget(comboBox_evento);

        lineEdit = new QLineEdit(verticalLayoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMinimumSize(QSize(100, 0));
        lineEdit->setFont(font);

        horizontalLayout->addWidget(lineEdit);

        timeEdit_start = new QTimeEdit(verticalLayoutWidget);
        timeEdit_start->setObjectName(QString::fromUtf8("timeEdit_start"));
        timeEdit_start->setFont(font);

        horizontalLayout->addWidget(timeEdit_start);

        timeEdit_end = new QTimeEdit(verticalLayoutWidget);
        timeEdit_end->setObjectName(QString::fromUtf8("timeEdit_end"));
        timeEdit_end->setFont(font);

        horizontalLayout->addWidget(timeEdit_end);

        comboBox_ripetizione = new QComboBox(verticalLayoutWidget);
        comboBox_ripetizione->addItem(QString());
        comboBox_ripetizione->addItem(QString());
        comboBox_ripetizione->addItem(QString());
        comboBox_ripetizione->addItem(QString());
        comboBox_ripetizione->setObjectName(QString::fromUtf8("comboBox_ripetizione"));
        comboBox_ripetizione->setFont(font);

        horizontalLayout->addWidget(comboBox_ripetizione);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setFont(font);

        horizontalLayout->addWidget(pushButton);

        pushButton_confirm_edit = new QPushButton(verticalLayoutWidget);
        pushButton_confirm_edit->setObjectName(QString::fromUtf8("pushButton_confirm_edit"));
        pushButton_confirm_edit->setFont(font);

        horizontalLayout->addWidget(pushButton_confirm_edit);


        verticalLayout_main->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_main->addItem(verticalSpacer);

        Calendar->setCentralWidget(centralwidget);

        retranslateUi(Calendar);

        QMetaObject::connectSlotsByName(Calendar);
    } // setupUi

    void retranslateUi(QMainWindow *Calendar)
    {
        Calendar->setWindowTitle(QCoreApplication::translate("Calendar", "Calendar", nullptr));
        label_2->setText(QCoreApplication::translate("Calendar", "Selected:", nullptr));
        label->setText(QCoreApplication::translate("Calendar", "TextLabel", nullptr));
        label_vecSize_2->setText(QCoreApplication::translate("Calendar", "events today:", nullptr));
        label_vecSize->setText(QCoreApplication::translate("Calendar", "TextLabel", nullptr));
        pushButton_previousPage->setText(QCoreApplication::translate("Calendar", "<", nullptr));
        label_page->setText(QCoreApplication::translate("Calendar", "0", nullptr));
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
        comboBox_ripetizione->setItemText(1, QCoreApplication::translate("Calendar", "Settimanale", nullptr));
        comboBox_ripetizione->setItemText(2, QCoreApplication::translate("Calendar", "Mensile", nullptr));
        comboBox_ripetizione->setItemText(3, QCoreApplication::translate("Calendar", "Annuale", nullptr));

        pushButton->setText(QCoreApplication::translate("Calendar", "Create", nullptr));
        pushButton_confirm_edit->setText(QCoreApplication::translate("Calendar", "Confirm", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Calendar: public Ui_Calendar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALENDAR_H

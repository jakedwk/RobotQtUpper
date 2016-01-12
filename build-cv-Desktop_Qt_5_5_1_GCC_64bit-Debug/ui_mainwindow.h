/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *but_start;
    QPushButton *but_stop;
    QLabel *txt_lab1;
    QPushButton *but_con;
    QLineEdit *lineEdit_ip;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *lab_dir;
    QLabel *lab_width;
    QLabel *lab_height;
    QLabel *lab_x;
    QLabel *lab_y;
    QLabel *lab_z;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QFrame *line;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(840, 550);
        MainWindow->setMinimumSize(QSize(840, 550));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        but_start = new QPushButton(centralWidget);
        but_start->setObjectName(QStringLiteral("but_start"));
        but_start->setGeometry(QRect(370, 480, 85, 27));
        but_stop = new QPushButton(centralWidget);
        but_stop->setObjectName(QStringLiteral("but_stop"));
        but_stop->setGeometry(QRect(470, 480, 85, 27));
        txt_lab1 = new QLabel(centralWidget);
        txt_lab1->setObjectName(QStringLiteral("txt_lab1"));
        txt_lab1->setGeometry(QRect(570, 480, 171, 21));
        but_con = new QPushButton(centralWidget);
        but_con->setObjectName(QStringLiteral("but_con"));
        but_con->setGeometry(QRect(280, 480, 71, 27));
        lineEdit_ip = new QLineEdit(centralWidget);
        lineEdit_ip->setObjectName(QStringLiteral("lineEdit_ip"));
        lineEdit_ip->setGeometry(QRect(150, 480, 113, 25));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(760, 70, 51, 241));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        lab_dir = new QLabel(layoutWidget);
        lab_dir->setObjectName(QStringLiteral("lab_dir"));

        verticalLayout_2->addWidget(lab_dir);

        lab_width = new QLabel(layoutWidget);
        lab_width->setObjectName(QStringLiteral("lab_width"));

        verticalLayout_2->addWidget(lab_width);

        lab_height = new QLabel(layoutWidget);
        lab_height->setObjectName(QStringLiteral("lab_height"));

        verticalLayout_2->addWidget(lab_height);

        lab_x = new QLabel(layoutWidget);
        lab_x->setObjectName(QStringLiteral("lab_x"));

        verticalLayout_2->addWidget(lab_x);

        lab_y = new QLabel(layoutWidget);
        lab_y->setObjectName(QStringLiteral("lab_y"));

        verticalLayout_2->addWidget(lab_y);

        lab_z = new QLabel(layoutWidget);
        lab_z->setObjectName(QStringLiteral("lab_z"));

        verticalLayout_2->addWidget(lab_z);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(680, 70, 51, 241));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget1);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout->addWidget(label_5);

        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout->addWidget(label_6);

        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(590, 220, 3, 61));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        but_start->setText(QApplication::translate("MainWindow", "start", 0));
        but_stop->setText(QApplication::translate("MainWindow", "stop", 0));
        txt_lab1->setText(QApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", 0));
        but_con->setText(QApplication::translate("MainWindow", "connect", 0));
        lab_dir->setText(QApplication::translate("MainWindow", "NA", 0));
        lab_width->setText(QApplication::translate("MainWindow", "NA", 0));
        lab_height->setText(QApplication::translate("MainWindow", "NA", 0));
        lab_x->setText(QApplication::translate("MainWindow", "NA", 0));
        lab_y->setText(QApplication::translate("MainWindow", "NA", 0));
        lab_z->setText(QApplication::translate("MainWindow", "NA", 0));
        label->setText(QApplication::translate("MainWindow", "dir", 0));
        label_2->setText(QApplication::translate("MainWindow", "width:", 0));
        label_3->setText(QApplication::translate("MainWindow", "height:", 0));
        label_4->setText(QApplication::translate("MainWindow", "x:", 0));
        label_5->setText(QApplication::translate("MainWindow", "y:", 0));
        label_6->setText(QApplication::translate("MainWindow", "z:", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

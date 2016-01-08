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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
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
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(640, 550);
        MainWindow->setMinimumSize(QSize(640, 550));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        but_start = new QPushButton(centralWidget);
        but_start->setObjectName(QStringLiteral("but_start"));
        but_start->setGeometry(QRect(250, 480, 85, 27));
        but_stop = new QPushButton(centralWidget);
        but_stop->setObjectName(QStringLiteral("but_stop"));
        but_stop->setGeometry(QRect(350, 480, 85, 27));
        txt_lab1 = new QLabel(centralWidget);
        txt_lab1->setObjectName(QStringLiteral("txt_lab1"));
        txt_lab1->setGeometry(QRect(450, 480, 171, 21));
        but_con = new QPushButton(centralWidget);
        but_con->setObjectName(QStringLiteral("but_con"));
        but_con->setGeometry(QRect(160, 480, 71, 27));
        lineEdit_ip = new QLineEdit(centralWidget);
        lineEdit_ip->setObjectName(QStringLiteral("lineEdit_ip"));
        lineEdit_ip->setGeometry(QRect(30, 480, 113, 25));
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
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

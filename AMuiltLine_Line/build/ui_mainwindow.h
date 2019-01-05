/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QChartView>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QPushButton *btnTimer;
    QChartView *widget;
    QGroupBox *groupBox_2;
    QListWidget *lstLineTemp;
    QListWidget *lstLineShow;
    QPushButton *btnDelLine;
    QPushButton *btnAddLine;
    QLabel *label;
    QLabel *label_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(878, 534);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 261, 201));
        btnTimer = new QPushButton(groupBox);
        btnTimer->setObjectName(QStringLiteral("btnTimer"));
        btnTimer->setGeometry(QRect(90, 90, 61, 25));
        widget = new QChartView(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(280, 10, 581, 451));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 210, 251, 251));
        lstLineTemp = new QListWidget(groupBox_2);
        lstLineTemp->setObjectName(QStringLiteral("lstLineTemp"));
        lstLineTemp->setGeometry(QRect(0, 30, 91, 181));
        lstLineShow = new QListWidget(groupBox_2);
        lstLineShow->setObjectName(QStringLiteral("lstLineShow"));
        lstLineShow->setGeometry(QRect(120, 30, 121, 181));
        btnDelLine = new QPushButton(groupBox_2);
        btnDelLine->setObjectName(QStringLiteral("btnDelLine"));
        btnDelLine->setGeometry(QRect(120, 220, 89, 25));
        btnAddLine = new QPushButton(groupBox_2);
        btnAddLine->setObjectName(QStringLiteral("btnAddLine"));
        btnAddLine->setGeometry(QRect(0, 220, 89, 25));
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(99, 70, 21, 17));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(99, 120, 21, 17));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 878, 22));
        MainWindow->setMenuBar(menuBar);
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "ChartLine", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "\350\256\276\347\275\256", nullptr));
        btnTimer->setText(QApplication::translate("MainWindow", "\345\220\257\345\212\250", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\346\233\262\347\272\277", nullptr));
        btnDelLine->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244", nullptr));
        btnAddLine->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240", nullptr));
        label->setText(QApplication::translate("MainWindow", ">>", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "<<", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

/**
 * QT 动态曲线 v0.1  by YcSmile
 * https://github.com/YcSmile
 * 
 * 
*/


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

// ========================== 绘图曲线 ===========================
#include <QtCharts>
#include <QChart>
#include <QLineSeries>
#include <QSplineSeries>
#include <QMutex>

using namespace QtCharts;

// ========================== 绘图曲线 ===========================

#include <QSpinBox>
#include <QString>
#include <QList>
#include <QMap>

// ==============================================================
#include <vector>
#include <map>
#include <list>
#include <iostream>

// ==============================================================

// ==============================================================

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


    void UiInit();


    // 绘图曲线
    // =================== 坐标轴设定 =====================
    const int xMaxNum = 20;     // 最多200个点
    const double axisX_dx = 200.0/ (xMaxNum - 1);// (xMaxNum - 1.0)/xMaxNum;

    QChart *mychart;                // 图形
    QValueAxis *axisX;
    QValueAxis *axisY;
    QMutex chartLineMutex;
    QMap<QString,QMap<QSplineSeries*,QList<double>*> > chartLines;
    QTimer *chartTimer;
    QTimer *numTimer;
    void ChartViewInit();
    void ChartAddQLine(QString lineName);
    void QLineAddPoint(QString lineName,double dPoint);
    void ChartUpdateQLine();
    void ChartRemoveQLine(QString lineName);
    void ChartVisibleLine(QString lineName,bool visible);


private slots:

    void on_btnTimer_clicked();

    void on_btnAddLine_clicked();

    void on_btnDelLine_clicked();

    // 曲线可视化
    void SLOT_ListLineShowItemChang(QListWidgetItem* item);

    void SLOT_TimeoutChartUpdate();
    // 
    void SLOT_LinePointAdd(QString linename,double point);

    // 
    void SLOT_NumAppend();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

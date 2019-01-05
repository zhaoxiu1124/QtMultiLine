#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ChartViewInit();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::UiInit(){
    //
    


}

#pragma region ChartZoon



/**
 * 初始化曲线显示
 * 
*/
void MainWindow::ChartViewInit(){

    // 先添加曲线
    // 初始化图形
    mychart = new QChart();
    mychart->setTitle("实时动态曲线");

    axisX = new QValueAxis;
    axisX->setRange(0,200.0);
    axisX->setLabelFormat("%g");
    // axisX->setTitleText("axisX");
    // axisX->setTickCount(20); //主分隔个数：0到10分成20个单位
    axisX->setMinorTickCount(4); //每个单位之间绘制了多少虚网线

    axisY = new QValueAxis;
    axisY->setRange(-500,500);
    // axisY->setTitleText("axisY");

    this->ui->widget->setChart(mychart);

    // 添加曲线    
    this->ui->lstLineTemp->addItem("sin");
    this->ui->lstLineTemp->addItem("cos");
    this->ui->lstLineTemp->addItem("random");
    // this->ui->lstLineTemp->addItem("M4Spd");
    // this->ui->lstLineTemp->addItem("M1Out");
    // this->ui->lstLineTemp->addItem("M2Out");
    // this->ui->lstLineTemp->addItem("M3Out");
    // this->ui->lstLineTemp->addItem("M4Out");

    // 可视化
    connect(this->ui->lstLineShow,SIGNAL(itemChanged(QListWidgetItem*)),this,SLOT(SLOT_ListLineShowItemChang(QListWidgetItem*)));
    
    // 定时更新chart
    chartTimer = new QTimer(this);
    connect(chartTimer, SIGNAL(timeout()), this, SLOT(SLOT_TimeoutChartUpdate()));
    chartTimer->start(100); // 100ms更新
}

/**
 * 添加值
 * 
*/
void MainWindow::QLineAddPoint(QString lineName,double dPoint){

    
    if(!chartLines.contains(lineName)){
        return;
        // ChartAddQLine(lineName);
    }
    chartLineMutex.lock();
    // 添加节点值
    QMap<QLineSeries*,QList<double>*> line = chartLines[lineName];
    // 添加值
    QList<double> *lList = line.begin().value();
    *lList << dPoint;    // 添加点
    if(lList->size()>xMaxNum){
        lList->removeFirst();
    }
    chartLineMutex.unlock();
}
/**
 * 添加新的曲线
 * 
*/
void MainWindow::ChartAddQLine(QString lineName){

    if(!chartLines.contains(lineName)){
        chartLineMutex.lock();
        // 添加新的曲线
        QMap<QLineSeries*,QList<double>*> newLine;
        QLineSeries *line = new QLineSeries();

        line->setName(lineName);

        // 添加到
        mychart->addSeries(line);
        mychart->setAxisX(axisX, line);
        mychart->setAxisY(axisY, line);

        
        QList<double> *list = new QList<double>();
        newLine.insert(line,list);
        chartLines.insert(lineName,newLine);
        chartLineMutex.unlock();
    }
}
/**
 * 删除曲线
 *  # 
 * TODO 
*/
void MainWindow::ChartRemoveQLine(QString lineName){

    if(!chartLines.contains(lineName)){
        return;
    }
    chartLineMutex.lock();

    // 添加节点值
    QMap<QString,QMap<QLineSeries*,QList<double>*> >::Iterator it = chartLines.find(lineName);

    QMap<QLineSeries*,QList<double>*> itval = it.value();
    // 添加值
    QLineSeries *line = itval.begin().key();

    QList<double> *lList = itval.begin().value();

    mychart->removeSeries(line);
    // 释放
    line->clear();
    lList->clear();
    chartLines.erase(it);

    delete line;
    delete lList;

    chartLineMutex.unlock();
}

/**
 * 可视化设置
 * 
*/

void MainWindow::ChartVisibleLine(QString lineName,bool visible){
    if(!chartLines.contains(lineName)){
        return;
        
    }

    QMap<QLineSeries*,QList<double>*> lIt = chartLines[lineName];
    QLineSeries *line = lIt.begin().key();
    line->setVisible(visible);

}
/**
 * 更新折线
 * 
*/
void MainWindow::ChartUpdateQLine(){
    
    if(chartLines.size() < 1){
        return;
    }
    chartLineMutex.lock();
    QMap<QString,QMap<QLineSeries*,QList<double>* > >::Iterator it;    
    for(it = chartLines.begin();it != chartLines.end();it++){
        QString lineName = it.key();
        QLineSeries *line = it.value().begin().key();
        QList<double> *list = it.value().begin().value();

        line->clear();
        int less = xMaxNum - list->size();
        for (int r_ = 0; r_ < list->size(); r_++)
        {
            line->append(less *axisX_dx  + r_ * axisX_dx, list->at(r_));
        }
    }
    chartLineMutex.unlock();
}

void MainWindow::SLOT_TimeoutChartUpdate()
{
    if(chartLines.size() < 1){
        return;
    }
    chartLineMutex.lock();
    QMap<QString,QMap<QLineSeries*,QList<double>* > >::Iterator it;    
    for(it = chartLines.begin();it != chartLines.end();it++){
        QString lineName = it.key();
        QLineSeries *line = it.value().begin().key();
        QList<double> *list = it.value().begin().value();

        line->clear();
        int less = xMaxNum - list->size();
        for (int r_ = 0; r_ < list->size(); r_++)
        {
            line->append(less *axisX_dx  + r_ * axisX_dx, list->at(r_));
        }
    }
    chartLineMutex.unlock();
}

void MainWindow::SLOT_LinePointAdd(QString linename,double point)
{
    QLineAddPoint(linename, point);
}

#pragma endregion Chart

void MainWindow::on_btnTimer_clicked()
{
    // 
    

    numTimer = new QTimer();
    connect(numTimer, SIGNAL(timeout()), this, SLOT(SLOT_NumAppend()));
    numTimer->start(10); // 100ms更新
    
}

void MainWindow::on_btnAddLine_clicked()
{
    // 添加曲线
    // 选择
    
    QListWidgetItem *tIt = this->ui->lstLineTemp->currentItem();
    if(!tIt){
        return;
    }
    QString itmS =tIt->text();
    this->ui->lstLineTemp->removeItemWidget(tIt);
    delete tIt;
    

    QListWidgetItem *sIt = new QListWidgetItem();
    sIt->setFlags(sIt->flags()|Qt::ItemIsUserCheckable);
    sIt->setText(itmS);
    sIt->setCheckState(Qt::Checked); // AND initialize check state
    this->ui->lstLineShow->addItem(sIt);

    // 添加曲线
    ChartAddQLine(itmS);


}

void MainWindow::on_btnDelLine_clicked()
{
    QListWidgetItem *sIt = this->ui->lstLineShow->currentItem();
    if(!sIt){
        return;
    }
    QString itmS =sIt->text();
    this->ui->lstLineShow->removeItemWidget(sIt);
    delete sIt;

    this->ui->lstLineTemp->addItem(itmS);

    // 删除曲线
    ChartRemoveQLine(itmS);
}
void  MainWindow::SLOT_NumAppend()
{
    static double a = 0.0;
    QLineAddPoint("sin", 200.0 * sin(a+=0.02));
    QLineAddPoint("cos", 200.0 * cos(a+=0.02));
    QLineAddPoint("random", qrand() % (1000 + 1) -500);
}

void MainWindow::SLOT_ListLineShowItemChang(QListWidgetItem* item){
    ChartVisibleLine(item->text(),item->checkState()==Qt::Checked);
}

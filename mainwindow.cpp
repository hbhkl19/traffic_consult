#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include"findinfo.h"
#include"addflight.h"
#include"deleteflight.h"
#include"changeflight.h"
#include"addcity.h"
#include"deletecity.h"
#include"changecity.h"
#include"addtrain.h"
#include"deletetrain.h"
#include"changetrain.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->exitButton,&QPushButton::clicked,this,&MainWindow::on_exitButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//界面跳转函数;
void MainWindow::on_exitButton_clicked()
{
    this->close();
}

void MainWindow::on_findInfo_clicked()
{
    findInfo *configWindow=new findInfo;
    this->close();
    configWindow->show();
}

void MainWindow::on_addFlights_clicked()
{
    addFlight *configWindow=new addFlight;
    this->close();
    configWindow->show();
}

void MainWindow::on_deleteFlight_clicked()
{
    deleteFlight *configWindow=new deleteFlight;
    this->close();
    configWindow->show();
}

void MainWindow::on_changeFlight_clicked()
{
    changeFlight *configWindow=new changeFlight;
    this->close();
    configWindow->show();
}

void findInfo::on_returnButton_clicked()
{
    MainWindow* configWindow=new MainWindow;
    this->close();
    configWindow->show();
}

void addFlight::on_returnButton_clicked()
{
    MainWindow* configWindow=new MainWindow;
    this->close();
    configWindow->show();
}

void deleteFlight::on_returnButton_clicked()
{
    MainWindow *configWindow=new MainWindow;
    this->close();
    configWindow->show();
}

void changeFlight::on_returnButton_clicked()
{
    MainWindow *configWindow=new MainWindow;
    this->close();
    configWindow->show();
}
void addCity::on_returnButton_clicked()
{
    MainWindow *configWindow=new MainWindow;
    this->close();
    configWindow->show();
}

void MainWindow::on_addCity_clicked()
{
    addCity* configWindow=new addCity;
    this->close();
    configWindow->show();
}

void MainWindow::on_deleteCity_clicked()
{
    deleteCity* configWindow=new deleteCity;
    this->close();
    configWindow->show();
}

void MainWindow::on_changeCity_clicked()
{
    changeCity* configWindow=new changeCity;
    this->close();
    configWindow->show();
}

void MainWindow::on_addTrainTrip_clicked()
{
    addTrain* configWindow=new addTrain;
    this->close();
    configWindow->show();
}


void MainWindow::on_deleteTrainTrip_clicked()
{
    deleteTrain* configWindow=new deleteTrain;
    this->close();
    configWindow->show();
}


void MainWindow::on_changeTrainTrip_clicked()
{
    changeTrain* configWindow=new changeTrain;
    this->close();
    configWindow->show();
}

void changeCity::on_returnButton_clicked()
{
    MainWindow *configWindow=new MainWindow;
    this->close();
    configWindow->show();
}

void deleteCity::on_returnButton_clicked()
{
    MainWindow *configWindow=new MainWindow;
    this->close();
    configWindow->show();
}

void deleteTrain::on_returnButton_clicked()
{
    MainWindow *configWindow=new MainWindow;
    this->close();
    configWindow->show();
}

void addTrain::on_returnButton_clicked()
{
    MainWindow *configWindow=new MainWindow;
    this->close();
    configWindow->show();
}

void changeTrain::on_returnButton_clicked()
{
    MainWindow *configWindow=new MainWindow;
    this->close();
    configWindow->show();
}

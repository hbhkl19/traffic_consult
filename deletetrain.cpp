#include "deletetrain.h"
#include "ui_deletetrain.h"


deleteTrain::deleteTrain(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::deleteTrain)
{
    ui->setupUi(this);
    ui->showSign->setReadOnly(true);
}

deleteTrain::~deleteTrain()
{
    delete ui;
}




void deleteTrain::on_deleteButton_clicked()
{
    ui->showSign->clear();
    QString tempBeginPlace=ui->beginPlace->text();
    QString tempEndPlace=ui->endPlace->text();
    QString tempBegin=ui->beginTime->text();
    QString tempEnd=ui->endTime->text();
    myTrain new_myTrain;
    city myCity;
    if(new_myTrain.deleteTrainTrip(tempBeginPlace.toStdString(),tempEndPlace.toStdString(),tempBegin.toStdString(),tempEnd.toStdString())){
        ui->showSign->setText("成功删除！");
        new_myTrain.saveInfo();
    }
    else{
        ui->showSign->setText("错误信息，删除失败！您有可能想要删除天堂哦.");
    }
}


void deleteTrain::on_deleteAllButton_clicked()
{
    ui->showSign->clear();
    QString tempBeginPlace=ui->beginPlace->text();
    QString tempEndPlace=ui->endPlace->text();
    myTrain new_myTrain;
    city myCity;
    if(new_myTrain.deleteAll(tempBeginPlace.toStdString(),tempEndPlace.toStdString())){
        ui->showSign->setText("成功删除！");
        new_myTrain.saveInfo();
    }
    else {
        ui->showSign->setText("错误信息，删除失败！您有可能想要删除天堂哦.");
    }
}


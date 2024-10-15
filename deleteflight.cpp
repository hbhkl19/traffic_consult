#include "deleteflight.h"
#include "ui_deleteflight.h"

deleteFlight::deleteFlight(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::deleteFlight)
{
    ui->setupUi(this);
    ui->showSign->setReadOnly(true);
}

deleteFlight::~deleteFlight()
{
    delete ui;
}

void deleteFlight::on_deleteButton_clicked()
{
    ui->showSign->clear();
    QString tempBeginPlace=ui->beginPlace->text();
    QString tempEndPlace=ui->endPlace->text();
    QString tempBegin=ui->beginTime->text();
    QString tempEnd=ui->endTime->text();
    myPlane new_myPlane;
    city myCity;
    if(new_myPlane.deleteFlight(tempBeginPlace.toStdString(),tempEndPlace.toStdString(),tempBegin.toStdString(),tempEnd.toStdString()))
        ui->showSign->setText("成功删除！");
    else{
        ui->showSign->setText("错误信息，删除失败！您有可能想要删除天堂哦.");
    }
}


void deleteFlight::on_deleteAllButton_clicked()
{
    ui->showSign->clear();
    QString tempBeginPlace=ui->beginPlace->text();
    QString tempEndPlace=ui->endPlace->text();
    myPlane new_myPlane;
    city myCity;
    if(new_myPlane.deleteAll(tempBeginPlace.toStdString(),tempEndPlace.toStdString())){
        ui->showSign->setText("成功删除！");
        new_myPlane.saveInfo();
    }
    else {
        ui->showSign->setText("错误信息，删除失败！您有可能想要删除天堂哦.");
    }
}


#include "addflight.h"
#include "ui_addflight.h"

addFlight::addFlight(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::addFlight)
{
    ui->setupUi(this);
    ui->showSign->setReadOnly(true);
}

addFlight::~addFlight()
{
    delete ui;
}

void addFlight::on_addButton_clicked()
{
    ui->showSign->clear();
    QString tempBeginPlace=ui->beginPlace->text();
    QString tempEndPlace=ui->endPlace->text();
    QString tempBegin=ui->beginTime->text();
    QString tempEnd=ui->endTime->text();
    QString fligthId=ui->flightId->text();
    myPlane new_myPlane;
    city myCity;
    if(new_myPlane.addFlight(tempBeginPlace.toStdString(),tempEndPlace.toStdString(),tempBegin.toStdString(),tempEnd.toStdString(),fligthId.toStdString())){
        ui->showSign->setText("成功添加");
        new_myPlane.saveInfo();
    }
    else{
        ui->showSign->setText("错误输入/添加失败——有可能是您误输入地点为天堂或地狱哦！");
    }
}


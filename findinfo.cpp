#include "findinfo.h"
#include "ui_findinfo.h"

findInfo::findInfo(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::findInfo)
{
    ui->setupUi(this);
    setWindowTitle("查询航班/列车");
    ui->findAnswer->setReadOnly(true);
}

findInfo::~findInfo()
{
    delete ui;
}
void getPlaneInfo(myPlane& aPlane, string tempBegin, string tempEnd,findInfo* aFindInfo) {
    int length = aPlane.planeInfo.size();
    for (int i = 0; i < length; i++) {
        if (aPlane.planeInfo[i]->beginAddress == tempBegin && aPlane.planeInfo[i]->endAddress == tempEnd) {
            int lengthT = aPlane.planeInfo[i]->flights.size();
            for (int j = 0; j < lengthT; j++) {
                QString s1="第" +QString::number(j+1)+"趟列车起点站:"+QString::fromStdString(tempBegin)+",终点站:"+QString::fromStdString(tempEnd);
                QString s2=".出发时间为:"+QString::fromStdString(aPlane.planeInfo[i]->flights[j]->beginTime)+",到达时间为:"+QString::fromStdString(aPlane.planeInfo[i]->flights[j]->endTime);
                QString s3="列车班次为:"+QString::fromStdString(aPlane.planeInfo[i]->flights[j]->Id);
                aFindInfo->findPlaneAnswer.push_back(s1+s2+s3);
            }
            return;
        }
    }
}
//友元函数;
void getTrainInfo(myTrain& aTrain, string tempBegin, string tempEnd,findInfo *aFindInfo) {
    int length = aTrain.trainInfo.size();
    for (int i = 0; i < length; i++) {
        if (aTrain.trainInfo[i]->beginAddress == tempBegin && aTrain.trainInfo[i]->endAddress == tempEnd) {
            int lengthT = aTrain.trainInfo[i]->trainTrips.size();
            for (int j = 0; j < lengthT; j++) {
                QString s1="第" +QString::number(j+1)+"趟列车起点站:"+QString::fromStdString(tempBegin)+",终点站:"+QString::fromStdString(tempEnd);
                QString s2=".出发时间为:"+QString::fromStdString(aTrain.trainInfo[i]->trainTrips[j]->beginTime)+",到达时间为:"+QString::fromStdString(aTrain.trainInfo[i]->trainTrips[j]->endTime);
                QString s3="列车班次为:"+QString::fromStdString(aTrain.trainInfo[i]->trainTrips[j]->Id);
                aFindInfo->findTrainAnswer.push_back(s1+s2+s3);
            }
            return;
        }
    }
}

void findInfo::on_findButton_clicked()
{
    ui->findAnswer->clear();
    this->findTrainAnswer.clear();
    this->findPlaneAnswer.clear();
    QString tempBeginPlace=findInfo::ui->beginPlace->text();
    QString tempEndPlace=ui->endPlace->text();
    QString typeFlag=ui->comboBox->currentText();
    std::string beginPlace=tempBeginPlace.toStdString();
    std::string endPlace =tempEndPlace.toStdString();
    myTrain new_myTrain;
    myPlane new_myPlane;
    getTrainInfo(new_myTrain,beginPlace,endPlace,this);
    getPlaneInfo(new_myPlane,beginPlace,endPlace,this);
    if(typeFlag=="列车"){
        //
        int length=this->findTrainAnswer.size();
        for(int i=0;i<length;i++){
            ui->findAnswer->append(findTrainAnswer[i]);
        }
        if(length==0)
            ui->findAnswer->append("抱歉，暂无此列车信息");
    }
    else if(typeFlag=="航班"){

        int length=this->findPlaneAnswer.size();
        for(int i=0;i<length;i++){
            ui->findAnswer->append(findPlaneAnswer[i]);
        }
        if(length==0)
            ui->findAnswer->append("抱歉，暂无此航班信息");
    }
    else{
        ui->findAnswer->append("以下为列车信息:");
        int length=this->findTrainAnswer.size();
        for(int i=0;i<length;i++){
            ui->findAnswer->append(findTrainAnswer[i]);
        }
        if(length==0)
            ui->findAnswer->append("抱歉，暂无此列车信息");


        ui->findAnswer->append("以下为航班信息:");
        int lengthP=this->findPlaneAnswer.size();
        for(int i=0;i<lengthP;i++){
            ui->findAnswer->append(findPlaneAnswer[i]);
        }
        if(lengthP==0)
            ui->findAnswer->append("抱歉，暂无此航班信息");
    }
}

#include "addtrain.h"
#include "ui_addtrain.h"

addTrain::addTrain(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::addTrain)
{
    ui->setupUi(this);
}

addTrain::~addTrain()
{
    delete ui;
}

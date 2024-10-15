#include "addcity.h"
#include "ui_addcity.h"

addCity::addCity(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::addCity)
{
    ui->setupUi(this);
}

addCity::~addCity()
{
    delete ui;
}

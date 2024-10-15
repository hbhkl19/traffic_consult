#include "deletecity.h"
#include "ui_deletecity.h"

deleteCity::deleteCity(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::deleteCity)
{
    ui->setupUi(this);
}

deleteCity::~deleteCity()
{
    delete ui;
}




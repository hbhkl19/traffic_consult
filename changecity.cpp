#include "changecity.h"
#include "ui_changecity.h"

changeCity::changeCity(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::changeCity)
{
    ui->setupUi(this);
}

changeCity::~changeCity()
{
    delete ui;
}

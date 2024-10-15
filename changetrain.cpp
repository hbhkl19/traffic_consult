#include "changetrain.h"
#include "ui_changetrain.h"

changeTrain::changeTrain(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::changeTrain)
{
    ui->setupUi(this);
}

changeTrain::~changeTrain()
{
    delete ui;
}

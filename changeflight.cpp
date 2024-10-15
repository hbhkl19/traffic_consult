#include "changeflight.h"
#include "ui_changeflight.h"

changeFlight::changeFlight(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::changeFlight)
{
    ui->setupUi(this);
}

changeFlight::~changeFlight()
{
    delete ui;
}

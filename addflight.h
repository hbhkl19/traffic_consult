#ifndef ADDFLIGHT_H
#define ADDFLIGHT_H

#include <QMainWindow>
#include"myClass.h"

namespace Ui {
class addFlight;
}

class addFlight : public QMainWindow
{
    Q_OBJECT

public:
    explicit addFlight(QWidget *parent = nullptr);
    ~addFlight();

private slots:
    void on_returnButton_clicked();

    void on_addButton_clicked();

private:
    Ui::addFlight *ui;
};

#endif // ADDFLIGHT_H

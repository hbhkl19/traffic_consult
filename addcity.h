#ifndef ADDCITY_H
#define ADDCITY_H

#include <QMainWindow>

namespace Ui {
class addCity;
}

class addCity : public QMainWindow
{
    Q_OBJECT

public:
    explicit addCity(QWidget *parent = nullptr);
    ~addCity();

private slots:
    void on_returnButton_clicked();

private:
    Ui::addCity *ui;
};

#endif // ADDCITY_H

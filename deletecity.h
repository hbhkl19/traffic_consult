#ifndef DELETECITY_H
#define DELETECITY_H

#include <QMainWindow>

namespace Ui {
class deleteCity;
}

class deleteCity : public QMainWindow
{
    Q_OBJECT

public:
    explicit deleteCity(QWidget *parent = nullptr);
    ~deleteCity();

private slots:
    void on_returnButton_clicked();

private:
    Ui::deleteCity *ui;
};

#endif // DELETECITY_H

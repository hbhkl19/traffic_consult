#ifndef CHANGECITY_H
#define CHANGECITY_H

#include <QMainWindow>

namespace Ui {
class changeCity;
}

class changeCity : public QMainWindow
{
    Q_OBJECT

public:
    explicit changeCity(QWidget *parent = nullptr);
    ~changeCity();

private slots:
    void on_returnButton_clicked();

private:
    Ui::changeCity *ui;
};

#endif // CHANGECITY_H

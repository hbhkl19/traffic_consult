#ifndef DELETEFLIGHT_H
#define DELETEFLIGHT_H

#include <QMainWindow>
#include"myClass.h"

namespace Ui {
class deleteFlight;
}

class deleteFlight : public QMainWindow
{
    Q_OBJECT

public:
    explicit deleteFlight(QWidget *parent = nullptr);
    ~deleteFlight();

private slots:
    void on_returnButton_clicked();

    void on_deleteButton_clicked();

    void on_deleteAllButton_clicked();

private:
    Ui::deleteFlight *ui;
};

#endif // DELETEFLIGHT_H

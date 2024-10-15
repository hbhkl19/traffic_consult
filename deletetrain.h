#ifndef DELETETRAIN_H
#define DELETETRAIN_H

#include <QMainWindow>
#include"myClass.h"

namespace Ui {
class deleteTrain;
}

class deleteTrain : public QMainWindow
{
    Q_OBJECT

public:
    explicit deleteTrain(QWidget *parent = nullptr);
    ~deleteTrain();

private slots:
    void on_returnButton_clicked();

    void on_deleteButton_clicked();

    void on_deleteAllButton_clicked();

private:
    Ui::deleteTrain *ui;
};

#endif // DELETETRAIN_H

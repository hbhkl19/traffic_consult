#ifndef ADDTRAIN_H
#define ADDTRAIN_H

#include <QMainWindow>

namespace Ui {
class addTrain;
}

class addTrain : public QMainWindow
{
    Q_OBJECT

public:
    explicit addTrain(QWidget *parent = nullptr);
    ~addTrain();

private slots:
    void on_returnButton_clicked();

private:
    Ui::addTrain *ui;
};

#endif // ADDTRAIN_H

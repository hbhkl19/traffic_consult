#ifndef CHANGETRAIN_H
#define CHANGETRAIN_H

#include <QMainWindow>

namespace Ui {
class changeTrain;
}

class changeTrain : public QMainWindow
{
    Q_OBJECT

public:
    explicit changeTrain(QWidget *parent = nullptr);
    ~changeTrain();

private slots:
    void on_returnButton_clicked();

private:
    Ui::changeTrain *ui;
};

#endif // CHANGETRAIN_H

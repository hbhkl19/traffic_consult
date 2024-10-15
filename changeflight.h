#ifndef CHANGEFLIGHT_H
#define CHANGEFLIGHT_H

#include <QMainWindow>

namespace Ui {
class changeFlight;
}

class changeFlight : public QMainWindow
{
    Q_OBJECT

public:
    explicit changeFlight(QWidget *parent = nullptr);
    ~changeFlight();

private slots:
    void on_returnButton_clicked();

private:
    Ui::changeFlight *ui;
};

#endif // CHANGEFLIGHT_H

#ifndef FINDINFO_H
#define FINDINFO_H

#include <QMainWindow>
#include"myClass.h"

namespace Ui {
class findInfo;
}

class findInfo : public QMainWindow
{
    Q_OBJECT

public:
    explicit findInfo(QWidget *parent = nullptr);
    ~findInfo();
    std::vector<QString> findTrainAnswer;
    std::vector<QString> findPlaneAnswer;
    friend void getPlaneInfo(myPlane& aPlane, string s1, string s2,findInfo* aFindInfo);
    friend void getTrainInfo(myTrain& aTrain,string s1,string s2,findInfo* aFindInfo);

private slots:
    void on_returnButton_clicked();

    void on_findButton_clicked();

private:
    Ui::findInfo *ui;
    QString beginPlace;
    QString endPlace;
};

#endif // FINDINFO_H

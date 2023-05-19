#ifndef MYGRID_H
#define MYGRID_H
#include <QGridLayout>
#include <QMessageBox>
#include "MatchButton.h"
#include <QLabel>
#include <QTimer>
class MyGrid: public QGridLayout
{
    Q_OBJECT
public:
    QPushButton * arr[30];
    MyGrid();
    MatchButton* sel_id = NULL;
    int score = 0, tries = 50;
    QLabel *label = new QLabel("Score: " + QString::number(score));
    QLabel *label2 = new QLabel("Remaining Tries: " + QString::number(tries));
public slots:
    void check_matches();
    void is_finished();
private:
    QTimer *timer;
};


#endif // MYGRID_H

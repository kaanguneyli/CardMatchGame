#include <QApplication>
#include <QPushButton>
#include <QSpinBox>
#include <QLabel>
#include <QHBoxLayout>
#include <QButtonGroup>
int main(int argc, char *argv[]) {

    QApplication app(argc, argv);
    QWidget *window = new QWidget;

    int score = 0;
    int tries = 50;
    bool newGame = false;

    //bunların yerleşimini ayarlamak lazım
    QLabel *label0 = new QLabel("Card Match Game");
    QLabel *label1 = new QLabel("Score: " + QString::number(score));
    QLabel *label2 = new QLabel("Remaining Tries: " + QString::number(tries));
    QPushButton *buttonNewGame = new QPushButton("NEW GAME");
    QPushButton *buttonX = new QPushButton("COUNTER");


    //bunun içine newgame tıklanınca olacakları yazmak lazım
    QObject::connect(buttonNewGame, &QPushButton::clicked, &app, [&newGame]() {newGame = true;});

    //bunun içine tries 0 ise olacakları yazmak lazım
    QObject::connect(buttonX, &QPushButton::clicked, [&tries, &label2]() {tries--, label2 -> setText("Remaining Tries: " + QString::number(tries));});


    //setTable diye bir fonksiyon olsun, bu en burada (tüm widgetları içine almalı) çalışsın, bir de newgame denince çalışsın
    //win ve lose fonksiyonları olsun bir de (bunlarda da kazandın+skor/kaybettin ve newgame butonu olsun)
 


    QHBoxLayout *layout = new QHBoxLayout;

    layout -> addWidget(label0);
    layout -> addWidget(label1);
    layout -> addWidget(label2);
    layout -> addWidget(buttonNewGame);
    layout -> addWidget(buttonX);



    window -> setLayout(layout);
    window -> show();

    return app.exec();
}

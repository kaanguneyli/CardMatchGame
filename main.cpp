#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include "myButton.h"

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);
    QWidget *window = new QWidget;
    int score = 0, tries = 5;

    QVBoxLayout *layout = new QVBoxLayout();
    QLabel *label = new QLabel("Remaining Tries: " + QString::number(tries));

    QPushButton *newGameButton = new QPushButton("New Game");
    QObject::connect(newGameButton, &QPushButton::clicked, [&](){
        tries = 5;
        label->setText("Remaining Tries: " + QString::number(tries));
        score = 0;
    });

    QHBoxLayout *layout1 = new QHBoxLayout;
    layout1->addWidget(label);
    layout1->addWidget(newGameButton);
    layout->addLayout(layout1);

    QPushButton *buttons[30];
    for (int j = 0; j < 5; j++) {
        QHBoxLayout *layoutX = new QHBoxLayout;
        for (int i = 0; i < 6; i++) {
            //myButton *button = new myButton("bas");
            QPushButton *button = new QPushButton("bas");
            QObject::connect(button, &QPushButton::clicked, [&]() {
                if (tries > 0) {
                    tries--;
                    label->setText("Remaining Tries: " + QString::number(tries));
                } if (score == 15) {
                    label->setText("HELAL LAN YUSUFİ");
                } else if (tries == 0) {
                    label->setText("SALAK SALAK SALAK");
                }
            });
            buttons[j*6+i] = button;
            layoutX->addWidget(button);
        }
        layout ->addLayout(layoutX);
    }

    window->setLayout(layout);
    window->show();
    return app.exec();
}

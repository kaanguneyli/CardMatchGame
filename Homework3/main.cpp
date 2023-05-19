#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QApplication>
#include <QVBoxLayout>
#include <QSpacerItem>
#include "MatchButton.h"
#include "mygrid.h"
#include "randomnames.h"
#include <QButtonGroup>
int main(int argc, char *argv[]){
    QApplication app(argc, argv);
    MyGrid *gl = new MyGrid();


    QPushButton *newGameButton = new QPushButton("New Game");
    QObject::connect(newGameButton, &QPushButton::clicked, [&](){
        gl->tries = 50;
        gl->label2->setText("Remaining Tries: " + QString::number(gl->tries));
        gl->score = 0;
        gl->label->setText("Score: " + QString::number(gl->score));
        std::array<std::string, 30>  elements = random_init();
        for(int row=0; row<5; row++){
            for(int col=0; col<6; col++){
                int index = row*6+col;
                MatchButton *randButton = new MatchButton(index, QString::fromUtf8(elements[index]));
                gl->arr[index]= randButton;
                QObject::connect(randButton, SIGNAL(clicked()), gl, SLOT(check_matches()));
                gl->addWidget(randButton, row, col, 1, 1);

            }
        }
    });

    QHBoxLayout *layout1 = new QHBoxLayout;
    layout1->addWidget(gl->label);
    layout1->addWidget(gl->label2);
    layout1->addWidget(newGameButton);




    QWidget *cw = new QWidget; // main widget
    QVBoxLayout *vb = new QVBoxLayout(cw); // timer, grid and spaceritem
    std::array<std::string, 30>  elements = random_init();
    for(int row=0; row<5; row++){
        for(int col=0; col<6; col++){
            int index = row*6+col;
            MatchButton *randButton = new MatchButton(index, QString::fromUtf8(elements[index]));
            QObject::connect(randButton, SIGNAL(clicked()), gl, SLOT(check_matches()));
            gl->arr[index]= randButton;
            gl->addWidget(randButton, row, col, 1, 1);

        }
    }
    vb->addLayout(layout1);
    vb->addLayout(gl);
    QSpacerItem *si = new QSpacerItem(0, 30, QSizePolicy::Expanding, QSizePolicy::Expanding);
    vb->addSpacerItem(si);

    cw->setWindowTitle("Matching Game");
    cw->resize(640, 480);
    cw->show();
    return app.exec();
}



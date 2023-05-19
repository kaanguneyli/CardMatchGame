#include "mygrid.h"
#include "MatchButton.h"
#include <iostream>
#include <thread>
#include <chrono>

MyGrid::MyGrid(): QGridLayout(){

}


void MyGrid::check_matches(){
    MatchButton* clickedButton = qobject_cast<MatchButton*>(sender());
    if(clickedButton->text!="")
    {if((this->sel_id)== NULL){
            clickedButton->setText(clickedButton->text);
            this->sel_id = clickedButton;
        }else if((this->sel_id->id)!=(clickedButton->id)){
            if(sel_id->text==clickedButton->text){
                sel_id->setText("");
                sel_id->text = "";
                clickedButton->setText("");
                clickedButton -> text = "";
                this->score++;
                this->tries--;

                label2->setText("Remaining Tries: " + QString::number(tries));

                label->setText("Score: " + QString::number(score));
                is_finished();
                this->sel_id = NULL;
            }else{
                clickedButton->setText(clickedButton->text);
                for(int i=0;i<30;i++){
                    arr[i]->MatchButton::mySetEnabled(false);
                }
                QTimer::singleShot(320, this,[=](){
                    sel_id->setText("?");
                    clickedButton->setText("?");
                    this->tries--;
                    label2->setText("Remaining Tries: " + QString::number(tries));
                    is_finished();
                    this->sel_id = NULL;
                    for(int i=0;i<30;i++){
                        arr[i]->setEnabled(true);
                    }

                })
                        ;

            }

        }
    }

}
void help(){

}
void MyGrid::is_finished(){

    if(this->score >= 15 ){
        this->setEnabled(false);
        QMessageBox msgBox;
        msgBox.setText("You won!");
        msgBox.setStandardButtons(QMessageBox::Cancel);
        msgBox.exec();
    }else if(this->tries<=0){
        this->setEnabled(false);
        QMessageBox msgBox;
        msgBox.setText("You failed!");
        msgBox.setStandardButtons(QMessageBox::Cancel);
        msgBox.exec();
    }

}


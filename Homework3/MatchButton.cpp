#include "MatchButton.h"
#include <QMessageBox>
MatchButton::MatchButton(const int id,
                         const QString& text,
                         QWidget* parent):
    QPushButton("?", parent)
{
    this->text = text;
    this->id = id;

}


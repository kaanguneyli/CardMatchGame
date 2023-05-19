#include "MatchButton.h"
#include <QMessageBox>
MatchButton::MatchButton(const int id,
                         const QString& text,
                         QWidget* parent):
        QPushButton("?", parent)

{
    this->text = text;
    this->id = id;
    defaultColor = palette().color(QPalette::Button);
    defaultTextColor = palette().color(QPalette::ButtonText);
}
void MatchButton::mySetEnabled(bool enabled)
{
    QPalette pal = palette();
    if (! enabled) {
        pal.setColor(QPalette::Button, defaultColor);
        pal.setColor(QPalette::ButtonText, defaultTextColor);
        setPalette(pal);
    }
    QPushButton::setEnabled(enabled);
}

#ifndef MATCHBUTTON_H
#define MATCHBUTTON_H
#include <QPushButton>
#include <QPalette>
class MatchButton : public QPushButton
{
    Q_OBJECT
public:
    MatchButton(const int id,
                const QString& text,
                QWidget* parent = 0);
    QString color;
    int id;
    QString text;
};


#endif // MATCHBUTTON_H

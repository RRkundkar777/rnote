// general keydown event for any widget

#ifndef KEYDOWN_H
#define KEYDOWN_H

#include<QObject>

class keydown : public QObject
{
    Q_OBJECT
public:
    keydown();
protected:
       bool eventFilter(QObject* obj, QEvent* event);
};

#endif // KEYDOWN_H

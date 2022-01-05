#include "keydown.h"

#include<QKeyEvent>

// Declaring rdebug() and RN_DBG
void rdebug(QString,bool,QString);
#define RN_DBG true

// ----------------------- keydown defintion --------------------------------//
keydown::keydown()
{

}

// keydown Event Filter
bool keydown::eventFilter(QObject* obj, QEvent* event)
{
    if (event->type()==QEvent::KeyPress) {
        QKeyEvent* key = static_cast<QKeyEvent*>(event);
        if ( (key->key()==Qt::Key_Enter) || (key->key()==Qt::Key_Return) ) {
                rdebug("Enter was pressed",RN_DBG,__FILE__);
        } else {
            return QObject::eventFilter(obj, event);
        }
        return true;
    } else {
        return QObject::eventFilter(obj, event);
    }
    return false;
}

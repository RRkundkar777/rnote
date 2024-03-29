#include<QKeyEvent>
#include "keydown.h"

// constructor
keydown::keydown()
{

}

// keydown event filter
bool keydown::eventFilter(QObject* obj, QEvent* event)
{
    if (event->type() == QEvent::KeyPress)
    {
        QKeyEvent* key = static_cast<QKeyEvent*>(event);
        if ((key->key() == Qt::Key_Enter) || (key->key() == Qt::Key_Return))
        {

        }
        else
        {
            return QObject::eventFilter(obj, event);
        }
        return true;
    }
    else
    {
        return QObject::eventFilter(obj, event);
    }
    return false;
}

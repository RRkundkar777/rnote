// The file to ease debugging mechanism

#ifndef CONFIG_H
#define CONFIG_H

#include<QString>
#include<QDebug>

// Debugging Macro
#define RN_DBG true

// Function to write debug statements
void rdebug(QString,bool,QString);

void rdebug(QString message,bool mode,QString file = "")
{
    QString filename = file.split("/").last();
    if(mode){
        qDebug() << filename << ":" << message;
    }
    return;
}

#endif // CONFIG_H

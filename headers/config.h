// The file to ease debugging mechanism

#ifndef CONFIG_H
#define CONFIG_H

#include<QString>
#include<QDebug>

#define RN_DBG true

void rdebug(QString message,bool mode,QString file = "")
{
    QString filename = file.split("/").last();
    if(mode){
        qDebug() << filename << ":" << message;
    }
    return;
}


#endif // CONFIG_H

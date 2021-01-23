#include"tabStack.h"
#include<QString>

//Initialising the list
void init(slist *L1){
    *L1 = NULL;
}

//Inserts a newnode at the end of list
void sappend(slist *L1,QString location){
    //Allocating a newnode
    node* newnode = (node*) malloc(sizeof(node));
    //Handling malloc failure
    if(!newnode){
        qDebug()<<"MemoryError: Failed to allocate memory\n";
    }
    //Initialising the newnode with data and next pointer
    newnode->location = location;
    newnode->filename = location.split("/").back();
    newnode->repeat = 0;
    newnode->next = NULL;

    //Handling empty list
    if(!(*L1)){
        (*L1) = newnode;
        return;
    }
    else{
        //Linking the newnode to linked list
        node* traveller = (*L1);
        while(traveller->next){
            if(traveller->filename == newnode->filename)
            {
                   newnode->repeat++;
            }
            traveller = traveller->next;
        }
        traveller->next = newnode;
    }
    return;
}

void display(slist *L1)
{
    node* traveller = *L1;
    while(traveller)
    {
        qDebug() <<"filename "<< traveller->filename;
        qDebug() <<"location "<< traveller->location;
        qDebug() <<"repaeat "<< traveller->repeat;
        qDebug()<<"\n";
        traveller = traveller->next;
    }
}












//Singly Linked List ADT for multiple data types
#include<iostream>

// For String Manipulation
#include<QStringList>

// For Debugging
#include<QDebug>

//Change the typedef for accomodating multiple data types
typedef int infi;

//for greater sizes
typedef long long INT;

//Node of a Linked List
typedef struct node{
    int repeat;
    QString location;
    QString filename;
    struct node* next;
}node;

//Node pointer as list
typedef node* slist;

// Linked List Functions
void init(slist *L1); //Initialises the linked list with NULL
void sappend(slist *L1,QString location); //Inserts a node at end of list
void remove(slist *L1,QString location); //Removes the node containing a certain data
void display(slist *L1);

#include"tabStack.h"

// Function Definitions of tabStack
void init(array A1,int s)
{
    A1->size = s;
    A1->ptr = (tabData*) malloc(sizeof(tabData)*s);
    A1->length = 0;
}

void append(array A1,tabData tbd)
{
    int len = A1->length;
    A1->ptr[len] = tbd;
    len++;
    A1->length = len;
}
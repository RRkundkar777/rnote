#include"tabData.h"

// Array Structure
typedef struct arry
{
    int size;
    int length;
    tabData *ptr;
}arry;

// Aliasing
typedef arry* array;

// Function Prototypes of tabStack
void init();
void append(array,tabData);
#include"tabData.h"
// Constructors and member function
tabData::tabData(int index,std::string name,std::string location)
{
    this->tabIndex = index;
    this->fileName = name;
    this->fileLocation = location;
}
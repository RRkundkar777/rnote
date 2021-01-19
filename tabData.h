#include<iostream>
// A TabData Class
class tabData
{
    private:
        int tabIndex;
        std::string fileName;
        std::string fileLocation;
        
    public:
        tabData(){}
        tabData(int,std::string,std::string);
        int getTabIndex(tabData*);
};
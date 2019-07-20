/***********************************
**  Author:  Bryan Konshak
**  Date:  10/17/2016
**  Description:  List Header file
**************************************/

#ifndef LIST_HPP
#define LIST_HPP


#include <string>

class List
{
private:
    Item** ItemArray;//an array of Item pointers
    int endArray;//keeps track of end of array
    std::string itemName;
    std::string itemType;
    double quantity;
    double pricePer;
    int size;
    double totalList;
    double finalTally;
    
    
public:
    List();
    ~List();
    void addItem();
    void menu();
    void doubleList();
    void printList();
    void removeItem();
   
};
#endif


    
    
    

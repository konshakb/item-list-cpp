/***********************************
**  Author:  Bryan Konshak
**  Date:  10/17/2016
**  Description:  Item header file
**************************************/

#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

class Item
{
private:
    std::string name;
    std::string type;
    double quantity;
    double unitPrice;
    double totalPrice;
    
public:
   Item(std::string, std::string, double, double);
   Item();
   std::string getName();
   std::string getType();
   double getQuantity();
   double getUnitPrice();
   double getTotalPrice();
  /* void setName(std::string);
   void setType(std::string);
   void setQuantity(double);
   void setUnitPrice(double);*/
   friend bool operator== (std::string a, Item* b);

};
#endif


    
    

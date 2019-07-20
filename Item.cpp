/***********************************
**  Author:  Bryan Konshak
**  Date:  10/17/2016
**  Description:  Item.cpp class file
**************************************/
#include <iostream>
//#include <stdio.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <string>
//#include "List.hpp"
#include "Item.hpp"
/*using std::cin;
using std::cout;
using std::endl;
using std::string;*/
using std::endl;

/*******************************************************************************************************
**  
**  Item constructor takes name, type, quantity and price as paramaters, and then formula for total price
**  
**********************************************************************************************************/
Item::Item(std::string nameIn, std::string typeIn, double quantityIn, double unitPriceIn)
{
    this->name=nameIn;
    this->type=typeIn;
    this->quantity = quantityIn;
    this->unitPrice = unitPriceIn;
    this->totalPrice = unitPrice * quantity;
   // std::cout << name << ": " << quantity << " Price per " << type << ": " << unitPrice << " Total price: $" << totalPrice << endl;
}
/*******************************************************************************************************
**  
** Item default constructor 
**  
**********************************************************************************************************/
Item::Item()
{
    this->name="REMOVED ITEM";
    this->type="REMOVED ITEM";
    this->quantity=0;
    this->unitPrice=0;
    this->totalPrice = unitPrice * quantity;
}
/*******************************************************************************************************
**  
**  accessory functions
**  
**********************************************************************************************************/
std::string Item::getName()
{
    return name;
}
std::string Item::getType()
{
    return type;
}

double Item::getQuantity()
{
    return quantity;
}

double Item::getUnitPrice()
{
    return unitPrice;
}
double Item::getTotalPrice()
{
    return totalPrice;
}
/*
void Item::setName(std::string nameIn)
{
    this->name=nameIn;
}
void Item::setType(std::string typeIn)
{
    this->type=typeIn;
}
void Item::setQuantity(double quantityIn)
{
    this->quantity=quantityIn;
}
void Item::setUnitPrice(double priceIn)
{
    this->totalPrice=priceIn;
}
*/
bool operator==(std::string a, Item* b)
{
    return a==b->getName();
}


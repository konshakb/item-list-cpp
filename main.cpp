/***********************************
**  Author:  Bryan Konshak
**  Date:  10/17/2016
**  Description:  main.cpp for Grocery shopping list
**************************************/
#include <iostream>
//#include <stdio.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Item.hpp"
#include "List.hpp"
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()

{
//    Item Item1("Meat", "3", 3, 1.99);
    List Grocery;//create the list object then run the menu function
    Grocery.menu();
    return 0;
}



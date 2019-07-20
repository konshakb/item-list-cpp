/***********************************
**  Author:  Bryan Konshak
**  Date:  10/17/2016
**  Description:  List.cpp class
**************************************/
#include <iostream>
//#include <stdio.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iomanip>
#include "Item.hpp"
#include "List.hpp"
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::setw;

/************************************************************************************************
**  
** List constructor 
**  
***************************************************************************************************/
List::List()
{
    size = 4;//original size of array
    ItemArray = new Item*[size];
    for (int i = 0; i<size; i++)
        ItemArray[i] = NULL;
    endArray=0;//tracker for end of array
    totalList=0;
}

/************************************************************************************************
**  
**  List destructor
**  
***************************************************************************************************/

List::~List()
{
    for (int i =0; i <size; i++)
    {
        delete ItemArray[i];
    }
    delete [] ItemArray;
}
    
/************************************************************************************************
**  
**  addItem() adds item to item* array
**  
***************************************************************************************************/
void List::addItem()
{
    cout << "What is the name of the item? " << endl;//get name from user
    cin.ignore(1000, '\n');
    getline(cin, itemName);
  // cout << endArray << endl;
    cout << "What is the unit of the item (pounds, ounces, bags, etc) ? " << endl;//get unity
//    cin.ignore(1000, '\n');
    getline(cin, itemType);
    quantity;
    while (cout  << "How many items do you want? "  && !(cin >> quantity ) || quantity<1 )//get quantity
    {
        
            cout << "Please enter a number greater than 0 " << endl;//input validation function
            cin.clear();
            cin.ignore(1000, '\n');
    }
    pricePer;
    while (cout  << "What is the price per unit? "  && !(cin >> pricePer ) || quantity<1)//get price
    {
        
            cout << "Please enter a number greater than 0 " << endl;//input validation
            cin.clear();
            cin.ignore(1000, '\n');
    }
    Item* test = new Item(itemName, itemType, quantity, pricePer);//create the Item for the List
    ItemArray[endArray]=test;//put created Item in the next spot in the array
   int duplicate;//check for duplicate entry
   if (endArray > 0)//dont check for duplicate first run
   {

    for (int k = 0; k < endArray; k++)
    {
        if (itemName==ItemArray[k])
        {
            duplicate = k;
            break;//found duplicate with overloaded function
        }
        else duplicate = k;
    }
   // cout << duplicate << endl << endl;
   if (itemName==ItemArray[duplicate])//overloaded == function
   {
       cout << "Item is already on your list" << endl;
       //dont add to endArray and it doesn't print!!!
//       ItemArray[duplicate] = NULL;
       printList();
   }
   else
   {
    if (endArray == (size-1))//check to double size of array
    {  size= size * 2;
      //  cout << "this is the new size!! " << size << endl << endl << endl;
    doubleList();//double the array if need be
    }
    endArray++;//move the array to the next element for the next item
    printList();
    }
   }
   else
   {
       endArray++;//move array
       printList();//print
   }

}
/************************************************************************************************
**  
** menu() function runs program 
**  
***************************************************************************************************/
void List::menu()
{
cout <<"This program will help you make a shopping list.  Let's get started. " << endl;
string menu;
do
{
do
{   //menu template
    cout << "(1) Add Item " << endl;
    cout << "(2) Remove Item " << endl;
  //  cout << "Add Item" << endl;
    cout << "(3) End and Print List" << endl;
    cout << "Choose option 1, 2, or 3" << endl;
    cin >> menu;
    
    
}  while (menu != "1" && menu != "2" && menu != "3");//menu for user to select
    if (menu == "1")
    addItem();//add item

    if (menu == "2")
    removeItem();//remove item
    if (menu == "3")
    {
    cout << "Final Shopping List: " << endl << endl;
    printList();//print list
    }

} while (menu == "1" || menu == "2");//loop ends if 3 selected.  runs if 1 or 2 is selected
}

/************************************************************************************************
**  
**  doubleList() doubles the dynamic array
**  
***************************************************************************************************/
void List::doubleList()
{  // cout << "this is the size in the function " << size << endl;
    Item** temp = new Item*[size];//create temp Item arrary
    for (int i=0; i < size; i++)
    {
      //  cout << i << " " << size <<  endl;
        temp[i]= NULL;//set to NULL
    }
    for (int j= 0; j < size; j++)
        temp[j] = ItemArray[j];//copy to temp array
   if (ItemArray)
   {
       delete [] ItemArray;//delete ItemArray
   }
  ItemArray = new Item*[size];
    for (int i = 0; i<size; i++)
        ItemArray[i] = NULL;
   for (int k = 0; k< size; k++)//copy back to ItemArray
      ItemArray[k] = temp[k];

    delete [] temp;//delete new temp
}
/************************************************************************************************
**  
** printList() prints list to screen 
**  
***************************************************************************************************/
void List::printList()
{
    
    for (int k = 0; k < endArray; k++)
    {
        totalList += ItemArray[k]->getTotalPrice();//formula for total of all items on list
    }
    cout << endl << endl;
    for (int i = 0; i < endArray; i++)
    {
        cout << "Name: " << ItemArray[i]->getName() << "      ";//get the name
        cout << " Unit: " <<ItemArray[i]->getType() << "      ";  //get the type
        cout  << " Quantity: " << ItemArray[i]->getQuantity() << "      ";//show quantity
        cout << " Price per Unit: $" << ItemArray[i]->getUnitPrice() << "      ";//show price
        cout <<  " Total List Price: $" << ItemArray[i]->getTotalPrice() << endl;//show total

    }
    
        cout << "Total Shopping List Price: $"  << totalList << endl;
        totalList=0;//reset

}
/************************************************************************************************
**  
** removeItem() 
**  
***************************************************************************************************/
void List::removeItem()
{
    
itemName = "REMOVED" ;
itemType = "REMOVED" ;
quantity = 0.0 ;
pricePer = 0.0;
    printList();
    Item* removed = new Item(itemName, itemType, quantity, pricePer);//create the Item for the List
//    Empty =  Item(itemName, itemType, quantity, pricePer);//create the Item for the List
    cout << "What item do you want to remove?  " << endl;
   // cin >> itemName;
    cin.ignore(1000, '\n');
    getline(cin, itemName);//user removes item
    for (int i = 0; i < endArray; i++)
    {
        if (ItemArray[i]->getName() == itemName)
        {
            ItemArray[i] = removed;//remove Item* replaces the original, shows as removed when list prints
        }

    }

        
}
























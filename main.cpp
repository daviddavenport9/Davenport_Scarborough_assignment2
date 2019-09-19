#include "SortedLinkedList.h"
#include "ListNode.h"
#include "ItemType.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int main(const int argc, const char * argv[]){
SortedLinkedList list;
ItemType item;
int input;
std::fstream fs;
fs.open(argv[1], std::fstream::in);
if (fs.is_open())
{
 fs >> input;
 while (!fs.eof())
  {       
   item.initialize(input);
   list.insertItem(item);
   fs >> input;
   }
 }
 else{    
   std::cout << "Failed to open the input file" << std::endl;
   return 0;
     }
     
 cout << "Commands:" << endl;
 cout << "(i) - Insert value" << endl;
 cout << "(d) - Delete value" << endl;
 cout << "(s) - Search value" << endl;
 cout << "(n) - Print next iterator value" << endl;
 cout << "(r) - Reset iterator" << endl;
 cout << "(p) - Print list" << endl;
 cout << "(l) - Print length" << endl;
 cout << "(b) - Reverse" << endl;
 cout << "(q) - Quit program" << endl;
 
 char command;
 while (true){
   cout << "Enter a command: ";
   cin >> command;
   if (command == 'i'){
    list.printList();
    cout << "" << endl;
    int numInsert;
    cout << "Enter number: ";
    cin >> numInsert;
    item.initialize(numInsert);
    list.insertItem(item);
    list.printList();
    cout << "" << endl;
   }//if
   else if (command == 'd'){
   
   }//else if
   else if (command == 's'){
   
   }//else if
   else if (command == 'n'){
    //cout << list.getNextItem();
   }//else if
   else if (command == 'r'){
   
   }//else if
   else if (command == 'p'){
     list.printList();
     cout << "" << endl;
   }//else if
   else if (command == 'l'){
     cout << "List length is " << list.getLength() << endl;
   }//else if
   else if (command == 'b'){
   
   }//else if
   else if (command == 'q'){
     cout << "Quitting program..." << endl;
     exit(0);
   }//else if
 }//while    
}//main     

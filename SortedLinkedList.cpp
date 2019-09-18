#include "SortedLinkedList.h"
int main(){
  SortedLinkedList::SortedLinkedList(){
    length = 0;
    head = NULL;
  } // SortedLinkedList                                                                          
  SortedLinkedList::~SortedLinkedList(){
    resetList();
  } // destructor                                                                                
  int SortedLinkedList::getLength const(){
    return length;
  } // getLength                                                                                 
  void SortedLinkedList::insertItem(ItemType item){

  } // sortedLinkedList                                                                          
  void SortedLinkedList::deleteItem(ItemType item){

  } // deleteItem                                                                                
  void SortedLinkedList::searchItem(ItemType &item){

  } // searchItem                                                                                
  ItemType SortedLinkedList::getNextItem(){

  } // getNextItem                                                                               
  void SortedLinkedList::resetList(){
    currentPos = NULL;
    length = 0;
  } // resetList                                                                                 
} // main                     

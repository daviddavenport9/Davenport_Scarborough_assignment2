#include "SortedLinkedList.h"
#include <iostream>
using namespace std;
SortedLinkedList::SortedLinkedList(){
    length = 0;
    head = NULL;
} // SortedLinkedList

SortedLinkedList::~SortedLinkedList(){
  makeEmpty();
} // destructor

void SortedLinkedList::makeEmpty(){
  ListNode *temp;
  while(head != NULL){
    temp = head;
    head = head->next;
    delete temp;
  } // while
  length = 0;
} // makeEmpty

bool SortedLinkedList::isFull() const{
  ListNode *loc;
  try{
    loc = new ListNode;
    delete loc;
    return false;
  }catch(bad_alloc exception){
    return true;
  } // try
} // isFull

int SortedLinkedList::getLength() const{
  return length;
} // getLength

void SortedLinkedList::insertItem(ItemType item){
  if(isFull()){ // if list is full
    cout << "can't add new item; list is full" << endl;
  }else{ // if there is space
    ListNode *node = new ListNode;
    ListNode *predLoc = NULL;
    ListNode *location = head;
    node->item = item;
    bool moreToSearch = (location != NULL); // checks if at end of list
    while(moreToSearch){
      if(location->item.compareTo(item) == LESS){
	predLoc = location;
	location = location->next;
	moreToSearch = (location != NULL);
      }else{ // nothing else to search
	moreToSearch = false;
      } // if
    } // while
    if(predLoc == NULL){ // if list is empty
      node->next = head;
      head = node; // node becomes head -- first item in list
    }else{
      node->next = location;
      predLoc->next = node;
    } // if
    length++;
  } // if
} // insertLinkedList

void SortedLinkedList::deleteItem(ItemType item){
  
} // deleteItem
int SortedLinkedList::searchItem(ItemType &item){
  int index = 0;
  ListNode *temp = head;
  bool moreToSearch = temp != NULL;
  while(moreToSearch){
    if(temp->item.compareTo(item) == LESS){ // keep looking
      temp = temp->next;
      index++;
    }else if(temp->item.compareTo(item) == EQUAL){ // found
      moreToSearch = false;
    }else{ // at end
      index = -1;
      cout << "Item not found" << endl;
      moreToSearch = false;
    } // if
  } // while
  return index;
} // searchItem

ItemType SortedLinkedList::getNextItem(){
  if(currentPos == NULL){ // if at end of list OR new list
    currentPos = head;
    return currentPos->item;
  }else{
    currentPos = currentPos->next;
    return currentPos->item;
  } // if
} // getNextItem

void SortedLinkedList::resetList(){
  currentPos = NULL;
  length = 0;
} // resetList

std::ostream& operator<<(std::ostream& os, const ItemType& item){
  return os << item.getValue();
}

void SortedLinkedList::printList(){
    ListNode* temp;
    for (temp = head; temp != NULL; temp = temp = temp->next){
      cout << temp->item.getValue() << " ";
    }
}//printList

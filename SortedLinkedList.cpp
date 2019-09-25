#include "SortedLinkedList.h"
#include <iostream>
using namespace std;
SortedLinkedList::SortedLinkedList(){
    length = 0;
    head = NULL;
} // SortedLinkedList

std::ostream& operator<<(std::ostream& os, const ItemType& item){
  return os << item.getValue();
}

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
  ListNode *tmp = head;
  tmp->item = head->item;
  ListNode *predLoc = NULL;
  bool moreToSearch = (tmp != NULL);
  if(tmp->item.compareTo(item) == EQUAL){ // check first item                                                                                                                                       
    cout << "equal first" << endl;
    head = head->next;
    moreToSearch = false;
  } // if                                                                                                                                                                                           
  while(moreToSearch){
    if(tmp->item.compareTo(item) == EQUAL){ // if item is found                                                                                                                                     
      cout << "equal mid or end" << endl;
      predLoc->next = tmp->next;
      moreToSearch = false;
    }else if(tmp->item.compareTo(item) == LESS){
      predLoc = tmp;
      tmp = tmp->next;
      moreToSearch = (tmp != NULL);
    } // if                                                                                                                                                                                         
  } // while                                                                                                                                                                                        
  delete tmp;
  length--;
} // deleteItem        

bool SortedLinkedList::valueExist(ItemType &item){
  ListNode *temp = head;
  while (temp != NULL){
    if (temp->item.compareTo(item) == EQUAL){
      return true;
    }//if
    temp = temp->next;
  }//while
  return false;
}

int SortedLinkedList::searchItem(ItemType &item){
  int index = 0;
  ListNode *temp = head;
  bool moreToSearch = temp != NULL;
  while(moreToSearch){
   if(temp->item.compareTo(item) == EQUAL){
     moreToSearch = false;
   }
   else{
     temp = temp->next;
     index++;
   }
  /*
    if(temp->item.compareTo(item) == LESS){ // keep looking
      temp = temp->next;
      index++;
    }else if(temp->item.compareTo(item) == EQUAL){ // found
      moreToSearch = false;
    }else{ // at end
      index = -1;
      cout << "Item not found" << endl;
      moreToSearch = false;
    } // else
    */
  } // while
  return index;
} // searchItem

ItemType SortedLinkedList::getNextItem(){
   if (length == 0){
     cout << "List is empty" << endl;
     return currentPos->item;
   }
  if(currentPos == NULL){ // assigns current position to head
    currentPos = head;
    cout << currentPos->item.getValue() << " ";
    cout << "" << endl;
    return currentPos->item;
  }else{
    if (currentPos->next == NULL){//end of list
      cout << "The end of the list is reached" << endl;
      return currentPos->item;
    }
    currentPos = currentPos->next;//iterates through every value
    cout << currentPos->item.getValue() << " ";
    cout << "" << endl;
    return currentPos->item;
  } // if
} // getNextItem

void SortedLinkedList::resetList(){
  currentPos = NULL;
} // resetList

void SortedLinkedList::printList(){
    ListNode* temp;
    for (temp = head; temp != NULL; temp= temp->next){
      cout << temp->item.getValue() << " ";
    }
}//printList

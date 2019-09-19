#include "ListNode.h"
#include "ItemType.h"
#ifndef SORTEDLINKEDLIST_H
#define SORTEDLINKEDLIST_H
class SortedLinkedList{
 public:
  SortedLinkedList();
  ~SortedLinkedList();
  int getLength() const;
  void insertItem(ItemType item);
  void deleteItem(ItemType item);
  int searchItem(ItemType &item);
  ItemType getNextItem();
  void resetList();
  void makeEmpty();
  void printList();
  bool isFull() const;
  bool valueExist(ItemType &item);
 private:
  int length;
  ListNode* head;
  ListNode* currentPos;
}; // SortedLinkedList                                                                           
#endif

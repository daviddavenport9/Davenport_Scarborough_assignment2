#include "ListNode.h"
#include "ItemType.h"
#ifndef SORTEDLINKEDLIST_H
#define SORTEDLINKEDLIST_H
class SortedLikedList{
 public:
  SortedLinkedList();
  ~SortedLinkedList();
  int getLength() const;
  void insertItem(ItemType item);
  void deleteItem(ItemType item);
  int searchItem(ItemType &item);
  ItemType getNextItem();
  void resetList();
 private:
  int length;
  ListNode* head;
  ListNode* currentPos;
}; // SortedLinkedList                                                                           
#endif

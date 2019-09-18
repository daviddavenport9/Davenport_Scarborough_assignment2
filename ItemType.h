#ifndef ITEMTYPE_H
#define ITEMTYPE_H

enum Comparison {LESS, EQUAL, GREATER };

class ItemType{

public : 
  ItemType();
  Comparison compareTo(ItemType) const;
  void print() const;
  void initialize(int number);
  
private:
  int value;

};
#endif

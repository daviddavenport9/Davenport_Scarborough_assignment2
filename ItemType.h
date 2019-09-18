#ifndef ITEMTYPE_H
#define ITEMTYPE_H

enum Comparison {LESS, EQUAL, GREATER };

class ItemType{

public : 
  ItemType();
  Comparison CompareTo(ItemType) const;
  void Print() const;
  void Initialize(int number);
  
private:
  int value;

};
#endif

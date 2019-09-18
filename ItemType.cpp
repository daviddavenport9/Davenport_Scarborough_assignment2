#include "ItemType.h"
#include <iostream>

using namespace std;

  ItemType::ItemType(){
    initialize(0);
  }

 Comparison ItemType::compareTo(ItemType otherItem) const{
  if (value < otherItem.value){
    return LESS;
    }
  else if (value > otherItem.value){
    return GREATER;
    }
  else{
    return EQUAL;
    }
}

  void ItemType::print() const{
  cout << value << endl;
}

  void ItemType::initialize(int number){
   value = number; 
}

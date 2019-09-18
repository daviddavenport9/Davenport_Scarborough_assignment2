#include "ItemType.h"
#include <iostream>

using namespace std;

  ItemType::ItemType(){
    Initialize(0);
  }

 Comparison ItemType::CompareTo(ItemType otherItem) const{
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

  void ItemType::Print() const{
  cout << value << endl;
}

  void ItemType::Initialize(int number){
   value = number; 
}

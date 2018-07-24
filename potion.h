#ifndef _POTION_H_
#define _POTION_H_

#include "item.h"

class Potion: public Item {
  std::string description;
 public:
  Potion(Stats effect); // take a description as a param
  std::string getDescription();
  void reverse(Player &user);
};

#endif

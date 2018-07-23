#ifndef _POTION_H_
#define _POSION_H_

#include <string.h>

class Potion: public Item {
 Stats effect;
 public:
  Potion(Stats effect);
  string getDescription();
  void getUsed(Player &user);
  void reverse(Player &user);
};

#endif

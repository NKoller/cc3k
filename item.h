#ifndef _ITEM_H_
#define _ITEM_H_

#include "stats.h"
#include "player.h"

class Item {
  char name;
  Stats s;
 public:
  Item(char name, Stats s);
  char getName();
  virtual void getUsed(Player &user);
};

#endif
 

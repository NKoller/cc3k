#ifndef _ITEM_H_
#define _ITEM_H_

#include "stats.h"
#include "player.h"

class Item {
  Stats effects();
 public:
  char getName();
  virtual void getUsed(Player &user);
};

#endif
 

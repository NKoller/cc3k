#ifndef _ITEM_H_
#define _ITEM_H_

#include "stats.h"
#include "player.h"

class Item {
  char name;
  Stats effect;
 public:
  Item(char name, Stats s);
  char getName() const;
  Stats getEffect() const;
  void getUsed(Character &user);
  virtual void getUsed(Player &user) = 0;
};

#endif

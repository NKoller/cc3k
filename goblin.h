#ifndef _GOBLIN_H_
#define _GOBLIN_H_

#include "player.h"

class Goblin: public Player {
 public:
  int defend(Character &attacker) override;
  Goblin(Observer* myTD);
  ~Goblin();
};

#endif

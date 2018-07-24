#ifndef _VAMPIRE_H_
#define _VAMPIRE_H_

#include "player.h"

class Vampire: public Player {
 public:
  int defend(Character &attacker) override;
  Vampire(Observer* myTD);
  void attack(Dwarf &defender);
  ~Vampire();
};

#endif

#ifndef _VAMPIRE_H_
#define _VAMPIRE_H_

#include "player.h"

class Vampire: public Player {
 public:
  int defend(Character &attacker) override;
  double generalAttack(Character &defender) override;
  double attack(Dwarf &defender) override;
  Vampire(Observer *myTD);
  ~Vampire();
};

#endif

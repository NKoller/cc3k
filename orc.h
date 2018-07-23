#ifndef _ORC_H_
#define _ORC_H_

#include "character.h"

class Orc: public Character {
 public:
  Orc();
  void defend(Character &attacker) override;
  //double attack(Goblin &defender) override;
  ~Orc();
};

#endif

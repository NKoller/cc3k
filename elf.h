#ifndef _ELF_H_
#define _ELF_H_

#include "character.h"

class Elf: public Character {
  bool attacking = false;
 public:
  Elf();
  int defend(Character &attacker) override;
  double generalAttack(Character &defender) override;
  double attack(Drow &defender) override;
};

#endif

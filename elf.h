#ifndef _ELF_H_
#define _ELF_H_

#include "character.h"

class Elf: public Character {
 public:
  Elf();
  void defend(Character &attacker) override;
  //double attack(Drow &defender) override;
  ~Elf();
};

#endif

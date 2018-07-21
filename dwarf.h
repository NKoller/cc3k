#ifndef _DWARF_H_
#define _DWARF_H_

#include "character.h"

class Dwarf: public Character {
 int returnGold() const;
 public:
  void defend(Character &attacker) override;
  Dwarf();
  ~Dwarf();
};

#endif

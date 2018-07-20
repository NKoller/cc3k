#ifndef _DWARF_H_
#define _DWARF_H_

#include "character.h"

class Dwarf: public Character {
 int returnGold() const;
 public:
  Dwarf();
  ~Dwarf();
};

#endif

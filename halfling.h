#ifndef _HALFLING_H_
#define _HALFLING_H_

#include "character.h"

class Halfling: public Character {
 public:
  Halfling();
  void defend(Character &attacker);
  ~Halfling();
};

#endif

#ifndef _HUMAN_H_
#define _HUMAN_H_

#include "character.h"

class Human: public Character {
 public:
  Human();
  void defend(Character &attacker);
  ~Human();
};

#endif

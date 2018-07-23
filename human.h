#ifndef _HUMAN_H_
#define _HUMAN_H_

#include "character.h"

class Human: public Character {
  void checkIfDead() override;
 public:
  Human();
  void defend(Character &attacker) override;
  ~Human();
};

#endif

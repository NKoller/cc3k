#ifndef _HUMAN_H_
#define _HUMAN_H_

#include "character.h"

class Human: public Character {
  void checkIfDead() override;
 public:
  Human();
  ~Human();
  void defend(Character &attacker) override;
};

#endif

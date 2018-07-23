#ifndef _MERCHANT_H_
#define _MERCHANT_H_

#include "character.h"

class Merchant: public Character {
  void checkIfDead() override;
 public:
  Merchant();
  ~Merchant();
  int defend(Character &attacker) override;
};

#endif

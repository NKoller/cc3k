#ifndef _MERCHANT_H_
#define _MERCHANT_H_

#include "character.h"

class Merchant: public Character {
 public:
  Merchant();
  void defend(Character &attacker);
  ~Merchant();
};

#endif

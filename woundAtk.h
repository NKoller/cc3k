#ifndef _WOUNDATK_H_
#define _WOUNDATK_H_

#include "potion.h"

class WoundAtk: public Potion {
  static bool used;
 public:
  WoundAtk();
  static bool hasBeenUsed();
  void getUsed(Player &user) override;
  std::string getDesc() const override;
};

#endif

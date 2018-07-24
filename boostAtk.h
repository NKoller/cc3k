#ifndef _BOOSTATK_H_
#define _BOOSTATK_H_

#include "potion.h"

class BoostAtk: public Potion {
  static bool used;
 public:
  BoostAtk();
  static bool hasBeenUsed();
  void getUsed(Player &user) override;
  std::string getDescription() const override;
};

#endif

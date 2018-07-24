#ifndef _WOUNDDEF_H_
#define _WOUNDDEF_H_

#include "potion.h"

class WoundDef: public Potion {
  static bool used;
 public:
  WoundDef();
  bool hasBeenUsed();
  void getUsed(Player &user) override;
};

#endif

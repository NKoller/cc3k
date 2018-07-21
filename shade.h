#ifndef _SHADE_H_
#define _SHADE_H_

#include "player.h"

class Shade: public Player {
 public:
  void defend(Character &attacker) override;
  Shade();
  ~Shade();
};

#endif

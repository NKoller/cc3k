#ifndef _SHADE_H_
#define _SHADE_H_

#include "player.h"

class Shade: public Player {
 public:
  int defend(Character &attacker) override;
  Shade(Observer* myTD);
  ~Shade();
};

#endif

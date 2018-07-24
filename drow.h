#ifndef _DROW_H_
#define _DROW_H_

#include "player.h"

class Drow: public Player {
 public:
  int defend(Character &attacker) override;
  Drow(Observer* myTD);
  void use(Item &i);
  void reversePotions();
  ~Drow();
};

#endif

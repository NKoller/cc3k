#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "character.h"

class Player: public Character {
//vector<Potion> used();
 public:
  //virtual void reversePotions();
  //virtual void use(Item &i);
  virtual void finishTurn();
  Player(Stats status, Observer* myTD);
  virtual ~Player();
};

#endif

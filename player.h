#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "character.h"

class Player: public Character {
  std::vector<Potion *> used;
 public:
  virtual void use(Potion &p);
  //virtual void use(Gold &g);
  virtual void reversePotions();
  virtual void finishTurn();
  virtual double generalAttack(Character &defender) override;
  Player(int maxHP, Stats status, Observer* myTD);
  virtual ~Player();
};

#endif

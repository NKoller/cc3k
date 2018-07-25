#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "character.h"

class Player: public Character {
 protected:
  std::vector<Potion *> used;
 public:
  virtual void use(Potion &p);
  //virtual void use(Gold &g);
  virtual void reversePotions();
  virtual void finishTurn();
  virtual double generalAttack(Character &defender) override;
  virtual int getScore() const;
  Player(int maxHP, Stats status);
  virtual ~Player();
};

#endif

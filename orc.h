#ifndef _ORC_H_
#define _ORC_H_

#include "character.h"

class Orc: public Character {
 public:
  Orc();
  void attack(Goblin &defender);
  ~Orc();
};

#endif

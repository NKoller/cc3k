#ifndef _POISONHP_H_
#define _POISONHP_H_

class PoisonHP:public Potion {
 public:
  PoisonHP();
  bool hasBeenUsed();
  ~PoisonHP();
};

#endif

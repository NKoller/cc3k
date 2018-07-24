#ifndef _RESTOREHP_H_
#define _RESTOREHP_H_

#include "potion.h"

class RestoreHP: public Potion {
  static bool used;
 public:
  RestoreHP();
  static bool hasBeenUsed();
  void getUsed(Player &user) override;
  std::string getDescription() const override;
};

#endif

#ifndef _POTION_H_
#define _POTION_H_

#include "item.h"

class Potion: public Item {
 protected:
  std::string description;
 public:
  Potion(Stats effect, std::string desc);
  virtual std::string getDescription() const = 0;
  Stats reverse() const;
};

#endif

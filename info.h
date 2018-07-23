#ifndef _INFO_H_
#define _INFO_H_

#include "cell.h"

struct Info {
  CellType type;
  char itemName;
  char characterName;
  char otherCharName;
  double otherCharHP;
  double damageDealt;
  int direction;
  unsigned int row;
  unsigned int col;
};

#endif

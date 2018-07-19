#ifndef _INFO_H_
#define _INFO_H_

#include "cell.h"

struct Info {
  CellType type;
  char itemName;
  char characterName;
  unsigned int row;
  unsigned int col;
};

#endif

#include "restoreHP.h"

RestoreHP::RestoreHP(): Potion{Stats{10, 0, 0, 0}} {}
  
bool RestoreHP::hasBeenUsed() {
 return RH;
}

RestoreHP::~RestoreHP() {}

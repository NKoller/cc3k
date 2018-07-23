#include "boostDef.h"

BoostDef::BoostDef(): Potion{Stats{0, 0, 5, 0}} {}
  
bool BoostDef::hasBeenUsed() {
 return BD;
}

BoostDef::~BoostDef() {}

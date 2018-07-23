#include "boostAtk.h"

BoostAtk::BoostAtk():Potion{Stats{0, 5, 0, 0}} {}

bool BoostAtk::hasBeenUsed() {
 return BA; 
}

BoostAtk::~BoostAtk() {}

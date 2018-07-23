#include "woundDef.h"

WoundDef::WoundDef():Potion{Stats{0, 0, -5, 0}} {}
  
bool WoundDef::hasBeenUsed() {
 return WD;
}

WoundDef::~WoundDef() {}

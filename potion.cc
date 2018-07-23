#include "potion.h"

Potion::Potion(Stats effect): Item{"P" , effect} {}

string Potion::getDescription() {
 return name;
}



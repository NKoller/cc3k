#include "potion.h"

Potion::Potion(Stats effect): Item{"P" , effect} {}

string Potion::getDescription() {
 return name;
}

void Potion::getUsed(Player &user) {}

void Potion::reverse(Player &user) {}

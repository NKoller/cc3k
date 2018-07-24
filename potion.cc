#include "potion.h"

Potion::Potion(Stats effect): Item{'P' , effect} {}

std::string Potion::getDescription() {
	// maybe do "if used return description"
	return description;
}

void Potion::reverse(Player &user) {}

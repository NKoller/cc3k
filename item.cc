#include "item.h"

Item::Item(char name, Stats s): name{name}, effect{s} {}

char Item::getName() { return name; }

Stats Item::getEffect() { return effect; }

void Item::getUsed(Character &user) {
	getUsed(static_cast<Player&>(user));
}

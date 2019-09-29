#include "item.h"

Item::Item(char name, std::string desc, Stats s):
		name{name},
		desc{desc},
		effect{s} {}

char Item::getName() const { return name; }

std::string Item::getDesc() const { return desc; }

Stats Item::getEffect() const { return effect; }

void Item::getUsed(Character &user) { getUsed(static_cast<Player&>(user)); }

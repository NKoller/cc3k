#include "potion.h"

Potion::Potion(Stats effect, std::string desc):	Item{'P', desc, effect} {}

Stats Potion::reverse() const {
		return getEffect() * -1;
}

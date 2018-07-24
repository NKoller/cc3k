#include "potion.h"

Potion::Potion(Stats effect, std::string desc):
	Item{'P', effect},
	description{desc} {}

Stats Potion::reverse() const {
	return Stats{0, 0, 0, 0} - getEffect();
}

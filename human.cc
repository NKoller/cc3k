#include "human.h"

Human::Human(): Character{'H', true, Stats{140, 20, 20, 0}} {}

Human::~Human() {}

void Human::checkIfDead() {
	if (status.HP <= 0) {
		setState(State::CharacterDied);
		notifyObservers();
		std::cout << "Oh noey! " << name << " died! :(" << std::endl;
	}
	// spawn gold nearby
}

int Human::defend(Character &attacker) {
	double damage = attacker.attack(*this);
	status.HP -= damage;
	std::cout << "Owie! " << name << " took " << damage << " damage! ";
	std::cout << status.HP << " wittle HPs left..." << std::endl;
	checkIfDead();
    return damage;
}

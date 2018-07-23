#include "shade.h"

int Shade::defend(Character &attacker) {
	double damage = attacker.attack(*this);
	status.HP -= damage;
	std::cout << "Owie! " << name << " took " << damage << " damage! ";
	std::cout << status.HP << " wittle HPs left..." << std::endl;
	checkIfDead();
    setState(State::UpdateTextdisplay);
    notifyObservers();
    return damage;
}

Shade::Shade(Observer* myTD): Player{Stats{125, 25, 25, 0}, myTD} {
    this->attach(myTD);
    setState(State::UpdateTextdisplay);
    notifyObservers();
}

Shade::~Shade() {}

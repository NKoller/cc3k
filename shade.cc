#include "shade.h"

int Shade::defend(Character &attacker) {
	double damage = attacker.attack(*this);
	status.HP -= damage;
    if (status.HP <= 0) status.HP = 0;
	//std::cout << "Owie! " << name << " took " << damage << " damage! ";i
	//std::cout << status.HP << " wittle HPs left..." << std::endl;
    setState(State::UpdateTextdisplay);
    notifyObservers();
    return damage;
}

Shade::Shade(Observer* myTD): Player{125, Stats{125, 1000, 25, 0}, myTD} {
    this->attach(myTD);
    setState(State::UpdateTextdisplay);
    notifyObservers();
}

Shade::~Shade() {}

#include "troll.h"
  
int Troll::defend(Character &attacker) {
    double damage = attacker.attack(*this);
	if (damage != Character::MISSED && damage != Character::NO_ATTACK) {
    	status.HP -= damage;
		if (status.HP < 0) status.HP = 0;
    	setState(State::UpdateTextdisplay);
	    notifyObservers();
	}
    return damage;
}

void Troll::finishTurn() {
	status.HP += 5;
}

Troll::Troll(Observer* myTD): Player{120, Stats{120, 25, 15, 0}, myTD} {}

Troll::~Troll() {}

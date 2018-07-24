#include "troll.h"
  
int Troll::defend(Character &attacker) {
        double damage = attacker.attack(*this);
        status.HP -= damage;
        std::cout << "Owie! " << name << " took " << damage << " damage! ";
        std::cout << status.HP << " wittle HPs left..." << std::endl;
        checkIfDead();
    setState(State::UpdateTextdisplay);
    notifyObservers();
    return damage;
}

Troll::Troll(Observer* myTD): Player{Stats{120, 25, 15, 0}, myTD} {
    this->attach(myTD);
    setState(State::UpdateTextdisplay);
    notifyObservers();
}

void finsihTurn() {

}

Troll::~Troll() {}

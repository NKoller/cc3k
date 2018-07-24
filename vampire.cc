#include "vampire.h"
#include <limits>
  
int Vampire::defend(Character &attacker) {
  double damage = attacker.attack(*this);
  status.HP -= damage;
    //std::cout << "Owie! " << name << " took " << damage << " damage! ";
    //std::cout << status.HP << " wittle HPs left..." << std::endl;
    checkIfDead();
    setState(State::UpdateTextdisplay);
    notifyObservers();
    return damage;
}

Vampire::Vampire(Observer* myTD): Player{std::numeric_limits<int>::max(), Stats{50, 25, 25, 0}, myTD} {
    this->attach(myTD);
    setState(State::UpdateTextdisplay);
    notifyObservers();
}

Vampire::~Vampire() {}

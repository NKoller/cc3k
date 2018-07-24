#include "drow.h"
  
int Drow::defend(Character &attacker) {
 double damage = attacker.attack(*this);
  status.HP -= damage;
  std::cout << "Owie! " << name << " took " << damage << " damage! ";
  std::cout << status.HP << " wittle HPs left..." << std::endl;
  checkIfDead();
  setState(State::UpdateTextdisplay);
  notifyObservers();
  return damage;
}

Drow::Drow(Observer* myTD): Player{Stats{150, 25, 15, 0}, myTD} {
    this->attach(myTD);
    setState(State::UpdateTextdisplay);
    notifyObservers();
}

void Drow::use(Item &i) {

}

void reversePotions() {

}

Drow::~Drow() {}

#include "halfling.h"

Halfling::Halfling(): Character{'L', true, Stats{100, 15, 20, 0}} {}

Halfling::~Halfling() {}

int Halfling::defend(Character &attacker) {
	// 50% chance to do nothing
  srand(time(NULL));
  int n = rand() % 2;
 
  if(n) {
	double damage = attacker.attack(*this);
	status.HP -= damage;
	std::cout << "Owie! " << name << " took " << damage << " damage! ";
	std::cout << status.HP << " wittle HPs left..." << std::endl;
	checkIfDead();
<<<<<<< HEAD
  }
=======
    return damage;
>>>>>>> 608f98f8627be5d626487ba448d8d8d1c2d2998b
}

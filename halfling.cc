#include "halfling.h"

Halfling::Halfling(): Character{'L', true, 100, Stats{100, 15, 20, 0}} {}

Halfling::~Halfling() {}

int Halfling::defend(Character &attacker) {
	// 50% chance to do nothing
  srand(time(NULL));
  int n = rand() % 2;
 
  if(n) {
	double damage = attacker.attack(*this);
	status.HP -= damage;
	//std::cout << "Owie! " << name << " took " << damage << " damage! ";
	//std::cout << status.HP << " wittle HPs left..." << std::endl;
	if (status.HP < 0) status.HP = 0;
	return damage;
  }
  return 0;
}

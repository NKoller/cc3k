#include "character.h"
#include "stats.h"
#include "dwarf.h"
#include "shade.h"

Character::Character(char name, bool canMove, Stats status):
	name{name}, canMove{canMove}, status{status} {}

void Character::attach(Observer *o) {
	if(observers.size()) observers.pop_back();
	observers.emplace_back(o);
}

char Character::getName() {
   return name;
}

Stats Character::getStats() const {
 return status;
}

/*
void Character::setStats(Stats s) {
    status.HP = s.HP;
    status.Atk = s.Atk;
    status.Def = s.Def;
    status.Gold = s.Gold;
}*/

bool Character::moves() {
 return canMove;
}

/*//helper
void change(int &type, const int amt) {
 type += amt;
 if(type < 0) {
   type = 0;
 }
}*/

void Character::checkIfDead() {
	if (status.HP < 0) {
		setState(State::CharacterDied);
		notifyObservers();
		std::cout << "Oh noey! " << name << " died! :(" << std::endl;
	}
}
double Character::calcDamage(int atk, int def) {
	float damage = (100.0 / (100 + def)) * atk;
	int trunc = damage;
	return (damage > trunc)? trunc + 1 : trunc;
}

double Character::attack(Shade &defender) {
	return calcDamage(status.Atk, defender.getStats().Def);
}

double Character::attack(Dwarf &defender) {
	return calcDamage(status.Atk, defender.getStats().Def);
}

Character::~Character() {}

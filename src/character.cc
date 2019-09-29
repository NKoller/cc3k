#include "character.h"
#include "stats.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"
#include "human.h"
#include "dwarf.h"
#include "elf.h"
#include "orc.h"
#include "merchant.h"
#include "halfling.h"

const double Character::MISSED = -1;
const double Character::NO_ATTACK = -2;

Character::Character(char name, bool canMove, int maxHP, Stats status):
		name{name}, canMove{canMove}, maxHP{maxHP}, status{status} {}

		void Character::attach(Observer *o) {
				if (observers.size() > 1) observers.pop_back();
				observers.emplace_back(o);
		}

char Character::getName() {
		return name;
}

Stats Character::getStats() const {
		return status;
}

bool Character::moves() {
		return canMove;
}

void Character::checkIfDead() {
		if (status.HP <= 0) {
				setState(State::CharacterDied);
				notifyObservers();
		}
}

double Character::generalAttack(Character &defender) {
		double damage = (100.0 / (100 + defender.getStats().Def)) * status.Atk;
		int trunc = damage;
		damage = (damage > trunc)? trunc + 1 : trunc;

		int missed = rand() % 2;
		if (missed) return Character::MISSED;
		return damage;
}

double Character::attack(Shade &defender) {
		return generalAttack(defender);
}

double Character::attack(Dwarf &defender) {
		return generalAttack(defender);
}

double Character::attack(Human &defender) {
		return generalAttack(defender);
}

double Character::attack(Elf &defender) {
		return generalAttack(defender);     
}

double Character::attack(Orc &defender) {
		return generalAttack(defender);
}

double Character::attack(Merchant &defender) {
		return generalAttack(defender);
}

double Character::attack(Halfling &defender) {
		return generalAttack(defender);
}

double Character::attack(Drow &defender) {
		return generalAttack(defender);
}

double Character::attack(Vampire &defender) {
		return generalAttack(defender);
}

double Character::attack(Goblin &defender) {
		return generalAttack(defender);
}

double Character::attack(Troll &defender) {
		return generalAttack(defender);
}

Character::~Character() {}

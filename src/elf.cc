#include "elf.h"
#include "drow.h"
#include "character.h"

Elf::Elf(): Character{'E', true, 140, Stats{140, 30, 10, 0}} {}

int Elf::defend(Character &attacker) {
		double damage = attacker.attack(*this);
		if (damage != Character::MISSED && damage != Character::NO_ATTACK) {
				status.HP -= damage;
				if (status.HP < 0) status.HP = 0;
		}
		return damage;
}

double Elf::generalAttack(Character &defender) {
		double damage = (100.0 / (100 + defender.getStats().Def)) * status.Atk;
		int trunc = damage;
		damage = (damage > trunc)? trunc + 1 : trunc;

		double second_damage = Character::NO_ATTACK;
		if (!attacking) {
				attacking = true;
				second_damage = defender.defend(*this);
				if (second_damage != Character::MISSED && second_damage != Character::NO_ATTACK) {
						if (damage != Character::MISSED && damage != Character::NO_ATTACK) {
								damage += second_damage;
						} else {
								damage = second_damage;
						}
				}
		} else {
				attacking = false;
		}

		int missed = rand() % 2;
		if (missed) {
				if (second_damage != Character::NO_ATTACK && second_damage != Character::MISSED) {
						return second_damage;
				}
				return Character::MISSED;
		}
		return damage;
}

double Elf::attack(Drow &defender) {
		attacking = true;
		return generalAttack(defender);
}

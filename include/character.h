#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include "observer.h"
#include "subject.h"
#include "stats.h"
#include <cstdlib> // for rand() and srand()

class Shade;
class Drow;
class Vampire;
class Troll;
class Goblin;
class Human;
class Dwarf;
class Elf;
class Orc;
class Merchant;
class Halfling;
class Potion;

class Character: public Subject {
		char name;
		bool canMove;

	protected:
		const int maxHP;
		Stats status;
		virtual double generalAttack(Character &defender);

	public:
		static const double MISSED;
		static const double NO_ATTACK;
		virtual void checkIfDead();
		Character(char name, bool canMove, int maxHP, Stats status);
		void attach(Observer *o) override;
		bool moves();
		Stats getStats() const;
		char getName();
		virtual int defend(Character &attacker) = 0;
		virtual double attack(Shade &defender);
		virtual double attack(Dwarf &defender);
		virtual double attack(Human &defender);
		virtual double attack(Elf &defender);
		virtual double attack(Orc &defender);
		virtual double attack(Merchant &defender);
		virtual double attack(Halfling &defender);
		//virtual double attack(Dragon &defender);
		virtual double attack(Drow &defender);
		virtual double attack(Vampire &defender);
		virtual double attack(Troll &defender);
		virtual double attack(Goblin &defender);
		virtual ~Character();
};

#endif

#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include "observer.h"
#include "subject.h"
#include "stats.h"
#include <iostream> // REMOVE

class Shade;
class Human;
class Dwarf;
class Elf;
class Orc;
class Merchant;
class Halfling;

class Character: public Subject {
    bool canMove;
	virtual double generalAtk(Character &defender);
protected:
	char name; // should be private, this was just for testing
	Stats status;
public:
	virtual void checkIfDead();
    Character(char name, bool canMove, Stats status);
	void attach(Observer *o) override;
    bool moves();
    Stats getStats() const;
    //void setStats(Stats s);
    char getName();
    virtual int defend(Character &attacker) = 0;
    virtual double attack(Shade &defender);
	virtual double attack(Dwarf &defender);
    virtual double attack(Human &defender);
    virtual double attack(Elf &defender);
    virtual double attack(Orc &defender);
    virtual double attack(Merchant &defender);
    virtual double attack(Halfling &defender);
	/*virtual void attack(Dragon &defender);
    virtual void attack(Drow &defender);
    virtual void attack(Vampire &defender);
    virtual void attack(Troll &defender);
    virtual void attack(Goblin &defender);*/
	virtual ~Character();
};

#endif

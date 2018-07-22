#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include "observer.h"
#include "subject.h"
#include "stats.h"
#include <iostream> // REMOVE

class Dwarf;
class Shade;

class Character: public Subject {
    bool canMove;
	virtual int calcDamage(double atk, double def);
protected:
	char name; // should be private, this was just for testing
	Stats status;
	void checkIfDead();
public:
    Character(char name, bool canMove, Stats status);
	void attach(Observer *o) override;
    bool moves();
    Stats getStats() const;
    //void setStats(Stats s);
    char getName();
    virtual void defend(Character &attacker) = 0;
    virtual double attack(Shade &defender);
	virtual double attack(Dwarf &defender);
  /*virtual void attack(Human &defender);
    virtual void attack(Elf &defender);
    virtual void attack(Orc &defender);
    virtual void attack(Merchent &defender);
    virtual void attack(Dragon &defender);
    virtual void attack(Halfling &defender);
    virtual void attack(Drow &defender);
    virtual void attack(Vampire &defender);
    virtual void attack(Troll &defender);
    virtual void attack(Goblin &defender);*/
	virtual ~Character();
};

#endif

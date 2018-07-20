#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include "observer.h"
#include "subject.h"
#include "stats.h"

class Character: public Subject {
    char name;
    Stats status;
    bool canMove;
public:
    Character(char name, bool canMove, Stats status);
    bool moves();
    Stats getStats();
    //void setStats(Stats s);
    char getName();
    //virtual void defend(Character &attacker);
    //virtual void attack(Shade &defender);

  /*
    virtual void defend(Character &attacker);
    virtual void attack(Human &defender);
    virtual void attack(Dwarf &defender);
    virtual void attack(Elf &defender);
    virtual void attack(Orc &defender);
    virtual void attack(Merchent &defender);
    virtual void attack(Dragon &defender);
    virtual void attack(Halfling &defender);
    virtual void attack(Shade &defender);
    virtual void attack(Drow &defender);
    virtual void attack(Vampire &defender);
    virtual void attack(Troll &defender);
    virtual void attack(Goblin &defender);
   */

   virtual ~Character();
};

#endif

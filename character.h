#ifndef character_h
#define character_h

#include "subject.h"
#include "stats.h"
#include <stdio.h>

class Character: public Subject {
    char name;
    Stats status;
    bool canMove;
public:
    Character(char name);
    void notifyObservers(Stats s);
    bool move();
    Stats getStats();
    virtual void defend(Character &attacker);
    virtual void attack(/*Shade*/ Character &defender);
  
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
 
   ~Character();
    
};

#endif

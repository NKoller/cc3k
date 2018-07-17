ifndef character_h
#define character_h

#include <stdio.h>

class Character: public Subject {
    char name;
public:
    Character(int hp, int atk, int def, int gold, char name);
     Stats status;
    void notifyObservers(Stats S);
    bool move();
    Stats getStats();
    void setStats(Stats s);
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
    ~Character();
    
};

#endif

#ifndef _TEXTDISPLAY_H_
#define _TEXTDISPLAY_H_

#include <iostream>
#include "cell.h"
#include <vector>
#include <string>
#include "direction.h"

class TextDisplay: public Observer {
    std::vector<std::vector <char>> cells;
    int hp, atk, def, gold, floor;
    std::string race;
    std::string actionString;
public:
    void updateFloor (int newFloor);
    void updateRace (std::string newRace);
    void notify(Subject &cell) override;
    TextDisplay(std::string s);
    friend std::ostream &operator<<(std::ostream &out,TextDisplay &td);
    void playerMoved(Direction dir);
};

#endif

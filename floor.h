#ifndef _FLOOR_H_
#define _FLOOR_H_
#include <iostream>
#include <vector>
#include "cell.h"

class Floor {
    struct Coords {
        int r;
        int c;
    };
    static int numFloors;
    const int player;
    const int stairs;
    std::vector<std::vector<Coords>> chambers;
    std::vector<Cell *> cells;
    std::vector<int> doors;
    std::vector<int> enemies;
    void initializeChamber(bool *added[], int chamber_num, unsigned int r, unsigned int c);
    void findChambers();
    std::string readingFile();
    void readingInput(std::string input);
    void spawn();
    void moveEnemies();
    void movePlayer(Direction);
 public:
    Floor();
    ~Floor();
};

#endif

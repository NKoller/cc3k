#ifndef _FLOOR_H_
#define _FLOOR_H_

#include <iostream>
#include <vector>
#include "cell.h"
#include "textdisplay.h"
#include "direction.h"

class Floor {
	struct Coords {
		unsigned int r;
		unsigned int c;
	};
	struct Coords player;
	std::vector<std::vector<Cell *>> map;
	std::vector<std::vector<Coords>> chambers;
	TextDisplay *td;

	static std::string readFile(std::string name);
	void initializeChamber(std::vector<std::vector<bool>> &added,
	                       int chamber_num, unsigned int r, unsigned int c);
	void findChambers();
	void addObsRecurse(std::vector<std::vector<bool>> &added,
	                   unsigned int r, unsigned int c);
	void addObservers();
	void resetProcessed();
	Coords randCoords();
	void spawn();
	void moveEnemies();

public:
	Floor(std::string file);
	~Floor();
	void movePlayer(Direction dir);
	bool gameOver() const;
    void playerAttack(Direction dir);
	friend std::ostream &operator<<(std::ostream &out, const Floor &f);
};

#endif

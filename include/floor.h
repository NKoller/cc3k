#ifndef _FLOOR_H_
#define _FLOOR_H_

#include <iostream>
#include <vector>
#include "cell.h"
#include "textdisplay.h"
#include "direction.h"
#include "player.h"

class Floor {
		struct Coords {
				unsigned int r;
				unsigned int c;
		};
		struct Coords player;
		std::vector<std::vector<Cell *>> map;
		std::vector<std::vector<Coords>> chambers;
		Player* myPlayer;
		static std::string readFile(std::string name, int file_skip);
		void initializeChamber(std::vector<std::vector<bool>> &added,
                               int chamber_num, unsigned int r, unsigned int c);
		void findChambers();
		void addObsRecurse(std::vector<std::vector<bool>> &added,
                           unsigned int r, unsigned int c);
		void addObservers();
		void resetProcessed();
		Coords randCoords();
		void spawnItems();
		void spawnEnemies();
		void spawn();
		void moveEnemies();

	public:
		TextDisplay *td;
		Floor(std::string file, Player* thePlayer, int file_skip = -1);
		~Floor(); 
		bool gameWon() const;
		void movePlayer(Direction dir);
		bool gameLost() const;
		void playerAttack(Direction dir);
		void playerUse(Direction dir);
		void freeze();
	
	friend std::ostream &operator<<(std::ostream &out, const Floor &f);
};

#endif

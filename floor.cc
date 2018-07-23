#include "floor.h"
#include "cell.h"
#include "shade.h"
#include "human.h"
#include "dwarf.h"
#include "elf.h"
#include "orc.h"
#include "merchant.h"
#include "halfling.h"
#include "info.h" // REMOVE
#include <iostream> // REMOOVVVEEEE
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

string Floor::readFile(string name) {
	ifstream file{name};
	stringstream result;
	result << file.rdbuf();
	return result.str();
}

void Floor::initializeChamber(vector<vector<bool>> &added, int chamber_num,
                              unsigned int r, unsigned int c) {
	if (map[r][c] && !added[r][c] && map[r][c]->getType() == CellType::Floor) {
		chambers[chamber_num].emplace_back(Coords{r, c});
		added[r][c] = true;
		for (int i = r-1; i <= r+1 && i < map.size(); ++i) {
			for (int j = c-1; j <= c+1 && j < map[0].size(); ++j) {
				if (!(i == r && j == c) && i >= 0 && j >= 0) {
					initializeChamber(added, chamber_num, i, j);
				}
			}
		}
	}
}

void Floor::findChambers() {
	vector<vector<bool>> added;
	for (unsigned int i = 0; i < map.size(); ++i) {
		added.emplace_back();
		for (unsigned int j = 0; j < map[i].size(); ++j) {
			added[i].emplace_back(false);
		}
	}
	int chamber_num = 0;
	for (unsigned int r = 0; r < map.size(); ++r) {
		for (unsigned int c = 0; c < map[r].size(); ++c) {
			if (map[r][c] && !added[r][c] && map[r][c]->getType() == CellType::Floor) {
				chambers.emplace_back();
				initializeChamber(added, chamber_num, r, c);
				++chamber_num;
			}
		}
	}
}

void Floor::addObsRecurse(vector<vector<bool>> &added,
                          unsigned int r, unsigned int c) {
	if (added[r][c]) return;
	added[r][c] = true;
	for (int i = r-1; i <= r+1; ++i) {
		for (int j = c-1; j <= c+1; ++j) {
			if (i == r && j == c) {
				continue;
			}
			else if (map[i][j] && i >= 0 && j >= 0 && i < map.size() && j < map[0].size()) {
				map[r][c]->attach(map[i][j]);
				addObsRecurse(added, i, j);
			} else {
				map[r][c]->attach(nullptr);
			}
		}
	}
	map[r][c]->attach(td);
}

void Floor::addObservers() {
	vector<vector<bool>> added;
	for (unsigned int i = 0; i < map.size(); ++i) {
		added.emplace_back();
		for (unsigned int j = 0; j < map[i].size(); ++j) {
			added[i].emplace_back(false);
		}
	}
	for (unsigned int r = 0; r < map.size(); ++r) {
		for (unsigned int c = 0; c < map[r].size(); ++c) {
			if (map[r][c]) {
				addObsRecurse(added, r, c);
				return;
			}
		}
	}
}

void Floor::resetProcessed() {
	for (auto &chamber : chambers) {
		for (auto &cell : chamber) {
			map[cell.r][cell.c]->processedThisTurn = false;
		}
	}
}

Floor::Coords Floor::randCoords() {
	int x = rand() % chambers.size();
	auto vec = chambers[x];
	int y;
	do {
		y = rand() % vec.size();
	} while (map[vec[y].r][vec[y].c]->processedThisTurn);
	//map[vec[y].r][vec[y].c]->processedThisTurn = true;
	return vec[y];
}

void Floor::spawnEnemies() {
	enum Order { H, W, L, E, O, M };
	const int num_enemies = 6;
	const int cumulative_prob[] = { 0, 4, 7, 12, 14, 16, 18 };
	for (int i = 0; i < cumulative_prob[num_enemies]; ++i) {
		int rand_int = rand() % cumulative_prob[num_enemies];
		//std::cout << "rand " << rand_int << std::endl;
		for (int type = num_enemies - 1; ; --type) {
			if (rand_int >= cumulative_prob[type]) {
				//std::cout << "type " << type << std::endl;
				Coords rand_coords = randCoords();
				Character *enemy;
				switch (type) {
					case Order::H: enemy = new Human{}; break;
					case Order::W: enemy = new Dwarf{}; break;
					case Order::L: enemy = new Halfling(); break;
					case Order::E: enemy = new Elf{}; break;
					case Order::O: enemy = new Orc{}; break;
					case Order::M: enemy = new Merchant{}; break;
				}
				map[rand_coords.r][rand_coords.c]->addChar(enemy);
				break;
			}
		}
	}
}

void Floor::spawn() {
	resetProcessed();

	int total_cells = 0;
	for (auto &ch : chambers) total_cells += ch.size();
	int rand_num = rand() % total_cells;
	int player_chamber;
	int player_cell;
	for (player_chamber = 0; player_chamber < chambers.size(); ++player_chamber) {
		for (player_cell = 0; player_cell < chambers[player_chamber].size(); ++player_cell) {
			if (rand_num == 0) break;
			--rand_num;
		}
		if (rand_num == 0) break;
	}
	Coords rand_cell = chambers[player_chamber][player_cell];
	player.r = rand_cell.r;
	player.c = rand_cell.c;
	map[rand_cell.r][rand_cell.c]->addChar(new Shade{td}, true);
	map[rand_cell.r][rand_cell.c]->processedThisTurn = true;

	total_cells -= chambers[player_chamber].size();
	rand_num = rand() % total_cells;
	int stairs_chamber;
	int stairs_cell;
	for (stairs_chamber = 0; stairs_chamber < chambers.size(); ++stairs_chamber) {
		if (stairs_chamber == player_chamber) continue;
		for (stairs_cell = 0; stairs_cell < chambers[stairs_chamber].size(); ++stairs_cell) {
			if (rand_num == 0) break;
			--rand_num;
		}
		if (rand_num == 0) break;
	}
	rand_cell = chambers[stairs_chamber][stairs_cell];
	map[rand_cell.r][rand_cell.c]->makeStairs();
	
	spawnEnemies();
}

void Floor::moveEnemies() {
	resetProcessed();
	for (unsigned int r = 0; r < map.size(); ++r) {
		for (unsigned int c = 0; c < map[0].size(); ++c) {
			if (!map[r][c] || r == player.r && c == player.c) continue;
			int dir;
			do {
				//std::cout << r << "move" << c << "  ";
				dir = rand() % 8;
				//std::cout << dir << std::endl;
			} while (!(map[r][c]->moveChar(dir)));
		}
	}
}

Floor::Floor(string file) {
	string input = readFile(file);
	// Initialize 2-D Cell vector
	unsigned int i = 0;
	unsigned int row = 0;
    while(i < input.length()) {
		map.emplace_back();
		unsigned int col = 0;
		while(input[i] != '\n' && i < input.length()) {
			if(input[i] == ' ' || input[i] == '|' || input[i] == '-') {
				map[row].emplace_back(nullptr);
			}
			else if(input[i] == '.') {
				map[row].emplace_back(new Cell{CellType::Floor, row, col});
			}
			else if(input[i] == '+') {
				map[row].emplace_back(new Cell{CellType::Door, row, col});
			}
			else if(input[i] == '#') {
				map[row].emplace_back(new Cell{CellType::Passage, row, col});
			}
			else {
				// throw i/o exception?
			}
			++i;
			++col;
		}
		++i;
		++row;
	}
	// Initialize display
	td = new TextDisplay{input};
	// Initialize chambers and observers
	findChambers();
	addObservers();
	// Span characters and items
	srand(time(nullptr));
	spawn();
}

Floor::~Floor() {
	for (auto &r : map) {
		for (auto &c : r) {
			delete c;
		}
	}
	delete td;
}

void Floor::movePlayer(Direction dir) {
	map[player.r][player.c]->processedThisTurn = false;
	if (map[player.r][player.c]->moveChar(dir)) {
		if (dir == Direction::N){
				player.r -= 1;
		} else if (dir == Direction::S){
				player.r += 1;
		} else if (dir == Direction::E){
				player.c += 1;
		} else if (dir == Direction::W){
				player.c -= 1;
		} else if (dir == Direction::NE){
				player.r -= 1;
				player.c += 1;
		} else if (dir == Direction::NW){
				player.r -= 1;
				player.c -= 1;
		} else if (dir == Direction::SE){
				player.r += 1;
				player.c += 1;
		} else if (dir == Direction::SW){
				player.r += 1;
				player.c -= 1;
		} 
	}
	moveEnemies();
}

bool Floor::gameOver() const {
	return map[player.r][player.c]->getType() == CellType::Stairs;
}

void Floor::playerAttack(Direction dir){
    map[player.r][player.c]->charAttack(dir);
	moveEnemies();
}

ostream &operator<<(ostream &out, const Floor &f) {
	return out << *(f.td);
}

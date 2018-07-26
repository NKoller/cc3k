#include "floor.h"
#include "cell.h"
#include "shade.h"
#include "human.h"
#include "dwarf.h"
#include "elf.h"
#include "orc.h"
#include "merchant.h"
#include "halfling.h"
#include "restoreHP.h"
#include "poisonHP.h"
#include "boostAtk.h"
#include "woundAtk.h"
#include "boostDef.h"
#include "woundDef.h"
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

string Floor::readFile(string name, int file_skip) {
	ifstream file{name};
	stringstream result;
	if (file_skip == -1) {
		result << file.rdbuf();
		return result.str();
	} else {
		int lines_to_skip = file_skip * 25;
		string line;
		for (int i = 0; i < lines_to_skip; ++i) getline(file, line);
		for (int j = 0; j < 25; ++j) {
			getline(file, line);
			result << line << endl;
		}
		return result.str();
	}
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
						if (map[r][c] && !added[r][c] &&
                            map[r][c]->getType() == CellType::Floor) {
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
						else if (map[i][j] && i >= 0 && j >= 0 &&
                                 i < map.size() && j < map[0].size()) {
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
		return vec[y];
}

void Floor::spawnItems() {
		const int num_potions = 6;
		for (int i = 0; i < 10; ++i) {
				int type = rand() % num_potions;
				Coords rand_coords = randCoords();
				Potion *p;
				switch (type) {
						case 0: p = new RestoreHP{}; break;
						case 1: p = new PoisonHP{};  break;
						case 2: p = new BoostAtk{};  break;
						case 3: p = new WoundAtk{};  break;
						case 4: p = new BoostDef{};  break;
						case 5: p = new WoundDef{};  break;
				}
				map[rand_coords.r][rand_coords.c]->addItem(p);
		}
}

void Floor::spawnEnemies() {
		enum Order { H, W, L, E, O, M };
		const int num_enemies = 6;
		const int cumulative_prob[] = { 0, 4, 7, 12, 14, 16, 18 };
		for (int i = 0; i < 20; ++i) {
				int rand_int = rand() % cumulative_prob[num_enemies];
				for (int type = num_enemies - 1; ; --type) {
						if (rand_int >= cumulative_prob[type]) {
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
		map[rand_cell.r][rand_cell.c]->addChar(myPlayer, true);
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

		spawnItems();
		spawnEnemies();
}

void Floor::moveEnemies() {
		resetProcessed();
		for (unsigned int r = 0; r < map.size(); ++r) {
				for (unsigned int c = 0; c < map[0].size(); ++c) {
						if (!map[r][c] || (r == player.r && c == player.c)) continue;
						int counter = 0;
						int dir;
						do {
								dir = rand() % 8;
								++counter;
						} while (!(map[r][c]->moveChar(dir)) && counter < 100);
				}
		}
}

Floor::Floor(string file, Player* thePlayer, int file_skip) {
		string input = readFile(file, file_skip);
		myPlayer = thePlayer;
		// Initialize display
		td = new TextDisplay{input, myPlayer->getStats()};
		myPlayer->attach(td);	
		// Initialize 2-D Cell vector
		unsigned int i = 0;
		unsigned int row = 0;
		while(i < input.length()) {
				map.emplace_back();
				unsigned int col = 0;
				while(input[i] != '\n' && i < input.length()) {
						if (input[i] == ' ' || input[i] == '|' || input[i] == '-') {
								map[row].emplace_back(nullptr);
						} else if (input[i] == '.' || input[i] == '6' || input[i] == '7' ||
						           input[i] == '8' || input[i] == '9' || input[i] == 'D') {
								map[row].emplace_back(new Cell{CellType::Floor, row, col});
						} else if (input[i] == '+') {
								map[row].emplace_back(new Cell{CellType::Door, row, col});
						} else if (input[i] == '#') {
								map[row].emplace_back(new Cell{CellType::Passage, row, col});
						} else if (input[i] == '\\') {
								map[row].emplace_back(new Cell{CellType::Stairs, row, col});
						} else {
								Cell *add = new Cell{CellType::Floor, row, col};
								if (input[i] == '0') {
										add->addItem(new RestoreHP{});
								} else if (input[i] == '1') {
										add->addItem(new BoostAtk{});
								} else if (input[i] == '2') {
										add->addItem(new BoostDef{});
								} else if (input[i] == '3') {
										add->addItem(new PoisonHP{});
								} else if (input[i] == '4') {
										add->addItem(new WoundAtk{});
								} else if (input[i] == '5') {
										add->addItem(new WoundDef{});
								} else if (input[i] == '@') {
										add->addChar(myPlayer, true);
										player.r = row;
										player.c = col;
								} else if (input[i] == 'H') {	
										add->addChar(new Human{});
								} else if (input[i] == 'W') {	
										add->addChar(new Dwarf{});
								} else if (input[i] == 'L') {	
										add->addChar(new Halfling{});
								} else if (input[i] == 'E') {	
										add->addChar(new Elf{});
								} else if (input[i] == 'O') {	
										add->addChar(new Orc{});
								} else if (input[i] == 'M') {	
										add->addChar(new Merchant{});
								}
								map[row].emplace_back(add);
						}
						++i;
						++col;
				}
				++i;
				++row;
		}
		// Initialize chambers and observers
		findChambers();
		addObservers();
		// Spawn characters and items (unless using a premade file)
		srand(time(nullptr));
		if (file_skip == -1) spawn();
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

bool Floor::gameLost() const{
		return map[player.r][player.c]->getChar() == nullptr;
}

bool Floor::gameWon() const {
		return map[player.r][player.c]->getType() == CellType::Stairs;
}

void Floor::playerAttack(Direction dir){
		map[player.r][player.c]->charAttack(dir);
		moveEnemies();
}

void Floor::playerUse(Direction dir) {
		map[player.r][player.c]->charUse(dir);
		moveEnemies();
}

void Floor::freeze() {
		for (auto &r : map) {
				for (auto &c : r) {
						if (c) c->frozen = !(c->frozen);
				}
		}
}

ostream &operator<<(ostream &out, const Floor &f) {
		return out << *(f.td);
}

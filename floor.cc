#include "floor.h"
#include "cell.h"
#include "shade.h"
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

// map[player.row][player.col]myChar.attack(DIRECTION)
//

void Floor::initializeChamber(vector<vector<bool>> &added, int chamber_num,
                              unsigned int r, unsigned int c) {
	if (map[r][c] && !added[r][c] && map[r][c]->getType() == CellType::Floor) {
		chambers[chamber_num].emplace_back(Coords{r, c});
		added[r][c] = true;
		for (unsigned int i = r-1; i <= r+1 && i < map.size(); ++i) {
			for (unsigned int j = c-1; j <= c+1 && j < map[0].size(); ++j) {
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
	for (unsigned int i = r-1; i <= r+1; ++i) {
		for (unsigned int j = c-1; j <= c+1; ++j) {
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

void Floor::spawn() {
	int play_r = 3;
	int play_c = 3;
	map[play_r][play_c]->addChar(new Shade{});
	player.r = play_r;
	player.c = play_c;
}

/*void Floor::playerAttack(Direction dir){
    map[player.r][player.c].attack(dir);    
}*/

void Floor::moveEnemies() {

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
	//cout << "moved <3" << endl;
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
}

bool Floor::gameOver() const {
	return map[player.r][player.c]->getType() == CellType::Stairs;
}

ostream &operator<<(ostream &out, const Floor &f) {
	return out << *(f.td);
}

//#include "floor.h"
#include "cell.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

struct Coords {
	unsigned int r;
	unsigned int c;
};

vector<vector<Cell *>> map;
vector<vector<Coords>> chambers;

void addObsRecurse(vector<vector<bool>> &added, unsigned int r, unsigned int c) {
	if (added[r][c]) return;
	added[r][c] = true;
	for (unsigned int i = r-1; i <= r+1; ++i) {
		for (unsigned int j = c-1; j <= c+1; ++j) {
			if (!(i == r && j == c) &&
			    i >= 0 && j >= 0 &&
			    i < map.size() && j < map[0].size() &&
				map[i][j]) {

				map[r][c]->attach(map[i][j]);
				addObsRecurse(added, i, j);
			} else {
				map[r][c]->attach(nullptr);
			}
		}
	}
	// add text display observer
}

void addObservers() {
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

void initializeChamber(vector<vector<bool>> &added, int chamber_num, unsigned int r, unsigned int c) {
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

void findChambers() {
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

string readingFile() {
    ifstream file {"empty.txt"};
	stringstream result;
    result << file.rdbuf();
	return result.str();
}

void readingInput(string input) {
	unsigned int i = 0;
	unsigned int row = 0;
	unsigned int width = 0;
    while(i < input.length()) {
		map.emplace_back();
		while(input[i] != '\n' && i < input.length()) {
			if(input[i] == ' ' || input[i] == '|' || input[i] == '-') {
				map[row].emplace_back(nullptr);
			}
			else if(input[i] == '.') {
				map[row].emplace_back(new Cell{CellType::Floor, row, i - row*width});
			}
			else if(input[i] == '+') {
				map[row].emplace_back(new Cell{CellType::Door, row, i - row*width});
			}
			else if(input[i] == '#') {
				map[row].emplace_back(new Cell{CellType::Passage, row, i - row*width});
			}
			else {
				// throw i/o exception?
			}
			++i;
		}
		if (!width) width = i;
		++i;
		++row;
	}
}

int main() {
	string f = readingFile();
	readingInput(f);
	findChambers();
	addObservers();
}

//#include "floor.h"
#include "cell.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;
/*
struct Coords {
	int r;
	int c;
};
*/
vector<vector<Cell *>> map;/*
vector<vector<Coords>> chambers;

void initializeChamber(bool *added[], int chamber_num, unsigned int r, unsigned int c) {
	if (map[r][c] && !added[r][c] && map[r][c]->getType() == CellType::Floor) {
		chambers[chamber_num].emplace_back({r, c});
	} else {
		return;
	}
	for (unsigned int i = r-1; i <= r+1 && i < map.size(); ++i) {
		for (unsigned int j = c-1; j <= c+1 && j < map[i].size(); ++j) {
			if (i != j && i >= 0 && j >= 0) {
				initializeChamber(added, chamber_num, i, j);
			}
		}
	}
}

void findChambers() {
	bool added[map.size()][map[0].size()];
	for (auto &r : added) {
		for (auto &c : r) {
			c = false;
		}
	}
	int chamber_num = 0;
	for (unsigned int r = 0; r < map.size(); ++r) {
		for (unsigned int c = 0; c < map[r].size(); ++c) {
			if (map[r][c] && !added[r][c] && map[r][c]->getType() == CellType::Floor) {
				initializeChamber(added, chamber_num, r, c);
				++chamber_num;
			}
		}
	}
}*/

string readingFile() {
    ifstream file {"empty.txt"};
	stringstream result;
    result << file.rdbuf();
	return result.str();
}

void readingInput(string input) {
	unsigned int i = 0;
	unsigned int row = 0;
    while(i < input.length()) {
		map.emplace_back();
		while(input[i] != '\n' && i < input.length()) {
			if(input[i] == ' ' || input[i] == '|' || input[i] == '-') {
				map[row].emplace_back(nullptr);
			}
			else if(input[i] == '.') {
				map[row].emplace_back(new Cell{CellType::Floor});
			}
			else if(input[i] == '+') {
				map[row].emplace_back(new Cell{CellType::Door});
			}
			else if(input[i] == '#') {
				map[row].emplace_back(new Cell{CellType::Passage});
			}
			else {
				// throw i/o exception?
			}
			++i;
		}
		++row;
	}
}

int main() {
	string f = readingFile();
	cout << f << endl;
	readingInput(f);
}

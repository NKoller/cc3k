//#include "floor.h"
#include "cell.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

string readingFile() {
    ifstream file {"empty.txt"};
	stringstream result;
    result << file.rdbuf();
	return result.str();
}

void readingInput(string input) {
    vector<vector<Cell *>> map;
	int i = 0;
	int row = 0;
    while(i < input.length()) {
		map.emplace_back();
		while(input[i] != '\n' && i < input.length()) {
			if(input[i] == ' ' || input[i] == '|' || input[i] == '-') {
				map[row].emplace_back(nullptr);
			}
			else if(input[i] == '.') {
				map[row].emplace_back(new Cell{Cell::Floor});
			}
			else if(input[i] == '+') {
				map[row].emplace_back(new Cell{Cell::Door});
			}
			else if(input[i] == '#') {
				map[row].emplace_back(new Cell{Cell::Passage});
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

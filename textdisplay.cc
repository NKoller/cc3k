#include "textdisplay.h"
#include "info.h"
#include <string>
#include <iostream>

using namespace std;

TextDisplay::TextDisplay(string s){
    unsigned int ind = 0, r = 0;
    cells.emplace_back();
    while (ind < s.size()){
        if (s[ind] == '\n'){
            ++r;
            ++ind;
            cells.emplace_back();
        }
        cells[r].emplace_back(s[ind]);
        ++ind;
    }
}

void TextDisplay::notify(Subject &cell){
	//cout << "NOTIFIED" << endl;
	if (cell.getState() != State::CharacterMoved) return;
	Info in = static_cast<Cell *>(&cell)->getInfo();
    if (in.characterName){
        cells[in.row][in.col] = in.characterName;
    } else if (in.itemName) {
    	cells[in.row][in.col] = in.itemName;
    } else if (in.type == CellType::Floor) {
		cells[in.row][in.col] = '.';
	} else if (in.type == CellType::Passage) {
		cells[in.row][in.col] = '#';
	} else if (in.type == CellType::Door) {
		cells[in.row][in.col] = '+';
	} else {
		cells[in.row][in.col] = '\\';
	}
}

ostream &operator<<(ostream &out, const TextDisplay &td){
    for (unsigned int i = 0; i < td.cells.size(); ++i){
        for (unsigned int j = 0; j < td.cells[i].size(); ++j){
            out << td.cells[i][j];
        }
        out << endl;
    }
	return out;
}

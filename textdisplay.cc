#include "textdisplay.h"
#include "info.h"
#include <string>
#include <iostream>
#include "floor.h"
#include "direction.h"
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
    this->s = "Action: ";
}

void TextDisplay::notify(Subject &cell){
	//cout << "NOTIFIED" << endl;
	Info in = static_cast<Cell *>(&cell)->getInfo();
    if (cell.getState() == State::CharacterMoved){
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
}

void TextDisplay::playerMoved(Direction dir){
    if (s.size() != 8){
        s += "and ";
    }
    s += "PC moves ";
    if (dir == Direction::N){
        s += "North ";
    } else if (dir == Direction::NE){
        s += "Northeast ";
    } else if (dir == Direction::E){
        s += "East ";
    } else if (dir == Direction::SE){
        s += "Southeast ";
    } else if (dir == Direction::S){
        s += "South ";
    } else if (dir == Direction::SW){
        s += "Southwest ";
    } else if (dir == Direction::W){
        s += "West ";
    } else {
        s += "Northwest ";
    }
}

ostream &operator<<(ostream &out, TextDisplay &td){
    for (unsigned int i = 0; i < td.cells.size(); ++i){
        for (unsigned int j = 0; j < td.cells[i].size(); ++j){
            out << td.cells[i][j];
        }
        out << endl;
    }
    td.s.pop_back();
    td.s += ".";
    out << td.s << endl;
	return out;
}

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
    if (cell.getInfo().itemName == 0){
        cells[cell.getInfo().row][cell.getInfo().col] = 
            cell.getInfo().characterName;
    } else {
    cells[cell.getInfo().row][cell.getInfo().col] = 
            cell.getInfo().itemName;
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

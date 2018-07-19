#include "textdisplay.h"
#include <string>
#include <iostream>

using namespace std;
TextDisplay::TextDisplay(string s){
    int ind = 0, r = 0;
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

void TextDisplay::notify(Cell &cell){
    if (cell.getInfo().item_name == 0){
        cells[cell.getInfo().row][cell.getInfo().col] = 
            cell.getInfo().character_name;
    } else {
    cells[cell.getInfo().row][cell.getInfo().col] = 
            cell.getInfo().item_name;
    }
}

ostream &operator<<(ostream &out, const TextDisplay &td){
    for (int i = 0; i < td.cells.size(); ++i){
        for (int j = 0; j < td.cells[i].size(); ++j){
            cout << td.cells[i][j];
        }
        cout << endl;
    }
}

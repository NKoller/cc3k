#include "textdisplay.h"
#include "info.h"
#include <string>
#include <iostream>
#include "floor.h"
#include "direction.h"
#include "stats.h"
#include "character.h"
#include <sstream>
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
    this->actionString = "Action: ";
}

void TextDisplay::updateRace(string newRace){
    race = newRace;
}

void TextDisplay::updateFloor(int newFloor){
    floor = newFloor;
    actionString += "Player Spawned";
    if (floor != 1){
        stringstream ss;
        ss << floor;
        string temp;
        ss >> temp;
        actionString += " on Floor " + temp;
    }
    actionString += "!";
}



void TextDisplay::notify(Subject &subj){
    if (subj.getState() == State::UpdateTextdisplay){
        Stats st = static_cast<Character *>(&subj)->getStats();
        hp = st.HP;
        atk = st.Atk;
        def = st.Def;
        gold = st.Gold;
    }
    
    
    else{
	Info in = static_cast<Cell *>(&subj)->getInfo();
    if (subj.getState() == State::GotAttacked){
        if (actionString.size() != 8){
            actionString += "and ";
        }
        int dmgdlt = in.damageDealt;
        int otherCharHP = in.otherCharHP;
        char otherCharName = in.otherCharName;
        stringstream ss;
        ss << otherCharName;
        string tempys;
        ss >> tempys;
        if (in.otherCharName == '@'){
            string tempS = "PC deals " +to_string(dmgdlt) + " damage to " + in.characterName + 
                " (" + to_string(otherCharHP) + ") ";
            actionString += tempS;
        } else{
            string tempS = tempys + " deals " + to_string(dmgdlt) + " damage to PC ";
            actionString += tempS;
        }
        if (otherCharHP <= 0){
            actionString += "and it died ";
        }
    }
    if (subj.getState() == State::PlayerMoved){
        if (actionString.size() != 8){
        actionString += "and ";
    }
    actionString += "PC moves ";
    if (in.direction == 1){
        actionString += "North ";
    } else if (in.direction == 2){
        actionString += "Northeast ";
    } else if (in.direction == 4){
        actionString += "East ";
    } else if (in.direction == 7){
        actionString += "Southeast ";
    } else if (in.direction == 6){
        actionString += "South ";
    } else if (in.direction == 5){
        actionString += "Southwest ";
    } else if (in.direction == 3){
        actionString += "West ";
    } else {
        actionString += "Northwest ";
    }
    }
    if (subj.getState() == State::CharacterMoved ||
            subj.getState() == State::PlayerHere){
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
}

ostream &operator<<(ostream &out, TextDisplay &td){
    for (unsigned int i = 0; i < td.cells.size(); ++i){
        for (unsigned int j = 0; j < td.cells[i].size(); ++j){
            out << td.cells[i][j];
        }
        out << endl;
    }
    out << "Race: " << td.race << " Gold: " << td.gold << "           Floor " << td.floor 
        << endl;
    out << "HP: " << td.hp << endl;
    out << "Atk: " << td.atk << endl;
    out << "Def: " << td.def << endl;
    if (td.actionString.size() != 8){
    td.actionString.pop_back();
    td.actionString += ".";
    out << td.actionString << endl;
    }
    td.actionString = "Action: ";
	return out;
}

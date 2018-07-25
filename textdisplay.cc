#include "textdisplay.h"
#include "info.h"
#include "stats.h"
#include <string>
#include <iostream>
#include "floor.h"
#include "direction.h"
#include "stats.h"
#include "character.h"
#include <sstream>
using namespace std;

TextDisplay::TextDisplay(string s, Stats status){
		unsigned int ind = 0, r = 0;
		cells.emplace_back();
		while (ind < s.size()){
				if (s[ind] == '\n'){
						++r;
						++ind;
						cells.emplace_back();
				}
				if ('0' <= s[ind] && s[ind] <= '5') s[ind] = 'P';
				if ('6' <= s[ind] && s[ind] <= '9' || s[ind] == 'D') s[ind] = '.';
				cells[r].emplace_back(s[ind]);
				++ind;
		}
		this->actionString = "";
		moveString = "";
		hp = status.HP;
		atk = status.Atk;
		def = status.Def;
		gold = status.Gold;
}

void TextDisplay::updateRace(string newRace){
		race = newRace;
}

void TextDisplay::updateFloor(int newFloor){
		floor = newFloor;
		actionString += "Player spawned ";
		if (floor != 1){
				stringstream ss;
				ss << floor;
				string temp;
				ss >> temp;
				actionString += "on Floor " + temp + " ";
		}
}

void TextDisplay::notify(Subject &subj){
		if (subj.getState() == State::UpdateTextdisplay ||
            subj.getState() == State::CharacterDied){
				Stats st = static_cast<Character *>(&subj)->getStats();
				hp = st.HP;
				atk = st.Atk;
				def = st.Def;
				gold = st.Gold;
		}
		else{
				Info in = static_cast<Cell *>(&subj)->getInfo();
				if (subj.getState() == State::DeclareItem){
						actionString += "and sees ";
						if (in.descrip == ""){
								actionString += "some unknown potion ";
						} else{
								actionString += in.descrip + " ";
						}
				}
				if (subj.getState() == State::ItemUsed){
						if (in.descrip != ""){
								if (actionString.size() != 0 || moveString.size() != 0){
										actionString += "and ";
								}
								actionString += "PC uses " + in.descrip + " ";
						}
				}
				if (subj.getState() == State::GotAttacked){
						if (actionString.size() != 0 || moveString.size() != 0){
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
								if (dmgdlt == Character::MISSED){
										stringstream qq;
										qq << in.characterName;
										string blah;
										qq >> blah;
										actionString += "PC attacks " + blah + " (" + 
										                to_string(otherCharHP) + ") " +  "but misses ";
								} else{
										string tempS = "PC deals " +to_string(dmgdlt) +
										               " damage to " + in.characterName +
										               " (" + to_string(otherCharHP) + ") ";
										actionString += tempS;
								}
						} else{
								string tempS;
								if (dmgdlt == Character::MISSED){
										tempS = tempys + " attacks PC but misses ";
								} else{
										tempS = tempys + " deals " + to_string(dmgdlt) +
										        " damage to PC ";
								}
								actionString += tempS;
						}
						if (otherCharHP <= 0){
								actionString += "and it dies ";
						}
				}
				if (subj.getState() == State::PlayerMoved){
						if (moveString.size() != 0){
								moveString += "and ";
						}
						moveString += "PC moves ";
						if (in.direction == 1){
								moveString += "North ";
						} else if (in.direction == 2){
								moveString += "Northeast ";
						} else if (in.direction == 4){
								moveString += "East ";
						} else if (in.direction == 7){
								moveString += "Southeast ";
						} else if (in.direction == 6){
								moveString += "South ";
						} else if (in.direction == 5){
								moveString += "Southwest ";
						} else if (in.direction == 3){
								moveString += "West ";
						} else {
								moveString += "Northwest ";
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
		out << "Race: " << td.race << " Gold: " << td.gold <<
		       "                         Floor " << td.floor << endl;
		out << "HP: " << td.hp << endl;
		out << "Atk: " << td.atk << endl;
		out << "Def: " << td.def << endl;
		if (td.actionString.size() != 0){
				td.actionString.pop_back();
				td.actionString += ".";
				td.moveString += td.actionString;
		} else if (td.moveString.size() != 0){
				td.moveString.pop_back();
				td.moveString += ".";
		}
		if (td.moveString != ""){
				out << "Action: " << td.moveString << endl;
		} 
		td.moveString = "";
		td.actionString = "";
		return out;
}

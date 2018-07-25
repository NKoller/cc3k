#include <iostream>
#include <string>
#include "floor.h"
#include "player.h"
#include "shade.h"
#include "troll.h"
#include "vampire.h"
#include "drow.h"
#include "goblin.h"
using namespace std;

Direction toDirection(string s) {
	if (s == "no"){
		return Direction::N;
	} else if (s == "so"){
		return Direction::S;
	} else if (s == "ea"){
		return Direction::E;
	} else if (s == "we"){
		return Direction::W;
	} else if (s == "ne"){
		return Direction::NE;
	} else if (s == "nw"){
		return Direction::NW;
	} else if (s == "se"){
		return Direction::SE;
	} else {
		return Direction::SW;
	}	
}

bool playAgainHuh(string s){
    return (s == "Y");
}

bool checkWin(Floor *f, int &floorsBeaten, const int MAX_FLOORS){
    if (f->gameWon()){
        floorsBeaten += 1;
        return (floorsBeaten == MAX_FLOORS);
    }
	
    return false;
}

bool quitPrompt(){
    cout << "Would you like to play again? Y/N" << endl;
    string s;
    cin >> s;
    if (s != "Y" && s != "N") return quitPrompt();
    return playAgainHuh(s);
}

int main(){
    Player* thePlayer;    
	const string file = "empty.txt";
	string s1, s2;
    int floorsBeaten = 0;
    Floor* f;
    const int MAX_FLOORS = 5;
    string theRace;
    while (true){
        while (true){
        cout << "Pick a race: s/d/v/g/t (q to quit)" << endl;
        cin >> s1;
        if (s1 != "s" && s1 != "d" && s1 != "v" && s1 != "g" && s1 != "t" && s1 != "q"){
            continue;
        }
        else {
         if (s1 == "s"){
            theRace = "Shade";
            thePlayer = new Shade();
		} else if (s1 == "d"){
            theRace = "Drow";
            thePlayer = new Drow();
		} else if (s1 == "v"){
            theRace = "Vampire";
            thePlayer = new Vampire();
		} else if (s1 == "g"){
            theRace = "Goblin";
            thePlayer = new Goblin();
		} else if (s1 == "t"){
            theRace = "Troll";
            thePlayer = new Troll();
		}
         else if (s1 == "q") return 0;
         break;
        }
        } 
                f = new Floor{file, thePlayer}; 
                floorsBeaten = 0;
                f->td->updateFloor(floorsBeaten + 1);
                f->td->updateRace(theRace);
	while (true){
		cout << *f;
		cin >> s1;
		if (s1 == "q"){
                delete f;
                delete thePlayer;
                if (quitPrompt()){
                break;
            }
            return 0;
		}
		if (s1 == "no"){
            f->movePlayer(Direction::N);
		} else if (s1 == "so"){
            f->movePlayer(Direction::S);
		} else if (s1 == "ea"){
            f->movePlayer(Direction::E);
		} else if (s1 == "we"){
            f->movePlayer(Direction::W);
		} else if (s1 == "ne"){
            f->movePlayer(Direction::NE);
		} else if (s1 == "nw"){
            f->movePlayer(Direction::NW);
		} else if (s1 == "se"){
            f->movePlayer(Direction::SE);
		} else if (s1 == "sw"){
            f->movePlayer(Direction::SW);
		} else if (s1 == "f"){
            f->freeze();
		} else if (s1 == "r"){
            delete f;
            delete thePlayer;
            break;
        } else if (s1 == "u"){
            cin >> s2;
			f->playerUse(toDirection(s2));
        } else if (s1 == "a"){
            cin >> s2;
            f->playerAttack(toDirection(s2));
        }
        if (f->gameLost()){
            delete f;
            if (quitPrompt()){
                break;
            }
            return 0;
        }
        if (f->gameWon()){
			floorsBeaten += 1;
            f->td->updateFloor(floorsBeaten + 1);
			if (floorsBeaten == MAX_FLOORS){
                cout << "Congratulations! Your score is: " << thePlayer->getScore() << " points!" << endl;
                    delete f;
                    delete thePlayer;
                    if (quitPrompt()){
                   	break;
               	}
				return 0;
			}
            thePlayer->reversePotions();
            thePlayer->clearObservers();
			f = new Floor{file, thePlayer};
            f->td->updateFloor(floorsBeaten + 1);
        }
        thePlayer->finishTurn();
    }

    }
}

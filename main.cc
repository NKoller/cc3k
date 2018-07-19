#include <iostream>
#include <string>
#include "floor.h"
using namespace std;

bool playAgainHuh(string s){
    return (s == "Y");
}

bool checkWin(Floor *f, int &floorsBeaten, const int MAX_FLOORS){
    if (f->gameOver()){
        floorsBeaten += 1;
        return (floorsBeaten == MAX_FLOORS);
    }
    return false;
}
bool quitPrompt(){
    cout << "Would you like to play again? Y/n" << endl;
    string s;
    cin >> s;
    return playAgainHuh(s);
}

int main(){
	string s1, s2;
    Floor *f = new Floor("empty.txt");
    const int MAX_FLOORS = 5;
    int floorsBeaten = 0;
	while (true){
		cin >> s1;
		if (s1 == "q"){
			cout << "quit" << endl;
            if (quitPrompt()){
                delete f; 
                f = new Floor("empty.txt"); 
                floorsBeaten = 0;
                continue;
            } //needs more
            break;
		}
		if (s1 == "no"){
            f->movePlayer(Direction::N);
		}	else if (s1 == "so"){
            f->movePlayer(Direction::S);
		}	else if (s1 == "ea"){
            f->movePlayer(Direction::E);
		}	else if (s1 == "we"){
            f->movePlayer(Direction::W);
		}	else if (s1 == "ne"){
            f->movePlayer(Direction::NE);
		}	else if (s1 == "nw"){
            f->movePlayer(Direction::NW);
		}	else if (s1 == "se"){
            f->movePlayer(Direction::SE);
		}	else if (s1 == "sw"){
            f->movePlayer(Direction::SW);
		}	else if (s1 == "s"){
            cout << s1 << endl;
			continue;
		}	else if (s1 == "d"){
            cout << s1 << endl;
			continue;
		}	else if (s1 == "v"){
            cout << s1 << endl;
			continue;
		}	else if (s1 == "g"){
            cout << s1 << endl;
			continue;
		}	else if (s1 == "t"){
            cout << s1 << endl;
			continue;
		}	else if (s1 == "f"){
            cout << s1 << endl;
			continue;
		}	else if (s1 == "r"){
            cout << s1 << endl;
        }   else if (s1 == "u"){
            cin >> s2;
            cout << s1 << " " << s2 << endl;
        }   else if (s1 == "a"){
            cin >> s2;
            cout << s1 << " " << s2 << endl;
        }
        if (checkWin(f, floorsBeaten, MAX_FLOORS)){
                if (quitPrompt()){
                    delete f;
                    f = new Floor("empty.txt");
                    floorsBeaten = = 0;
                    contiinue;
                }
                break;
            }
    }
}

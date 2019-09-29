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
		cout << "Would you like to play again? (y/n)" << endl;
		string s;
		cin >> s;
		if (s == "y") s = "Y";
		else if (s == "n") s = "N";

		if (s != "Y" && s != "N") return quitPrompt();
		return playAgainHuh(s);
}

int main(int num_args, char *args[]) {
		if (num_args > 2) {
				cerr << "Format:  cc3k  OR  cc3k [inputfile]" << endl;
				return 1;
		}
		string file;
		if (num_args == 2) file = args[1];
		else file = "maps/empty.txt";

		Player *thePlayer;
		string s1, s2;
		int floorsBeaten = 0;
		Floor* f;
		const int MAX_FLOORS = 5;
		string theRace;
		while (true){
				while (true){
						cout << "Pick a race: s/d/v/g/t (q to quit)" << endl;
						cin >> s1;
						if (s1 != "s" && s1 != "d" && s1 != "v" &&
						    s1 != "g" && s1 != "t" && s1 != "q"){
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
				floorsBeaten = 0;
				if (num_args == 1) f = new Floor{file, thePlayer};
				else f = new Floor{file, thePlayer, floorsBeaten};
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
                                floorsBeaten = 0;
								break;
						} else if (s1 == "u"){
								cin >> s2;
								f->playerUse(toDirection(s2));
						} else if (s1 == "a"){
								cin >> s2;
								f->playerAttack(toDirection(s2));
						}
						if (f->gameLost()){
								cout << *f;
								delete f;
								cout << "GAME OVER: You died!" << endl;
								if (quitPrompt()){
										break;
								}
								return 0;
						}
						if (f->gameWon()){
								floorsBeaten += 1;
								f->td->updateFloor(floorsBeaten + 1);
								if (floorsBeaten == MAX_FLOORS){
										cout << "GAME OVER: Your score is: " <<
										        thePlayer->getScore() << " points!" << endl;
										delete f;
										delete thePlayer;
										if (quitPrompt()){
												break;
										}
										return 0;
								}
								thePlayer->reversePotions();
								thePlayer->clearObservers();
								delete f;
								if (num_args == 1) f = new Floor{file, thePlayer};
								else f = new Floor{file, thePlayer, floorsBeaten};
								f->td->updateFloor(floorsBeaten + 1);
						}
						thePlayer->finishTurn();
				}

		}
}

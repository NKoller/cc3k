#include "player.h"

void Player::finishTurn() {}

Player::Player(Stats status, Observer* myTD): Character{'@', true, status} {
    this->attach(myTD);
    setState(State::UpdateTextdisplay);
    notifyObservers();
}

Player::~Player() {} 

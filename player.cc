#include "player.h"

void Player::finishTurn() {}

Player::Player(Stats status): Character{'@', true, status} {}

Player::~Player() {} 

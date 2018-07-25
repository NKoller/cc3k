#include "player.h"
#include "potion.h"

void Player::finishTurn() {}

void Player::use(Potion &p) {
	status += p.getEffect();
	if (status.HP > maxHP) status.HP = maxHP;
	used.emplace_back(&p);
	setState(State::UpdateTextdisplay);
	notifyObservers();
}

double Player::generalAttack(Character &defender) {
    double damage = (100.0 / (100 + defender.getStats().Def)) * status.Atk;
	int trunc = damage;
	return (damage > trunc)? trunc + 1 : trunc;
}

void Player::reversePotions() {
	while (used.size()) {
		status += used[used.size()-1]->reverse();
		delete used[used.size()-1];
		used.pop_back();
	}
}

int Player::getScore() const { return status.Gold; }

Player::Player(int maxHP, Stats status, Observer* myTD): Character{'@', true, maxHP, status} {
    this->attach(myTD);
    setState(State::UpdateTextdisplay);
    notifyObservers();
}

Player::~Player() {
	for (auto &pot : used) {
		delete pot;
	}
}

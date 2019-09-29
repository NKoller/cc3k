#include "player.h"
#include "potion.h"

void Player::finishTurn() {}

void Player::use(Potion &p) {
		status += p.getEffect();
		if (status.HP > maxHP) status.HP = maxHP;
		else if (status.HP < 0) status.HP = 0;
		if (status.Atk < 0) status.Atk = 0;
		if (status.Def < 0) status.Def = 0;
		if (status.Gold < 0) status.Gold = 0;
		reverse += p.reverse();
		setState(State::UpdateTextdisplay);
		notifyObservers();
		checkIfDead();
}

double Player::generalAttack(Character &defender) {
		double damage = (100.0 / (100 + defender.getStats().Def)) * status.Atk;
		int trunc = damage;
		return (damage > trunc)? trunc + 1 : trunc;
}

void Player::reversePotions() {
		status += reverse;
		reverse = Stats{0, 0, 0, 0};
}

int Player::getScore() const { return status.Gold; }

Player::Player(int maxHP, Stats status): Character{'@', true, maxHP, status} {}

Player::~Player() {}

void Player::clearObservers(){
		while (observers.size()) {
				observers.pop_back();
		}
}

#include "player.h"
#include "potion.h"

void Player::finishTurn() {}

void Player::use(Potion &p) {
	status += p.getEffect();
	if (status.HP > maxHP) status.HP = maxHP;
<<<<<<< HEAD
    reverse += p.reverse();
=======
	Potion *copy = new Potion{p};
	used.emplace_back(copy);
>>>>>>> 36f1dc50361829d0bb646ee1751abcdf81b8792f
	setState(State::UpdateTextdisplay);
	notifyObservers();
}

double Player::generalAttack(Character &defender) {
    double damage = (100.0 / (100 + defender.getStats().Def)) * status.Atk;
	int trunc = damage;
	return (damage > trunc)? trunc + 1 : trunc;
}

void Player::reversePotions() {
    status += reverse;
}

int Player::getScore() const { return status.Gold; }

Player::Player(int maxHP, Stats status): Character{'@', true, maxHP, status} {}

Player::~Player() {}

void Player::clearObservers(){
    while (observers.size()) {
        observers.pop_back();
    }
}

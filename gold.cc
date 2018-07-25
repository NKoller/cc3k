#include "gold.h"

double Gold::randomPile() {
		int rpile =  1 + rand() % 2;
		return rpile;
}

Gold::Gold(double pile): pile{pile} {}

void Gold::getUsed(Player &user) {
		user.setGold(pile);
}

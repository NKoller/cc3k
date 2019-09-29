#include "gold.h"

double Gold::randomPile() {
		int rpile =  1 + rand() % 2;
		return rpile;
}

void getUsed(Player &user) {
		//user.use(*this);
}

Gold::Gold(double pile): pile{pile} {}

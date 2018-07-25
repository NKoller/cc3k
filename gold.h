#ifndef _GOLD_H_
#define _GOLD_H_

#include "item.h"
#include "player.h"

class Gold: public Item {
		double pile; 
	public:
		static double randomPile();
		Gold(double pile);
		void getUsed(Player &user);
};

#endif

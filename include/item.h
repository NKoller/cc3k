#ifndef _ITEM_H_
#define _ITEM_H_

#include "stats.h"
#include "player.h"
#include <string>

class Item {
		char name;
		Stats effect;
		virtual void getUsed(Player &user) = 0;

	protected:
		std::string desc;

	public:
		Item(char name, std::string desc, Stats s);
		char getName() const;
		virtual std::string getDesc() const;
		Stats getEffect() const;
		void getUsed(Character &user);
};

#endif

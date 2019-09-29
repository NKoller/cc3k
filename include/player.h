#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "character.h"

class Player: public Character {
	
	protected:
		Stats reverse = Stats{0, 0, 0, 0};
		virtual double generalAttack(Character &defender) override;

	public:
		virtual void use(Potion &p);
		//virtual void use(Gold &g);
		void reversePotions();
		virtual void finishTurn();
		virtual int getScore() const;
		Player(int maxHP, Stats status);
		virtual ~Player();
		void clearObservers();
};

#endif

#include "stats.h"

Stats &Stats::operator+=(Stats &other) {
	this->HP   += other.HP;
	this->Atk  += other.Atk;
	this->Def  += other.Def;
	this->Gold += other.Gold;
	return *this;
}

Stats &Stats::operator+=(Stats &&other) {
	this->HP   += other.HP;
	this->Atk  += other.Atk;
	this->Def  += other.Def;
	this->Gold += other.Gold;
	return *this;
}

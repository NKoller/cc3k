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

Stats &Stats::operator*(int n) {
	this->HP   *= n;
	this->Atk  *= n;
	this->Def  *= n;
	this->Gold *= n;
	return *this;
}

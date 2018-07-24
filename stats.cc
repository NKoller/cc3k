#include "stats.h"

Stats Stats::operator-(Stats &&other) {
	Stats result;
	result.HP   = HP   - other.HP;
	result.Atk  = Atk  - other.Atk;
	result.Def  = Def  - other.Def;
	result.Gold = Gold - other.Gold;
	return result;
}

Stats &Stats::operator+=(Stats &&other) {
	this->HP   += other.HP;
	this->Atk  += other.Atk;
	this->Def  += other.Def;
	this->Gold += other.Gold;
	return *this;
}

Stats Stats::operator*(int n) {
	Stats result;
	result.HP   = HP   * n;
	result.Atk  = Atk  * n;
	result.Def  = Def  * n;
	result.Gold = Gold * n;
	return result;
}

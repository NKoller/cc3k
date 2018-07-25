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

Stats Stats::operator*(double n) {
		Stats result;
		result.HP   = HP   * n;
		result.Atk  = Atk  * n;
		result.Def  = Def  * n;
		result.Gold = Gold * n;
		return result;
}

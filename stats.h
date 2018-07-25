#ifndef stats_h
#define stats_h

struct Stats {
		double HP;
		double Atk;
		double Def;
		double Gold;
		Stats &operator+=(Stats &other);
		Stats &operator+=(Stats &&other);
		Stats operator*(double n);
};

#endif

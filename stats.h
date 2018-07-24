#ifndef stats_h
#define stats_h

#include <stdio.h>

struct Stats {
    double HP;
    double Atk;
    double Def;
    double Gold;
	Stats &operator+=(Stats &&other);
	Stats operator*(int n);
};

#endif

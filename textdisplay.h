#ifndef _TEXTDISPLAY_H_
#define _TEXTDISPLAY_H_

#include <iostream>
#include "cell.h"
#include <vector>

class TextDisplay{
    std::vector<std::vector <char>> cells;
    public:
        void notify(Cell &cell);
        TextDisplay(std::string s);
        friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

#endif

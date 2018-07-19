#ifndef _TEXTDISPLAY_H_
#define _TEXTDISPLAY_H_

#include <iostream>
#include "cell.h"
#include <vector>

class TextDisplay: public Observer {
    std::vector<std::vector <char>> cells;
public:
    void notify(Subject &cell) override;
    TextDisplay(std::string s);
    friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

#endif

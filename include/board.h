#ifndef BOARD_H
#define BOARD_H

#include "cannon.h"
#include "counter.h"
#include "nail.h"
#include <vector>

class Board {
private:
    std::vector<Obstacle*> obstacles; // Stores all obstacles(clous e compteurs)
    std::vector<Counter*> counters;   // Counter for last lvl
    Cannon cannon;                    // Thrower
    Obstacle* terminalCounter;        // terminal Counter

public:
    Board(int numCounters);           // Constructor by counters value
    ~Board();                         // Destructor
    void simulate(int numPallets); 
};

#endif

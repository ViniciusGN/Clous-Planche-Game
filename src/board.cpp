#include "board.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

Board::Board(int numCounters) {
    std::srand(std::time(0)); 

    terminalCounter = new Counter();
    obstacles.push_back(terminalCounter);

    for (int i = 0; i < numCounters; i++) {
        Counter* counter = new Counter();
        counters.push_back(counter);
        obstacles.push_back(counter);
    }

    std::vector<Obstacle*> previousLevel(counters.begin(), counters.end());
    for (int level = numCounters - 1; level > 0; level--) {
        std::vector<Obstacle*> currentLevel;
        for (int i = 0; i < level; i++) {
            Nail* nail = new Nail(previousLevel[i], previousLevel[i + 1]);
            currentLevel.push_back(nail);
            obstacles.push_back(nail);
        }
        previousLevel = currentLevel;
    }
}

Board::~Board() {
    for (Obstacle* obstacle : obstacles) {
        if (obstacle->isOrphan) {
            delete obstacle;
        }
    }
}

void Board::simulate(int numPallets) {
    for (int i = 0; i < numPallets; i++) {
        cannon.launch(obstacles.back()); 
    }

    // Display the results
    int c0 = counters[0]->getCount();

    if (c0 > 0) {
        std::cout << "Normalized binomial coefficients:\n";
        for (size_t i = 0; i < counters.size(); i++) {
            int ci = counters[i]->getCount();
            double ratio = static_cast<double>(ci) / c0; 
            double roundedRatio = (ratio > 0) ? (ratio + 0.5) : (ratio - 0.5); 
            std::cout << "round(" << i+1 << "): " << static_cast<int>(roundedRatio) << std::endl;
        }
    } else {
        std::cout << "No pallets reached the counters to display coefficients." << std::endl;
    }
}
#include "board.h"
#include <iostream>

int main() {
    int numCounters, numPallets;

    std::cout << "Enter the number of counters: ";
    std::cin >> numCounters;
    std::cout << "Enter the number of discs to be launched: ";
    std::cin >> numPallets;

    Board board(numCounters);
    board.simulate(numPallets);

    return 0;
}

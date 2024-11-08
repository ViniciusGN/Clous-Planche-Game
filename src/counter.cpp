#include "counter.h"

void Counter::receivePallet(int depth) {
    count++; // Increment the counter
}

int Counter::getCount() const {
    return count;
}

void Counter::reset() {
    count = 0;
}

#include "nail.h"
#include <cstdlib>

Nail::Nail(Obstacle* left, Obstacle* right)
    : leftSuccessor(left), rightSuccessor(right) {
    if (left && left->isOrphan) {
        left->setOrphan(false);
    }
    if (right && right->isOrphan) {
        right->setOrphan(false);
    }
}

void Nail::receivePallet(int depth) {
    // Choose direction randomly
    int direction = std::rand() % 2;
    if (direction == 0 && leftSuccessor) {
        leftSuccessor->receivePallet(depth + 1);
    } else if (rightSuccessor) {
        rightSuccessor->receivePallet(depth + 1);
    }
}

Nail::~Nail() {
    if (leftSuccessor && leftSuccessor->isOrphan) {
        delete leftSuccessor;
    }
    if (rightSuccessor && rightSuccessor->isOrphan) {
        delete rightSuccessor;
    }
}

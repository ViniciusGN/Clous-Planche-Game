#ifndef NAIL_H
#define NAIL_H

#include "Obstacle.h"

class Nail : public Obstacle {
private:
    Obstacle* leftSuccessor;
    Obstacle* rightSuccessor;

public:
    Nail(Obstacle* left, Obstacle* right);
    void receivePallet(int depth) override;
    ~Nail();
};

#endif

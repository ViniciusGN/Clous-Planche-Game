#ifndef COUNTER_H
#define COUNTER_H

#include "obstacle.h"

class Counter : public Obstacle {
private:
    int count = 0;

public:
    void receivePallet(int depth) override;
    int getCount() const;
    void reset();
};

#endif
#ifndef OBSTACLE_H
#define OBSTACLE_H

class Obstacle {
public:
    bool isOrphan = true;                      // Flag to indicate if the object is orphan
    virtual void receivePallet(int depth) = 0; // Pure virtual function for polymorphism
    virtual ~Obstacle() = default;             // Virtual destructor
    void setOrphan(bool orphanStatus) { isOrphan = orphanStatus; }
};

#endif
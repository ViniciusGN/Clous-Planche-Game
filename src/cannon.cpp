#include "cannon.h"

void Cannon::launch(Obstacle* firstObstacle) {
    if (firstObstacle) {
        firstObstacle->receivePallet(0); // Initial depth is 0
    }
}
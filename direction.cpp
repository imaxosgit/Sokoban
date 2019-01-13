#include "direction.h"

Direction directions[DIRS] = {
    Direction(0, -1, 'w'),
    Direction(0, 1, 's'),
    Direction(-1, 0, 'a'),
    Direction(1, 0, 'd')
};

Direction::Direction(int _dx, int _dy, char _key) {
    dx = _dx;
    dy = _dy;
    key = _key;
}

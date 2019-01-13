#ifndef DIRECTION_H
#define DIRECTION_H

class Direction {
    int dx, dy;
    char key;
public:
    Direction(int _dx, int _dy, char _key);
    int getDx() const { return dx; }
    int getDy() const { return dy; }
    char getKey() const { return key; }
};
const int DIRS = 4;
extern Direction directions[DIRS];
#endif // DIRECTION_H

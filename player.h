#ifndef PLAYER
#define PLAYER
class Board;
class Player {
    int x, y;
    Board *board;
public:
    Player(Board *myBoard);
    void step();
    void setPosition(int _x, int _y);
    bool isHere(int _x, int _y) const;
};

#endif // PLAYER


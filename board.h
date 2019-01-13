#ifndef BOARD
#define BOARD
#include "cell.h"
#include "wall.h"
#include <iostream>
#include <fstream>
#include <set>
#include "player.h"
#include "direction.h"
using namespace std;

const int SIZE = 20;

class Board {
private:
    Cell *cells[SIZE][SIZE];
    int rows, cols;
    set<pair<int,int> > boxes;
    Player player;
public:
    Board();
    bool checkVictory() const;
    void moveBox(int x, int y, const Direction &dir);
    void playerStep() { player.step(); }
    bool isLegal(int x, int y) const;
    bool containsPlayer(int x, int y) const;
    bool containsBox(int x, int y) const;
    void load(char *filename);
    void printBoard() const;
    Cell *getCell(int x, int y) const;
};

#endif // BOARD


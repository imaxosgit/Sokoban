#include "player.h"
#include "board.h"
#include "direction.h"

Player::Player(Board *myBoard) {
    board = myBoard;
    x = 0;
    y = 0;
}

void Player::setPosition(int _x, int _y) {
    if(board->isLegal(_x, _y)) {
        x = _x;
        y = _y;
    }
    else throw "incorrect move";
}

bool Player::isHere(int _x, int _y) const {
    return x == _x && y == _y;
}

void Player::step() {
    char in = getchar();
    for(int i = 0; i < DIRS;i++) {
        int cellX, cellY;
        Direction &dir = directions[i];
        cellX = x + dir.getDx();
        cellY = y + dir.getDy();
        if(in == dir.getKey() && board->isLegal(cellX, cellY) &&
            !board->getCell(cellX, cellY)->isBlocked() && !board->containsBox(cellX, cellY))
            setPosition(cellX, cellY);
        int newBoxX = cellX + dir.getDx();
        int newBoxY = cellY + dir.getDy();
        if(in == dir.getKey() && board->containsBox(cellX, cellY) && board->isLegal(newBoxX, newBoxY) &&
                !board->getCell(newBoxX, newBoxY)->isBlocked() &&
                !board->containsBox(newBoxX, newBoxY)) {
            setPosition(cellX, cellY);
            board->moveBox(cellX, cellY, dir);
        }
    }
}

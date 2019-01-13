#include "board.h"
#include "emptycell.h"
#include "boxspot.h"

Board::Board() : player(this) {
    rows = 0;
    cols = 0;

}

void Board::load(char *filename) {
    ifstream f(filename, ifstream::in);
    f >> rows >> cols;
    for(int y = 0; y < rows; y++)
        for(int x = 0; x < cols; x++) {
            char obj; 
            do { 
                obj = f.get();
                if(obj == EOF) throw "premature end of file";
                if(obj == '#')
                    cells[x][y] = new Wall();
                else if(obj == 'p' || obj == ' ' || obj == 'b' || obj == '_')
                    cells[x][y] = new EmptyCell();
                else if(obj == 'P' || obj == ':' || obj == 'B')
                    cells[x][y] = new BoxSpot();
                else continue;
                if(obj == 'B' || obj == 'b')
                    boxes.insert(pair<int,int>(x,y));
                else if(obj == 'P' || obj == 'p')
                    player.setPosition(x, y);
                break;
            } while (true);
        }
    f.close();
}


void Board::printBoard() const {
    for(int y = 0; y < rows; y++) {
        for(int x = 0; x < cols; x++)
            if(containsBox(x, y))
                cout << (cells[x][y]->isUpperCase() ? 'B' : 'b');
            else if(containsPlayer(x, y))
                cout << (cells[x][y]->isUpperCase() ? 'P' : 'p');
            else
                cout << getCell(x, y)->getSymbol();
        cout << endl;
    }
    cout << "-------------------------------" << endl;
}

bool Board::containsBox(int x, int y) const {
    if(boxes.find(pair<int,int>(x,y)) != boxes.end()) return true;
    else return false;
}

bool Board::containsPlayer(int x, int y) const {
    return player.isHere(x, y);
}

Cell *Board::getCell(int x, int y) const {
    if(!isLegal(x, y)) throw "out of range";
    return cells[x][y];
}

bool Board::isLegal(int x, int y) const {
    return x < cols && x >= 0 && y < rows && y >= 0;
}

void Board::moveBox(int x, int y, const Direction &dir) {
    int nx = x + dir.getDx();
    int ny = y + dir.getDy();
    boxes.erase(pair<int, int>(x, y));
    boxes.insert(pair<int, int>(nx, ny));
}

bool Board::checkVictory() const {
    int totalInPlace = 0;
    for(set<pair<int, int> >::const_iterator it = boxes.begin(); it != boxes.end(); it++) {
        if(getCell(it->first, it->second)->isBoxSpot())
            totalInPlace++;
    }
    if(totalInPlace == boxes.size()) {
        cout << "VICTORY!" << endl;
        return true;
    }
    else return false;

}

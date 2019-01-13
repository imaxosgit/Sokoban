#ifndef WALL
#define WALL

class Wall : public Cell {
public:
    virtual char getSymbol() const { return '#'; }
    virtual bool isUpperCase() const { throw "in the wall"; }
    virtual bool isBlocked() const { return true; }
    virtual bool isBoxSpot() const { return false; }
};

#endif // WALL


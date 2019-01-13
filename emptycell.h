#ifndef EMPTYCELL
#define EMPTYCELL

class EmptyCell : public Cell {
    virtual char getSymbol() const { return ' '; }
    virtual bool isUpperCase() const { return false; }
    virtual bool isBlocked() const { return false; }
    virtual bool isBoxSpot() const { return false; }
};

#endif // EMPTYCELL


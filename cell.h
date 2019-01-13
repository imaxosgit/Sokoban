#ifndef CELL
#define CELL

class Cell {
public:
    virtual char getSymbol() const = 0;
    virtual bool isUpperCase() const = 0;
    virtual bool isBlocked() const = 0;
    virtual bool isBoxSpot() const = 0;
};

#endif // CELL


#ifndef BOXSPOT
#define BOXSPOT

class BoxSpot : public EmptyCell {
    virtual char getSymbol() const { return ':'; }
    virtual bool isUpperCase() const { return true; }
    virtual bool isBoxSpot() const { return true; }
};

#endif // BOXSPOT


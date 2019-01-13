#ifndef FILEHANDLER
#define FILEHANDLER
#include "board.h"

class FileHandler {
private:
    char *filename;
public:
    FileHandler(Board &board, int argc, char *argv[]);
    void setFilename(int argc, char *argv[]);
  //  Board *readFile() const;
};

#endif // FILEHANDLER


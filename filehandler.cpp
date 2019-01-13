#include "filehandler.h"
#include <fstream>
using namespace std;

FileHandler::FileHandler(Board &board, int argc, char *argv[]) {
    setFilename(argc, argv);
    board.load(filename);
}

void FileHandler::setFilename(int argc, char *argv[]) {
    if(argc < 2) throw "level file is required in argument"; 
    filename = argv[1];
}

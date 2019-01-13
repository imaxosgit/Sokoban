#include <QCoreApplication>
#include "board.h"
#include <time.h>
#include <stdlib.h>
#include "filehandler.h"

int main(int argc, char *argv[])
{
    srand(time(0));
    try {
        Board b;
        FileHandler fh(b,argc, argv);
        while(!b.checkVictory()) {
            b.printBoard();
            b.playerStep();
        }
    }
    catch(char const *message) {
        cout << message << endl;
        return -1;
    }

    return 0;
}


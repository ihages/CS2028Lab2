#include "BballPlayer.h"
#include <string>
#include <ctime>


// funtions
bool BballPlayer::PassBall() {

    double passPercentage = 100.00 * static_cast<double> (passesMade) / static_cast<double>(passesAttempted);
    // return value regards to if a pass was successful or not
    // pulls a random number between 1-100 and if % > passesmade/passes attempted

    double difficulty = rand() % 101;

    incPasAtt();

    if (difficulty < passPercentage) {
        incPasMade();
        return true;
    } else {
        return false;
    }
}

int BballPlayer::TakeShot(int point) {

    double shotPerc = 100 * static_cast<double>(shotsMade) / shotsTaken;
    incShtTake();

    if (point == 3) {
        int randNum = (rand() % 71);
        if (shotPerc > randNum) {
            //std::cout << "made 3 point" << std::endl;
            incShtMade();
            return point;
        }
    }
    else if (point == 2) {
        int randNum = (rand() % 101);
        if (shotPerc > randNum) {
            //std::cout << "made 2 point" << std::endl;
            incShtMade();
            return point;
        }
    }
    else if (point == 1) {
        int randNum = (rand() % 126);
        if (shotPerc > randNum) {
            //std::cout << "made 1 point" << std::endl;
            incShtMade();
            return point;
        }
    }
    else {
        return 0;
    }
    return 0;
    }
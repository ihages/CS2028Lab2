#include "BballPlayer.h"
#include <string>
#include <ctime>


/*
Function: 
	PassBall - 
Input:
    None
Goal: 
	Decide whether on not the given pass was made,
    the chance is decided on the players passes made / the number of passes attempted,
    if the random number is lower that the calculated pass percentage then the pass is successful
Returns:
	true if the pass is made, false if the pass is not made
*/
bool BballPlayer::PassBall() {

    double passPercentage = 100.00 * static_cast<double> (passesMade) / static_cast<double>(passesAttempted);
    // return value regards to if a pass was successful or not
    // pulls a random number between 1-100 and if % > passesmade/passes attempted

    double difficulty = (rand() % 100) + 1;

    incPasAtt();

    if (difficulty < passPercentage) {
        incPasMade();
        return true;
    } else {
        return false;
    }
}

/*
Function: 
	TakeShot - 
Input:
    int point - the amount of points that the player is going for
Goal: 
	Decide whether or not the shot was made,
    shot is decided based on what the percentage of player shots made /shots taken
    if the player goes for 1 points then the random number is between 1 and 70
    if the player goes for 2 points then the random number is between 1 and 100
    if the player goes for 3 points then the random number is between 1 and 125
    if the player's shot percentage is greater than the random number they score that amount of points
Returns:
	the amount of points made,
    if they don't make the shot 0 points is returned
*/
int BballPlayer::TakeShot(int point) {

    double shotPerc = 100 * static_cast<double>(shotsMade) / shotsTaken;
    incShtTake();

    if (point == 1) {
        int randNum = ((rand() % 70) + 1);
        if (shotPerc > randNum) {
            //std::cout << "made 3 point" << std::endl;
            incShtMade();
            return point;
        }
    }
    else if (point == 2) {
        int randNum = ((rand() % 100) + 1);
        if (shotPerc > randNum) {
            //std::cout << "made 2 point" << std::endl;
            incShtMade();
            return point;
        }
    }
    else if (point == 3) {
        int randNum = ((rand() % 125) + 1);
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

/*
Function: 
	randomizePlayerStats - 
Input:
    none
Goal: 
	This function randomizes all the players stats,
    making sure that the shots made and passes made are added to the shots taken and passes taken
    all stats are randomized between 1 and 100 
Returns:
	none void
*/
void BballPlayer::randomizePlayerStats(){
    shotsMade = (rand() % 100) + 1;
    shotsTaken = (rand() % 100) + 1 + shotsMade;
    passesMade = (rand() % 100) + 1;
    passesAttempted = (rand() % 100) + 1 + passesMade;
}
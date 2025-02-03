#include "BballPlayer.h"
#include <iostream>
#include <string>
#include <ctime>


bool PassBall();
int TakeShot(int);
void randomizePlayerStats();

/*
Function: 
	Pass - 
Input:
	int currPlayer - the player who is making the play
	Bballplayer team - an array of all the players on the team
Goal: 
	Choose a player that you would like to pass to, confitm that the input given is a vaild player,
	use the PassBall function to determine if the pass was successfull or not.
Returns:
	bool: true if possesion is kept, false if posession is lost
	updates current player to player ball was passed to
*/
bool Pass(int &currPlayer, BballPlayer team[]) {
	std::string passPlayer{""};
	bool validPlayer{false};

	while (!validPlayer) {
		if (!validPlayer) {
			std::cout << "Who do you want to pass to?" << std::endl;
		}
		for (int i{}; i < 5; i++) {
			if (i != currPlayer) {
				std::cout << team[i].getName() << " ? ";
			}
		}

		std::cout << std::endl;
		std::cin >> passPlayer;

		for (int i{}; i < 5; i++) {
			if (team[i].getName() == passPlayer) {
				validPlayer = true;
				currPlayer = i;
			}
		}

		if (!validPlayer){
			std::cout << "Please enter a valid player's name - ";
		}
	}

	//checks if the pass was successful
	if (team[currPlayer].PassBall()) {
		std::cout << "\nPass successfully passed to " << passPlayer << "!" << std::endl;
		//pos--; //this line and the following line will essentially bring the loop to the top but not make it so that the team loses a posession.
		return true;
	}
	else {
		std::cout << "Your pass to " << passPlayer << " was intercepted! The opponent will now get the ball." << std::endl;
		return false;
	}
	return false;
}

/*
Function: 
	Shoot - 
Input:
	int currPlayer - the player who is making the play
	int teamScore - the current score of the player team
	Bballplayer team - an array of all the players on the team
Goal: 
	Take a shot, the user will choose the amount of points that they want to shoot for,
	call the TakeShot function to determine if the shot was made,
	update the teamScore if the shot was made,
	if the shot was missed there is a 50% chance the player loses possesion
Returns:
	bool: true if possesion is kept, false if posession is lost
	updates teamScore based on the amount of points gained
*/
bool Shoot(int currPlayer, int &teamScore, BballPlayer team[]){
	std::cout << "\nAnd " << team[currPlayer].getName() << " lines up for the shot! He's going for a...(1,2, or 3)" << std::endl;
	int scoreAttempt{ 0 };
	std::cin >> scoreAttempt;

	int points = team[currPlayer].TakeShot(scoreAttempt);
	teamScore += points;

	if (points > 0) {
		std::cout << "The shot was made and the points have been added to the scoreboard. \nThe opposing team will now take posession" << std::endl;
	}
	else {
		std::cout << "\nThe shot was missed." << std::endl;
		if (rand() % 100 < 50) {
			std::cout << "You kept possession." << std::endl;
			return true;
			//allowPlayerRandomizing = true;
			//pos--;
		}
		else {
			std::cout << "You lost possession!" << std::endl;
			return false;
		}
	}
	return false;
}

/*
Function: 
	seePlayerStats - 
Input:
	Bballplayer team - an array of all the players on the team
Goal: 
	Show the stats of all players on the team
Returns:
	void, no return
*/
void seePlayerStats(BballPlayer team[]) {
	for (int i{ 0 }; i < 5; i++) {
		std::cout << "\n" << team[i].getName() << "'s stats are:" << std::endl;
		std::cout << "Pass Attempts: " << team[i].getPasAtt() << std::endl;
		std::cout << "Passes Made: " << team[i].getPasMade() << std::endl;
		std::cout << "Shots Taken: " << team[i].getShotTake() << std::endl;
		std::cout << "Shots Made: " << team[i].getShotMade() << std::endl;}
}

/*
Function: 
	seeScore - 
Input:
	int scores[] - the scores of both teams
	int numPos - the number of possesions
Goal: 
	Shows the score of both teams,
	Show the number of possessions that are left
Returns:
	void, no return
*/
void seeScore(int scores[], int numPos){
	std::cout << "\nYour score: " << scores[0] << std::endl;
	std::cout << "Opponent score: " << scores[1] << std::endl;
	std::cout << "Possessions left: " << 30 - numPos << std::endl;
}

/*
Function: 
	callPlay - 
Input:
	int playCall - what play should be chosen
	int currPlayer - the player who is making the play
	int scores[] - array of the team's score and the opponents score
	int numPos - the number of possesions
	Bballplayer team - an array of all the players on the team
Goal: 
	Use given playCall to decide which play is made,
	do the actions of chosen play,
	return true if the team kept possession
	return false if the team lost possession
Returns:
	bool: true if possesion is kept, false if posession is lost
	updates current player to player ball was passed to
	updates scores of the team
*/
bool callPlay(int playCall, int &currPlayer, int scores[], int numPos, BballPlayer team[]) {
	if (playCall == 1){
		return Pass(currPlayer,team);
	} else if (playCall == 2) {
		return Shoot(currPlayer, scores[0], team);
	} else if (playCall == 3) {
		seePlayerStats(team);
		return true;
	} else if (playCall == 4) {
		seeScore (scores, numPos);
		return true;
	} else {
		return false;
	}

}

int main() {
	srand(time(nullptr)); //Get Random number

	BballPlayer team[5] = { {"Jack"},{"Quinton"},{"John"},{"Steve"},{"Cinco"} };

	team[0].randomizePlayerStats();	//Jack
	team[1].randomizePlayerStats(); //Quinton
	team[2].randomizePlayerStats(); //John
	team[3].randomizePlayerStats(); //Steve
	team[4].randomizePlayerStats(); //Cinco

	int scores[] = {0,0}; //Our team index 0, opponents team index 1
	bool havePossesion = true;
	int currPlayerNumber = rand() % 5;

	for (int pos{ 0 }; pos < 30; pos++) {
		//tell user which player has poss, display name, stats
		//player /w/ pos is randomized
		int currPlayerNumber = rand() % 5;
	
		std::cout << "\n" << team[currPlayerNumber].getName() << " has the ball. His stats are:" << std::endl;
		std::cout << "Passes Attempted: " << team[currPlayerNumber].getPasAtt() << std::endl;
		std::cout << "Passes Made: " << team[currPlayerNumber].getPasMade() << std::endl;
		std::cout << "Shots Taken: " << team[currPlayerNumber].getShotTake() << std::endl;
		std::cout << "Shots Made: " << team[currPlayerNumber].getShotMade() << std::endl;	

		while(havePossesion){
			std::cout << "\nWhat would you like to do?" << std::endl;
			std::cout << "Pass (1) \t Shoot (2) \t See Stats (3) \t See Score (4)" << std::endl;

			int playCall{ 0 };

			std::cin >> playCall;
			std::cout << std::endl;

			havePossesion = callPlay(playCall, currPlayerNumber, scores, pos, team);
	}

	//Opponents turn
	std::cout << "\nNow it's the opponents turn\n" << std::endl;
	bool oppsTurn = true;
	while (oppsTurn) {
		if (rand() % 100 < 60) {
			int pointsScored = rand() % 3 + 1;
			std::cout << "Your opponents scored a " << pointsScored << " pointer! Now you will get possession" << std::endl;
			scores[1] += pointsScored;
			oppsTurn = false;
		} else {
			std::cout << "Your opponents took a shot and missed!" << std::endl;
		}
		if (rand() % 100 < 50 && oppsTurn == true) {
			std::cout << "Your opponents kept possession." << std::endl;
		} else {
			std::cout << "\nYou've gained possession!" << std::endl;
			oppsTurn = false;
			havePossesion = true;
		}
	}

	}
	
	/*Game is over, go through the final score*/	
	std::cout << "It's the end of the game and the scores are in...\n Your opponent scored " << scores[1] << " points...\n and you scored..." << std::endl;
	if (scores[1] > scores[0]) {
		std::cout << scores[0] << " points. Better luck next time!" << std::endl;
	} else if(scores[1] < scores[0]) {
		std::cout << scores[0] << " points!!! Congratulations!!!" << std::endl;
	}
	else if (scores[1] == scores[0]) {
		std::cout << scores[0] << " points! That's a tie! Look's like a rematch is in order!" << std::endl;
	}
	else {
		std::cout << scores[0] << " points? You broke my program? Um...what?" << std::endl;
	}

		return 0;
}

#include "BballPlayer.h"
#include <iostream>
#include <string>
#include <ctime>


bool PassBall();
int TakeShot(int);
void randomizePlayerStats();


bool Pass(int &currPlayer, BballPlayer team[]) {
	std::string passPlayer{""};
	bool validPlayer{false};

	//add way to check if the player you are inputting is valid or not repeat if not
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

void seePlayerStats(int currPlayer, BballPlayer team[]){
	std::cout << "\n"<< team[currPlayer].getName() << "'s stats are:" << std::endl;
	std::cout << "Pass Attempts: " << team[currPlayer].getPasAtt() << std::endl;
	std::cout << "Passes Made: " << team[currPlayer].getPasMade() << std::endl;
	std::cout << "Shots Taken: " << team[currPlayer].getShotTake() << std::endl;
	std::cout << "Shots Made: " << team[currPlayer].getShotMade() << std::endl;
}

void seeScore(int currPlayer,int scores[], int numPos, BballPlayer team[]){
	std::cout << "\nYour score: " << scores[0] << std::endl;
	std::cout << "Opponent score: " << scores[1] << std::endl;
	std::cout << "Possessions left: " << 30 - numPos << std::endl;
}

bool callPlay(int playCall, int &currPlayer, int scores[], int numPos, BballPlayer team[]) {
	if (playCall == 1){
		return Pass(currPlayer,team);
	} else if (playCall == 2) {
		return Shoot(currPlayer, scores[0], team);
	} else if (playCall == 3) {
		//seePlayerStats(currPlayer, team);
		return true;
	} else if (playCall == 4) {
		seeScore (currPlayer,scores, numPos, team);
		return true;
	} else {
		return false;
	}

}


int main() {
	srand(time(nullptr)); //Get Random number

	BballPlayer team[5] = { {"Jack"},{"Quinton"},{"John"},{"Steve"},{"Cinco"} };

	//Jack
	//team[0].setPassAtt(15);	team[0].setPassMade(8);	team[0].setShotTake(9);	team[0].setShotMade(2);
	team[0].randomizePlayerStats();

	//Quinton
	//team[1].setPassAtt(90);	team[1].setPassMade(78); team[1].setShotTake(63); team[1].setShotMade(40);
	team[1].randomizePlayerStats();

	//John
	//team[2].setPassAtt(56);	team[2].setPassMade(30); team[2].setShotTake(92); team[2].setShotMade(78);
	team[2].randomizePlayerStats();

	//Steve
	//team[3].setPassAtt(84); team[3].setPassMade(50); team[3].setShotTake(9); team[3].setShotMade(1);
	team[3].randomizePlayerStats();

	//Cinco
	//team[4].setPassAtt(70); team[4].setPassMade(5); team[4].setShotTake(80); team[4].setShotMade(70);
	team[4].randomizePlayerStats();

	int scores[] = {0,0}; //Our team index 0, opponents team index 1
	bool havePossesion = true;
	int currPlayerNumber = rand() % 5;

	for (int pos{ 0 }; pos < 30; pos++) {
		//tell user which player has poss, display name, stats
		//player /w/ pos is randomized
		int currPlayerNumber = rand() % 5;
	
		

		while(havePossesion){
			std::cout << "\n" << team[currPlayerNumber].getName() << " has the ball. His stats are:" << std::endl;
			std::cout << "Passes Attempted: " << team[currPlayerNumber].getPasAtt() << std::endl;
			std::cout << "Passes Made: " << team[currPlayerNumber].getPasMade() << std::endl;
			std::cout << "Shots Taken: " << team[currPlayerNumber].getShotTake() << std::endl;
			std::cout << "Shots Made: " << team[currPlayerNumber].getShotMade() << std::endl;

			std::cout << "\nWhat would you like to do?" << std::endl;
			std::cout << "Pass (1) \t Shoot (2) \t See Stats (3) \t See Score (4)" << std::endl;

			int playCall{ 0 };

			std::cin >> playCall;
			std::cout << std::endl;

			havePossesion = callPlay(playCall, currPlayerNumber, scores, pos, team);
		}

		

		// if playcall is two and the shot fails, then the opposing team takes the ball, 
		// use continue to go to the top of the for loop

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

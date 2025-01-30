#include <iostream>
#include <string>
#include <ctime>

class BballPlayer {
	private:
		std::string name{ " " };
		int shotsTaken{ 0 };
		int shotsMade{ 0 };
		int passesAttempted{ 0 };
		int passesMade{ 0 };

	public:

		BballPlayer(std::string n) {
			name = n;
		}

		//setters

		void setName(std::string n) {
			name = n;
		}
		void setShotTake(int st) {
			shotsTaken = st;
		}
		void setShotMade(int sm) {
			shotsMade = sm;
		}
		void setPassAtt(int pa) {
			passesAttempted = pa;
		}
		void setPassMade(int pm) {
			passesMade = pm;
		}

		// getters

		std::string getName() {
			return name;
		}
		const int getPasAtt() {
			return passesAttempted;
		}
		const int getPasMade() {
			return passesMade;
		}
		const int getShotTake() {
			return shotsTaken;
		}
		const int getShotMade() {
			return shotsMade;
		}

		// modifiers
		void incPasAtt() {
			passesAttempted++;
		}
		void incPasMade() {
			passesMade++;
		}
		void incShtTake() {
			shotsTaken++;
		}
		void incShtMade() {
			shotsMade++;
		}


		// funtions

		bool PassBall() {

			double passPercentage = 100.00 * static_cast<double> (passesMade) / static_cast<double>(passesAttempted);
			// return value regards to if a pass was successful or not
			// pulls a random number between 1-100 and if % > passesmade/passes attempted

			srand(time(0));

			double difficulty = rand() % 101;

			//std::cout << "difficulty: " << difficulty << std::endl;
			//std::cout << "player stat: " << passPercentage << std::endl;

			incPasAtt();

			if (difficulty < passPercentage) {
				incPasMade();
				//std::cout << "the pass was made";
				return true;
			} else {
				//std::cout << "the pass failed";
				return false;
			}
		}

		int TakeShot(int point) {
			srand(time(0));

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

};

int main() {

	BballPlayer team[5] = { {"Jack"},{"Quinton"},{"John"},{"Steve"},{"Cinco"} };

	//jack
	team[0].setPassAtt(15);
	team[0].setPassMade(8);
	team[0].setShotTake(9);
	team[0].setShotMade(2);

	//quinton
	team[1].setPassAtt(90);
	team[1].setPassMade(78);
	team[1].setShotTake(63);
	team[1].setShotMade(40);

	//john
	team[2].setPassAtt(56);
	team[2].setPassMade(30);
	team[2].setShotTake(92);
	team[2].setShotMade(78);

	//steve
	team[3].setPassAtt(84);
	team[3].setPassMade(50);
	team[3].setShotTake(9);
	team[3].setShotMade(1);

	//Cinco
	team[4].setPassAtt(70);
	team[4].setPassMade(5);
	team[4].setShotTake(80);
	team[4].setShotMade(70);

	//Opponents
	int oppScore{0};



	for (int pos{ 0 }; pos < 30; pos++) {
		//tell user which player has poss, display name, stats
		//player /w/ pos is randomized

		srand(time(0) + 4);

		int currPlayerNumber = rand() % 5;

		std::cout << team[currPlayerNumber].getName() << " has the ball. His stats are:" << std::endl;
		std::cout << "Pass Attempts: " << team[currPlayerNumber].getPasAtt();
		std::cout << "\tPasses Made: " << team[currPlayerNumber].getPasMade() << std::endl;
		std::cout << "\nShots Taken: " << team[currPlayerNumber].getShotTake();
		std::cout << "\t\tShots Made: " << team[currPlayerNumber].getShotMade() << "\n" << std::endl;
		
		std::cout << "\nWhat would you like to do?" << std::endl;
		std::cout << "Pass (1) \t Shoot (2) \t See Stats (3) \t See Score (4)" << std::endl;

		int playCall{ 0 };

		std::cin >> playCall;

		if (playCall == 1) {
			std::string passPlayer{""};
			bool validPlayer{false};
			
			//add way to check if the player you are inputting is valid or not repeat if not
			while(!validPlayer){
				if(!validPlayer){
					std::cout << "Who do you want to pass to?" << std::endl;
				}
				for (int i{}; i < 5; i++) {
					if (i != currPlayerNumber){
							std::cout << team[i].getName() << "? ";
						}
					}
				
					std::cout << std::endl;
					std::cin >> passPlayer;
				for (int i{}; i < 5; i++) {
					if(team[i].getName() == passPlayer){
							validPlayer = true;
					}
				}
			}
		
			
			if (team[currPlayerNumber].PassBall()) {
				std::cout << "Pass successfully passed to " << passPlayer << "!" << std::endl;
				continue;
			}
			else {
				std::cout << "Your pass to " << passPlayer << " was intercepted! The opponent will now get the ball." << std::endl;
			}
		}
		else if (playCall == 2) {
			std::cout << "And " << team[currPlayerNumber].getName() << " lines up for the shot! He's going for a...(1,2, or 3)" << std::endl;
			int scoreAttempt{ 0 };
			std::cin >> scoreAttempt;
			if (team[currPlayerNumber].TakeShot(scoreAttempt) > 0) {
				std::cout << "The shot was made and the points have been added to the scoreboard. \nThe opposing team will now take posession" << std::endl;
				continue;
			}
		}
		// if playcall is two and the shot fails, then the opposing team takes the ball, 
		// use continue to go to the top of the for loop

		std::cout << "Now it's the opponents turn" << std::endl;

		bool oppsTurn = true;

		while(oppsTurn){
			if (rand() % 100 < 60){
				int pointsScored = rand() % 3 + 1;
				std::cout << "Your opponents scored a " << pointsScored << " pointer!" << std::endl;
				oppScore += pointsScored;
			} else {
				std::cout << "Your opponents missed!" << std::endl;
			}

			if (rand() % 100 < 50){
				std::cout << "Your opponents kept possession." << std::endl;
			} else {
				std::cout << "You've gained possession!" << std::endl;
				oppsTurn = false;
			}
		}
		return 0;
	}
	
}


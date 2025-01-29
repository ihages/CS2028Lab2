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

		int getPasAtt() {
			return passesAttempted;
		}
		int getPasMade() {
			return passesMade;
		}
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

			double passPercentage = 100.00 * static_cast<double> (this->passesMade) / static_cast<double>(this->passesAttempted);
			// return value regards to if a pass was successful or not
			// pulls a random number between 1-100 and if % > passesmade/passes attempted

			srand(time(0));

			double difficulty = rand() % 101;

			std::cout << "difficulty: " << difficulty << std::endl;
			std::cout << "player stat: " << passPercentage << std::endl;

			incPasAtt();

			if (difficulty < passPercentage) {
				incPasMade();
				std::cout << "the pass was made";
				return true;
			} else {
				std::cout << "the pass failed";
				return false;
			}
		}
		
		 int TakeShot(int point) {
            srand(time(0));

            double shotPerc = 100 * static_cast<double>(shotsMade) / shotsTaken;
            incShtAtt();

            if (point == 3){
                int randNum = (rand() % 71);
                if (shotPerc > randNum){
                    //std::cout << "made 3 point" << std::endl;
                    incShtMade();
                    return point;
                }
            } else if (point == 2) {
                int randNum = (rand() % 101);
                if (shotPerc > randNum){
                    //std::cout << "made 2 point" << std::endl;
                    incShtMade();
                    return point;
                }
            } else if (point == 1) {
                int randNum = (rand() % 126);
                if (shotPerc > randNum){
                    //std::cout << "made 1 point" << std::endl;
                    incShtMade();
                    return point;
                }
            } else {
                return 0;
            }

            return 0;
    }

};

int main() {

	BballPlayer team[5] = { {"Jack"},{"Quinton"},{"John"},{"Steve"},{"Cinco"} };

	team[0].setPassAtt(40);
	team[0].setPassMade(20);

	team[0].PassBall();
}


#ifndef __BBALLPLAYER_HPP
#define __BBALLPLAYER_HPP

#include <string>


class BballPlayer {
	private:
		std::string name{ "" };
		int shotsTaken{ 0 };
		int shotsMade{ 0 };
		int passesAttempted{ 0 };
		int passesMade{ 0 };

	public:

		//constructor
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
		int getPasAtt() const{
			return passesAttempted;
		}
		int getPasMade() const{
			return passesMade;
		}
		int getShotTake() const {
			return shotsTaken;
		}
		int getShotMade() const {
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

		//functions
		bool PassBall();
		int TakeShot(int);
};


#endif
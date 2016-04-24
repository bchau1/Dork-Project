#include "dork.h"
#ifndef GAME_H
#define GAME_H


class GameData{

	private:
		string name;
		string levels[3] = {"Terrestrial", "Arboreal", "Aerial"};
		string level;
		int energy;
		int roll;
		int steps;
	

	public:
		GameData();
		GameData(string name);
	    GameData(string name, string level, int energy, int steps);
		
		string getName();
		string getLevel();
		int getEnergy();
		int getSteps();
		int getRoll();

		void setName(string n);
		void setLevel(int s);
		void setEnergy(int e);
		void setSteps(int s);
		void setRoll(int r);
		
		void printData();
		void playGame();
		

};

#endif

#include "dork.h"
#ifndef GAME_H
#define GAME_H


class GameData{

	private:
		string name;
		string levels[3] = {"Terrestrial", "Arboreal", "Aerial"};
		int level;
		int energy;
		int roll;
		int steps;
	

	public:
		GameData();
		GameData(string name);
		GameData(string n, int l, int e, int s);
		
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
		
		void printData(); // prints the banner
		void playGame();
		
		void loadEvents();

		int loadGame();
		int saveGame();
		

};
struct point
{
	int x;
	int y;
};

struct eventInfo
{
	bool needsResponse;
	string Description;
	int energy;
	point newLocation;
	bool isQuestion;
	
};

#endif

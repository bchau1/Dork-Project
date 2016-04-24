#include "game.h"

//Gamedata Constructors
GameData::GameData(string n):name(n)
{
	energy = 15;
	level = levels[0];
	steps = 0;
	roll = 0;
}

GameData::GameData()
{
	name = "Unknown";
	level = levels[0];
	energy = 15;
	steps = 0;
	roll = 0;
}

GameData::GameData(string n, string l, int e, int s)
:name(n), level(l), energy(e), steps(s)
{

}

//Member functions Accessors and Mutators
//Accessors
string GameData::getName()
{
	return name;

}
	
string GameData::getLevel()
{
	return level;

}

int GameData::getEnergy()
{
	return energy;

}

int GameData::getSteps()
{
	return steps;

}

int GameData::getRoll()
{
	return roll;

}
//Mutators
void GameData::setName(string n)
{
	name=n;


}

void GameData::setLevel(int s){
	level = levels[s];
}

void GameData::setEnergy(int e){
	energy = e;
}

void GameData::setSteps(int s){
	steps = s;
}

void GameData::setRoll(int r){
	roll = r;
}

//Member functions, that do actual things		
void GameData::printData(){
	printw("Username: ");
	string user = getName();
	printw("%s", user.c_str());
	printw("\t");
	printw("Level: ");
	string lev = getLevel();
	printw("%s", lev.c_str());
	printw("\t");
	printw("Energy Level: ");
	printw("%d", getEnergy());
	printw("\t");
	printw("Steps: ");
	printw("%d", getSteps());
}//end printData

void GameData::playGame()
{
	string input;
	bool running = true;
	while(running)
	{
		scanw("%s", input.c_str());
		if(input.length() > 7)
		{
		
		printw("\n");
		refresh();
		printw("%s", input.c_str());
		printw("\n");
		refresh();
			running = false;
			printw("Ended?");
		}
	
	
	}//end while
		



}

#include "dork.h"
#include "game.h"
//Don't include .cpp files


//Member functions, that do actual things		
void GameData::printData(){
	move(8,0);
	printw("\n---------------------------------------------\n");
	printw("Hello: ");
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
	printw("\n---------------------------------------------\n");
	refresh();
}//end printData

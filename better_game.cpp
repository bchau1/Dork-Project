#include "game.h"

//Gamedata Constructors
GameData::GameData(string n)
{
	name = n;
	energy = 15;
	level = 0;
	steps = 0;
	roll = 0;
}

GameData::GameData()
{
	name = "Unknown";
	level = 0;
	energy = 15;
	steps = 0;
	roll = 0;
}

GameData::GameData(string n, int l, int e, int s)
{
	name = n;
	level = l;
	energy = e;
	steps = s;
	roll =0;
}

//Member functions Accessors and MutatorsclearDisplay(1);
//Accessors
string GameData::getName()
{
	return name;

}
	
string GameData::getLevel()
{
	return levels[level];

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
	level = s;
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



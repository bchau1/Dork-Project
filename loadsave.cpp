#include"dork.h"
#include"game.h"


int GameData::loadGame()
{
	ifstream dat("saved_Data.dat");
	string arr[5];
	if (!dat.is_open())
    	{
		printw("Input file could not be read");
		return -1;
    	}
	while (dat.good())
   	{
		int count = 0;
		for(string eachLine; getline(dat, eachLine);++count) //get each line
		{
			arr[count]=eachLine;
		}
	}
	int LLevel = stoi(arr[1]);
	int Lroll = stoi(arr[2]);
	int Lenergy = stoi(arr[3]);
	int Lsteps = stoi(arr[4]);

	setName(arr[0]);
	setLevel(LLevel);
	setRoll(Lroll);
	setEnergy(Lenergy);
	setSteps(Lsteps);
	dat.close();
	return 0;
}
int GameData::saveGame()
{
	int error = 0;


	ofstream dat ("saved_Data.dat");
	if (!dat.is_open())
   	{
        	printw("Input file could not be read");
        	return -1;
   	}
	dat<< getName()<<endl;
	dat<< getLevel()<<endl;
 	dat<< getRoll()<<endl;
	dat<< getEnergy()<<endl;
 	dat<< getSteps()<<endl;
	return 0;
}


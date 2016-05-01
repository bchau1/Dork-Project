#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>
#include "game.h"
using namespace std;

int rollfunc()
{	
  int num;
  char* in_str = new char[30];
  while (strcmp(in_str,"roll")!=0){
    printw("Please type 'roll' to roll the die\n");
    scanw("%s", in_str);
  }
  if (strcmp(in_str,"roll")==0)
  {
    srand(time(NULL));
    num= rand() % 6 + 1;
  }
  delete in_str;

  return num;
}

void GameData::playGame()
{
	string input;
	int loops = 0;
	while(getEnergy()!=0)
	{	
		loops++;
		clearDisplay(1);
		printData();
		setEnergy(getEnergy()-1);
		setSteps(getSteps()+rollfunc());
		if(loops%25==0)
		{
			saveGame();
		}
	}//end while
}


#include "dork.h"
#include "game.cpp"
//#include "game.h"


void banner(dorkInfo dork)
{
	clearDisplay(1);
	printw("%s"," Hello: "); 
	printName(dork);
	printw("%s", " Level: ");
	printLevel(dork);
	
	printw(" " );
	
	printw( "%s", " Energy:" );  
	
	printEnergy(dork);
	
	printw( "%s" , "Rolls:");
	
	printw(" ");
	
	printRolls(dork);
	
	printw(" ");//
	printw("%s", "Steps: "); 
	printSteps(dork);
	//dork.printAll();
	refresh();
	getch();
 }

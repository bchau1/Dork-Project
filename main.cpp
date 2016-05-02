/*********************************************************************
 * File: main.cpp
 * Description: Main function which initialize the display and 
 * Introduction.
 * Author: Abhi (adevalap@uncc.edu)
 * University: UNC Charlotte
 * 
 * Copyright (C) 2016, Abhilash Devalapura Rajagopala
 * This program is part of UNC Charlotte course project
 * and is distributed for education purpose only.
 * All commercial rights are reserved by the author on
 * distibution of the game database, custom function , header, ascii art
 * and other related to this game pack.
 * must be properly acknowledge.
 * /
 * *******************************************************************/
#include"dork.h"
#include"loadsave.cpp"
#include"play.cpp"
int eventLocationX[200];
int eventLocationY[200];
string eventDescription[200];
int responseNum[200];
int energyNum[200];
int moveX[200];
int moveY[200];
int questionNum[200];

void Database()
{
	string eventLocation[200];
	string response[200];
	string energy[200];
	string move[200];
	string Question[200];
	
	int error = 1;
	char *token;
	char *token2;
	string arr[200];
	char temp[100];
	char eventTemp[10];
	int count = 0;
	int j = 0;
	
	ifstream database("events.txt");
	if (!database.is_open())
    	{
        printw("Input file could not be read");
        error = 1;
    	}
	while (database.good()) 
   	{
        for(string eachLine; getline(database, eachLine);++count) //get each line
        {
		arr[count]=eachLine;
	}
	}
	database.close();
	
	for(int j = 1; j<200; j++)//Event.txt ^ deliminator
	{
		for(int i = 0; i<arr[j].length(); i++)//converts a string to an array of char
		{
		temp[i] = arr[j].at(i);
		}
		token = strtok(temp,"^");
		string array[7];
		int i=0;
		while(token != NULL)
		{
			array[i]=token;
			i++;
			//printw("%s\n",token);
			token = strtok(NULL,"^");
		}
		
			eventLocation[j]= array[0];
			eventDescription[j]= array[1];
			response[j]= array[2];
			energy[j]= array[3];
			move[j]= array[4];
			Question[j]= array[5];
		
	 }
	 for(int j = 1; j<200; j++) //Location , Deliminator
	 {
		 int pos = eventLocation[j].find_first_of(',');
		 eventLocationY[j] = stoi(eventLocation[j].substr(pos+1));
		 eventLocationX[j] = stoi(eventLocation[j].substr(0,pos));
		 responseNum[j] = stoi(response[j]);
		 energyNum[j] = stoi(energy[j]);
		 questionNum[j] = stoi(Question[j]);
		 
	 }
	 for(int j = 1; j<200; j++) //Location , Deliminator
	 {
		 int pos = move[j].find_first_of(',');
		 moveY[j] = stoi(move[j].substr(pos+1));
		 moveX[j] = stoi(move[j].substr(0,pos));
	 }
	 
	 /*
	ofstream test ("testing.txt");
	
		for(int i =1; i<200; i++)
		{
		//test<<eventLocation[i]<<endl;
		//test<<eventDescription[i]<<endl;
		//test<<response[i]<<endl;
		//test<<energy[i]<<endl;
		//test<<move[i]<<endl;
		//test<<Question[i]<<endl;
		//test<<eventLocationX[i]<<"   ";
		//test<<eventLocationY[i]<<endl;
		//test<<moveX[i]<<"   ";
		//test<<moveY[i]<<endl;
		}
		test.close();*/
}
int main(int argc, char *argv[])
{
	display_init();
        //intro_display();
	clearDisplay(1);
	dorkInfo dork;
	//loadOrNew(dork);
	clearDisplay(1);
	dork.printAll();
	Database();
	for(int i = 1; i<10; i++)
	{
	printw("%d",moveX[i]);
	printw("\t%d",moveY[i]);
	printw("\n");
	//refresh();
	}
	//printw("%d",Roll());
	//checkEvent(dork.getCurrentLocationX, dork.getCurrentLocationY);
	//if(checkpoint(dork.getSteps) == 1)
	//{
	//	save(dork);
	//}
    getch();
    display_close();
    return 0;
}

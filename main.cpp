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
#include"Checkpoint.cpp"
int eventLocationX[200];
int eventLocationY[200];
string eventDescription[200];
int responseNum[200];
int energyNum[200];
int moveX[200];
int moveY[200];
int questionNum[200];
string arr[9];
int count=0;
int roll = 0;
int energy = 0;
int steps = 0;
int age = 0;
int currentX = 0;
int currentY = 0;
int arrayNum = 0;
int temp = 0;
int newLoad = 0;
int stepReset = 0;
char levelIncrease = 'y';
int storedEnergy = 0;
char eatOrStore[5];
string answer;

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
		 eventLocationX[j] = stoi(eventLocation[j].substr(pos+1));
		 eventLocationY[j] = stoi(eventLocation[j].substr(0,pos));
		 responseNum[j] = stoi(response[j]);
		 energyNum[j] = stoi(energy[j]);
		 questionNum[j] = stoi(Question[j]);
		 
	 }
	 for(int j = 1; j<200; j++) //Location , Deliminator
	 {
		 int pos = move[j].find_first_of(',');
		 moveX[j] = stoi(move[j].substr(pos+1));
		 moveY[j] = stoi(move[j].substr(0,pos));
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
	Database();
	dork.printAll();
	newLoad = loadOrNew(dork);
	ifstream dat("saved_Data.dat");
	while (dat.good())
   	{
       		 for(string eachLine; getline(dat, eachLine);++count) //get each line
       		 {
			arr[count]=eachLine;
		 }
	}
	dork.setName(arr[0]);
	dork.setLevel(arr[1]);
	roll = stoi(arr[2]);
 	dork.setRolls(roll);
	energy = stoi(arr[3]);
	dork.setEnergy(energy);
	steps = stoi(arr[4]);
 	dork.setSteps(steps);
	age = stoi(arr[5]);
	dork.setAge(age);
	dork.setNationality(arr[6]);
	currentX = stoi(arr[7]);
	dork.setCurrentLocationX(currentX);
	currentY = stoi(arr[8]);
	dork.setCurrentLocationY(currentY);
	dat.close();
	
	ifstream newGame("new_Data.dat");
	if (newLoad == 0)
	{
		count = 0;
		while (newGame.good())
   		{
       		 	for(string eachLine; getline(newGame, eachLine);++count) //get each line
       			{
				arr[count]=eachLine;
		 	}
		}
		dork.setName(arr[0]);
		dork.setLevel(arr[1]);
		roll = stoi(arr[2]);
 		dork.setRolls(roll);
		energy = stoi(arr[3]);
		dork.setEnergy(energy);
		steps = stoi(arr[4]);
 		dork.setSteps(steps);
		age = stoi(arr[5]);
		dork.setAge(age);
		dork.setNationality(arr[6]);
		currentX = stoi(arr[7]);
		dork.setCurrentLocationX(currentX);
		currentY = stoi(arr[8]);
		dork.setCurrentLocationY(currentY);
		newGame.close();
	}
	save(dork);
	clearDisplay(1);
	dork.printAll();	
	printw("%s\n",eventDescription[1].c_str());
	while(dork.getEnergy() != 0)
	{
		temp = Roll();
		dork.setRolls(temp);
		printw("You rolled a : ");
		printw("%d\n",temp);
		dork.setEnergy(dork.getEnergy() - 1);
		dork.setSteps(dork.getSteps()+temp);
		dork.setCurrentLocationX(dork.getCurrentLocationX()+temp);
		for(int i = 1; i<200; i++)
		{
			if((dork.getCurrentLocationX() == eventLocationX[i]) && (dork.getCurrentLocationY() ==
			eventLocationY[i]))
	  		{
				getch();
				clearDisplay(1);
				dork.printAll();
				printw("%s\n",eventDescription[i].c_str());
				if(responseNum[i] == 0) //No response
				{
					dork.setEnergy(dork.getEnergy()+energyNum[i]);
					if(dork.getEnergy()>30)
					{
						dork.setEnergy(30);
					}
					dork.setCurrentLocationX(dork.getCurrentLocationX()+moveX[i]);
					dork.setCurrentLocationY(dork.getCurrentLocationY()+moveY[i]);
				}
				if(responseNum[i] == 1) //Response
				{
					if(energyNum[i] != 0) //Energy Eat or Store
					{
						printw("eat or store?");
						scanw("%s\n",eatOrStore);
						while((strcmp(eatOrStore,"eat")!=0) && (strcmp(eatOrStore,"store") != 0))
						{
							printw("eat or store?");
							scanw("%s\n",eatOrStore);
						}
						if(strcmp(eatOrStore,"eat")==0)
						{
							dork.setEnergy(dork.getEnergy()+energyNum[i]);
							if(dork.getEnergy()>30)
							{
								dork.setEnergy(30);
							}
						}
						if(strcmp(eatOrStore,"store")==0)
						{
							storedEnergy = energyNum[i];
						}
					}
					if(questionNum[i] == 1) //Question
					{
						scanw("%s\n",answer.c_str());
					}
					
	  			}
			}
		}
		stepReset++;
		if(stepReset > 6)
		{
			save(dork);
			stepReset = 0;
		}
		getch();
		clearDisplay(1);
		dork.printAll();
	}
	printw("\t\t=[ You ran out of Energy.");
    getch();
    display_close();
    return 0;
}

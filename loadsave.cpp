#include"dork.h"
#include"game.cpp"

void loadOrNew(dorkInfo dork)
{
	int error = 0;
	string arr[9];
	int count=0;
	int roll = 0;
	int energy = 0;
	int steps = 0;
	char load_new[4];
	int age = 0;
	int currentX = 0;
	int currentY = 0;
	
	char enterName[10];
	char temp[3];
	int enterAge =00;
	char enterNationality[10]; 
	printw("Would you like to start a new game or load a saved game?\n");
	printw("Type load or new: \t");
	scanw("%s",load_new);
	
	while((strcmp(load_new,"load")!=0) && (strcmp(load_new,"new")!=0))
	{
		printw("Enter load or new: \n");
		scanw("%s",load_new);
	}
	if(strcmp(load_new,"load")==0)
	{
		ifstream dat("saved_Data.dat");
		//dat.open("saved_Data.dat");
	if (!dat.is_open())
    	{
        printw("Input file could not be read");
        error = 1;
    	}
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
		printw("load\n");
		dork.printAll();
		dat.close();
		//run game
	
	}
	if(strcmp(load_new,"new")==0)
	{
		ofstream news ("new_Data.dat");
		printw("Starting New game\n");
		printw("Enter the following.\n");
		printw("Name: ");
		scanw("%s", enterName);
		//dork.setName(enterName);
		printw("Age: ");
		scanw("%s", temp);
		enterAge = atoi(temp);
		//dork.setAge(enterAge);
		printw("Nationality: ");
		scanw("%s", enterNationality);
		//dork.setNationality(enterNationality);
		//dork.setRolls(0);
		//dork.setEnergy(15);
		//dork.setSteps(0);
		//dork.setLevel("Terrestrial");
		
		if (!news.is_open())
   		{
   		    	 cout << "Input file could not be read" << endl;
        		 error = 1;
   		}
		news<< enterName<<endl;
		news<< "Terrestrial"<<endl;
 		news<< 0 <<endl;
		news<< 15<<endl;
 		news<< 0 <<endl;
		news<< enterAge<<endl;
		news<< enterNationality<<endl;
		news<< 0 <<endl;
		news<< 0 <<endl;
		news.close();
		printw("\n");
		//run game
	}
	if(error == 1)
	{
		printw("error with load");
		error =0;
	}
}
void save(dorkInfo dork)
{
	int error = 0;
	ofstream dat ("saved_Data.dat");
	//dat.open("saved_Data.dat");
	if (!dat.is_open())
   	{
        cout << "Input file could not be read" << endl;
        error = 1;
   	}
	dat<< dork.getName()<<endl;
	dat<< dork.getLevel()<<endl;
 	dat<< dork.getRolls()<<endl;
	dat<< dork.getEnergy()<<endl;
 	dat<< dork.getSteps()<<endl;
	dat<< dork.getAge()<<endl;
	dat<< dork.getNationality()<<endl;
	dat<< dork.getCurrentLocationX()<<endl;
	dat<< dork.getCurrentLocationY()<<endl;
	if(error == 1)
	{
		printw("error with save");
		error = 0;
	}
	dat.close();
}


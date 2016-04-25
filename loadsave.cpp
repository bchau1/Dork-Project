#include"dork.h"
#include"game.cpp"

void loadOrNew(dorkInfo dork)
{
	int error = 0;
	string arr[5];
	int count=0;
	int roll = 0;
	int energy = 0;
	int steps = 0;
	char load_new[4];
	
	char forename[10];
	char surname[10];
	int age[3];
	char nationality[10]; 
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
		dat.close();
		printw("load\n");
		dork.printAll();
		//run game
	
	}
	if(strcmp(load_new,"new")==0)
	{
		printw("Starting New game\n");
		printw("Forename: ");
		scanw("%s", forename);
		//printw("\n");
		printw("Surname: ");
		scanw("%s", surname);
		//printw("\n");
		printw("Age: ");
		scanw("%d", age);
		//printw("\n");
		printw("Nationality: ");
		scanw("%s", nationality);
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
	/*if(dork.getSteps() % 25 == 0)
	{
		// save
	}*/
	//testing for load function
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
	if(error == 1)
	{
		printw("error with save");
		error = 0;
	}
}


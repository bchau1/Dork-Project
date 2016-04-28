#include"dork.h"

void Database()
{
	int error = 1;
	char *token;
	string arr[200];
	char temp[100];
	//string storeEvent[6];
	int count = 0;
	string eventLocation[200];
	string eventDescription[200];
	string response[200];
	string energy[200];
	string move[200];
	string Question[200];
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
	
	for(int j = 1; j<200; j++)
	{
		for(int i = 0; i<arr[j].length(); i++)
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
			//printw("%d\t",i);
			//printw("%s\n",token);
			//storeEvent[1] = token;
			
			token = strtok(NULL,"^");
		}
		
			eventLocation[j]= array[0];
			eventDescription[j]= array[1];
			response[j]= array[2];
			energy[j]= array[3];
			move[j]= array[4];
			Question[j]= array[5];
		
		//	printw("%s\n",array[0].c_str());
		//	printw("%s\n",array[1].c_str());
		//	printw("%s\n",array[2].c_str());
		//	printw("%s\n",array[3].c_str());
		//	printw("%s\n",array[4].c_str());
		//	printw("%s\n",array[5].c_str());
		
	}
		printw("%s\n",eventLocation[1].c_str());
		refresh();
		printw("%s\n",eventDescription[3].c_str());
		refresh();
	
}

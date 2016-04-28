#include"dork.h"

void Database()
{
	int error = 1;
	char *token;
	string arr[200];
	char temp[100]= {NULL};
	string storeEvent[6];
	int count = 0;
	string eventLocation[200];
	string eventDescription[200];
	int response[200];
	int energy[200];
	string move[200];
	int Question[200];
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
	
	//for(int i = 1; i<10; i++)
	//{
		for(int i = 0; i<arr[2].length(); i++)
		{
		temp[i] = arr[2].at(i);
		}
		token = strtok(temp,"^");
		while(token != NULL)
		{
			//printw("%s\n",token);
			//storeEvent[1] = token;
			token = strtok(NULL,"^");
		}
			//printw("%s\n",storeEvent[0].c_str());
			//printw("%s\n",storeEvent[1].c_str());
			//printw("%s\n",storeEvent[2].c_str());
		
		refresh();
	//}
	
}

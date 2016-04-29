#include"dork.h"

void Database()
{
	int error = 1;
	char *token;
	char *token2;
	string arr[200];
	char temp[100];
	char eventTemp[7];
	int count = 0;
	string eventLocation[200];
	int eventLocationX[200];
	int eventLocationY[200];
	string eventDescription[200];
	string response[200];
	string energy[200];
	string move[200];
	int moveX[200];
	int moveY[200];
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
	 for(int j = 10; j<17; j++) //Location , Deliminator
	 {
	 	for(int i = 0; i<eventLocation[j].length(); i++)
		{
		eventTemp[i] = eventLocation[j].at(i);
		}
		 string store[3];
		 token2 = strtok(eventTemp,",");
		 int i=0;
		 while(token2 != NULL)
		 {
		 	store[i]= token2;
			i++;
			//printw("%s\n",token2);
			token2 = strtok(NULL,",");
		 }
		 store[0] = store[0].substr(0,3);
		 eventLocationX[j]=atoi(store[0].c_str());
		 store[1] = store[1].substr(0,3);
		 eventLocationY[j]=atoi(store[1].c_str());
	}
	ofstream test ("testing.txt");
	
		for(int i =1; i<200; i++)
		{
		test<<eventLocation[i]<<endl;
		//test<<eventDescription[i]<<endl;
		//test<<response[i]<<endl;
		//test<<energy[i]<<endl;
		//test<<move[i]<<endl;
		//test<<Question[i]<<endl;
		//test<<eventLocationX[i]<<"   ";
		//test<<eventLocationY[i]<<endl;
		}
		test.close();
}

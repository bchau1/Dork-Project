#include"dork.h"
//cloud 9
class dorkInfo{
	private:
		string name= "Unknown";
		string level = "Terrestrial";
		int rolls = 0;
		int energy= 15;
		int steps = 0;
		int age = 0;
		string nationality = "Unknown";
		int currentLocationX = 0;
		int currentLocationY = 0;
	public:
		void setName(string set_name);
		void setLevel(string set_level);
		void setEnergy(int set_energy);
		void setRolls(int set_rolls);
		void setSteps(int set_steps);
		void setAge(int set_age);
		void setNationality(string set_nationality);
		void setCurrentLocationX(int set_LocX);
		void setCurrentLocationY(int set_LocY);
		void printAll();
		string getName();
		string getLevel();
		int getEnergy();
		int getRolls();
		int getSteps();
		int getAge();
		string getNationality();
		int getCurrentLocationX();
		int getCurrentLocationY();
};
void dorkInfo::setName(string set_name)
{
	name = set_name;
}
void dorkInfo::setLevel(string set_level)
{
	level = set_level;
}
void dorkInfo::setEnergy(int set_energy)
{
	energy = set_energy;
}
void dorkInfo::setRolls(int set_rolls)
{
	rolls = set_rolls;
}
void dorkInfo::setSteps(int set_steps)
{
	steps = set_steps;
}
void dorkInfo::setAge(int set_age)
{
	age = set_age;
}
void dorkInfo::setNationality(string set_nationality)
{	
	nationality = set_nationality;
}
void dorkInfo::setCurrentLocationX(int set_LocX)
{
	currentLocationX = set_LocX;
}
void dorkInfo::setCurrentLocationY(int set_LocY)
{
	currentLocationY = set_LocY;
}
string dorkInfo::getName()
{
	return name;
}
string dorkInfo::getLevel()
{
	return level;
}	
int dorkInfo::getEnergy()
{
	return energy;
}
int dorkInfo::getRolls()
{
	return rolls;
}
int dorkInfo::getSteps()
{
	return steps;
}
int dorkInfo::getAge()
{
	return age;
}
string dorkInfo::getNationality()
{
	return nationality;
}
int dorkInfo::getCurrentLocationX()
{
	return currentLocationX;
}
int dorkInfo::getCurrentLocationY()
{
	return currentLocationY;
}
void dorkInfo::printAll()
{
	printw("Name: ");
	printw("%s\t", name.c_str());
	printw("Level: ");
	printw("%s\t", level.c_str());
	printw("Rolls: ");
 	printw("%d\t", rolls);
	printw("Energy: ");
	printw("%d\t", energy);
	printw("\n\t\t\tSteps: ");
 	printw("%d\t", steps);
	printw("Location: ");
	printw("%d", currentLocationX);
	printw(",");
 	printw("%d", currentLocationY);
	printw("\n");
}

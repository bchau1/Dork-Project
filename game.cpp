#include"dork.h"

class dorkInfo{
	private:
		string name= "Unknown";
		string level = "Terrestrial";
		int energy= 0;
		int rolls = 0;
		int steps = 0;
	public:
		void setName(string set_name);
		void setLevel(string set_level);
		void setEnergy(int set_energy);
		void setRolls(int set_rolls);
		void setSteps(int set_steps);
		void printAll();
		string getName();
		string getLevel();
		int getEnergy();
		int getRolls();
		int getSteps();
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
void dorkInfo::printAll()
{
	//addstr(name);
	cout<<"Name: " <<name<<"    "<< "Level: "<<level <<"    "<< "Rolls left: " <<rolls <<"    "<< "Engery Left: "<<energy <<"    "<< "Steps: "<<steps << endl;
	/*cout<<level;
	cout<<rolls;
	cout<<energy;
	cout<<steps;*/
}

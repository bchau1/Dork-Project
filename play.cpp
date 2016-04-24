#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>
using namespace std;
//int rollfunc(string in_str);
//int main(){
//cout << rollfunc("roll");

//return 0; }
int rollfunc(string in_str){	
int num;
	
	while (in_str != "roll"){
		cout<< "Please type 'roll' to roll the die" << endl;
	cin >> in_str;}

	if (in_str== "roll"){
		srand(time(NULL));
		num= rand() % 6 + 1;}
//cout << num << endl;
return num;}

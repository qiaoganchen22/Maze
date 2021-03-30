#include "MazePath.h"
#include <iostream>
#include <cassert>

using namespace std;
int main(){
    
    cout<<"Welcome to the path reverser program.\n";
	char m;

	do{
		string directions;

		cout << "Enter a path as a series of steps  (NSEW), press enter when done: ";
		getline(cin, directions);

		MazePath mazep(directions);
		mazep.directionsOut();

		cout << "The path is: " << directions << "\n";
		cout << mazep << "\n";

		cout << "Another (Y/N)? ";
		cin >> m;
		cin.ignore();

	}while(m=='Y'||m=='y');
    if (m!='Y'||m!='y')
      cout<< "thanks for using the path reverser\n";
      else
    return 0;
}

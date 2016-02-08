#include <string>
#include <iostream>

using namespace std;

// Still need to implement validation on user input
int getInt(string message){
	int count;
	cout << message; 
	cin >> count;
	return count;
}
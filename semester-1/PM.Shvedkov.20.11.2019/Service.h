#include <iostream>

using namespace std;

void menuText();
int enterNumber();
void displayResult(int);

int enterNumber()
{
	int n;

	cin >> n;

	return n;
}

void displayResult(int n)
{
	cout << " Answer: " << n << endl;
}

void menuText()
{
	cout << "Press 1 to work with the console." << endl;
	cout << "Press 2 to run tests." << endl;
	cout << "Press 3 to exit." << endl;
}
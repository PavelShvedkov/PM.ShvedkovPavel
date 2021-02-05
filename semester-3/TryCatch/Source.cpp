#include <iostream>

using namespace std;

int main()
{
	try
	{
		int b = 10;
		throw;
	}
	catch (int b)
	{
		cout << "exeption";
	}
}
//Лабораторная №3 Задание 7

#include <iostream>

using namespace std;
int main()
{
	float a, b, c;
	cout << " Enter number 1:= ";
	cin >> a;
	cout << " Enter number 2:= ";
	cin >> b;
	cout << " Enter number 3:= ";
	cin >> c;
	if (a > b)
	{
		if (b > c)
			cout << "Smallest number:= " << c << endl;
		else
			cout << "Smallest number:= " << b << endl;
	}
	else
	{
		if (a < c)
			cout << "Smallest number:= " << a << endl;
		else
			cout << "Smallest number:= " << c << endl;
	}
	return 0;
}

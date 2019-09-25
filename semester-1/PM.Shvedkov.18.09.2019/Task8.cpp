//Лабораторная №3 Задание 8

#include <iostream>

using namespace std;
int main()
{
	float a, b, c;
	cout << " Enter the sides of the triangle/n" << " Enter side 1:= ";
	cin >> a;
	cout << " Enter side 2:=";
	cin >> b;
	cout << " Enter side 1:=";
	cin >> c;
	if (a == b == c)
		cout << "Triangle is equilateral" << endl;
	else
	{
		if (a == b)
			cout << "Triangle is isosceles" << endl;
		else
		{
			if (a == c)
				cout << "Triangle is isosceles" << endl;
			else
			{
				if (b == c)
					cout << "Triangle is isosceles" << endl;
				else
					cout << "Triangle is versatile" << endl;
			}
		}
	}
	return 0;
}

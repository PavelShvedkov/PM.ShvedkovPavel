#include <iostream>; 
#include <cmath>;

using namespace std;

int main()
{
	int n, i = 1;
	char ok = 'y';
	double sum = 0, znam = 0;

	while (ok == 'y')
	{
		while (true)
		{
			cout << "Enter n" << endl;
			cin >> n;
			if (n > 0)
			{
				break;
			}
			cout << "Enter n>0\n";
			system("pause");
			system("cls");
		}

		while (i <= n)
		{
			znam = znam + sin(i);
			sum = sum + 1 / znam;
			i = i + 1;
		}
		cout << "Summ( " << n << " )= " << sum << endl;
		system("pause");
		system("cls");
		cout << " Press y to continue" << endl;
		cin >> ok;
		system("cls");
	}
	return 0;
}
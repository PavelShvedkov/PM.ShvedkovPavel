#include <iostream>; 

using namespace std;

int main()
{
	int n, i = 1, fact=1;
	char ok = 'y';
	double progr = 0, sum = 0;

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
			fact = fact * i;
			progr = progr + (1. / i);
			sum = sum + fact / progr;
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
#include <iostream>; 

using namespace std;

int main()
{
	int n, i = 1;
	char ok = 'y';
	long double ror = sqrt(2), sum = 0;

	cout << fixed;
	cout.precision(20);

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
			sum = ror;
			ror = sqrt(ror + 2);
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
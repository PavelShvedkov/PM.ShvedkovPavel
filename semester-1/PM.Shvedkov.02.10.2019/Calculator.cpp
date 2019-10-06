#include <iostream>

using namespace std;

int main()
{
	char ok = 't';

	while (ok == 't')
	{
		cout << " Press 'a' if summ 1 " << endl;
		cout << " Press 'b' if summ 2 " << endl;
		cout << " Press 'c' if summ 3 " << endl;
		cout << " Press 'd' if summ 4 " << endl;

		char operation;

		cin >> operation;

		int n;

		if (operation == 'a' || operation == 'b' || operation == 'c' || operation == 'd')
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
		}

		double numerator = 1, denaminator = 0, sum = 0;
		bool exist = true;

		switch (operation)
		{
		case 'a':
			for (int i = 1, k = 1; i <= n; i++, k = -k)
			{
				sum = sum + (double)k / i / ((double)i + 1);
			}
			break;
		case 'b':
			for (int i = 1; i <= n; i++)
			{
				sum = sqrt(sum + 2);
			}
			break;
		case 'c':
			for (int i = 1; i <= n; i++)
			{
				denaminator = denaminator + sin(i);
				sum = sum + 1 / denaminator;
			}
			break;

		case 'd':
			for (int i = 1; i <= n; i++)
			{
				numerator = numerator * i;
				denaminator = denaminator + (1. / i);
				sum = sum + numerator / denaminator;
			}
			break;

		default:
			exist = false;
		}

		if (exist)
		{
			cout << "Summ( " << operation << " )" << sum << endl;
		}
		else
		{
			cout << " XXXXX " << endl;
		}

		cout << " Press to restart 't'" << endl;
		cin >> ok;

		system("cls");
	}

	return 0;
}

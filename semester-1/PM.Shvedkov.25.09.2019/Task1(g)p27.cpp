#include <iostream>;

using namespace std;

int main()
{
	char ok = 'y';
	double sum = 0;
	int i = 1, k = 1, n;

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
			sum = sum + k / ((double)i * ((double)i + 1));
			i = i + 1;
			k = -k;
		}
		
		cout << "Summ( " << n << " )= " << sum << endl;
		system("pause");
		system("cls");
		cout << " Press y to continue" << endl;
		cin >> ok;
		system("cls");
	}
	
	system("cls");
	return 0;
}

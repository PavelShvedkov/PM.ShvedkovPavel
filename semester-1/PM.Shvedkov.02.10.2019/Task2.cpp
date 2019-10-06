#include <iostream>

using namespace std;

int main()
{
	int note;
	char again = 'r';
	string season;

	while (again == 'r')
	{
		while (true)
		{
			cout << " Enter number of the month ";
			cin >> note;
			if (note >= 1 && note <= 12)
			{
				break;
			}
			system("cls");
		}

		switch (note)
		{
		case 1:
		case 2:
		case 12:
			season= " Winter. Frost and sun...";
			break;
		case 3:
		case 4:
		case 5:
			season = " Spring, and i'm going for a walk again...  ";
			break;
		case 6:
		case 7:
		case 8:
			season = " Summer. Maybe go to the beach?";
			break;
		case 9:
		case 10:
		case 11:
			season = " Autumn. So charming to the eye! ";
			break;
		default:
			cout << "Not numer month.";
		}

		cout << season << endl;
		system("pause");
		system("cls");
		cout << " Press 'r' to try again." << endl;
		cin >> again;
		system("cls");
	}

	return 0;
}
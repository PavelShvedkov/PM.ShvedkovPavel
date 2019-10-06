#include <iostream>

using namespace std;

int main()
{
	int note;
	char again = 'r';
	string translate;

	while (again == 'r')
	{
		cout << " Enter note: ";
		cin >> note;

		switch (note)
		{
		case 1:
		case 2:
			translate = " One?! Was absent!";
			break;
		case 3:
		case 4:
			translate = " Two! Not satisfactorily!";
			break;
		case 5:
		case 6:
			translate = " Three, satisfactorily.";
			break;
		case 7:
		case 8:
			translate = " Four? Why not five? Good.";
			break;
		case 9:
		case 10:
			translate = " Five. Congratulations, excellent!!!";
			break;
		default:
			cout << "Not analogue note.";
		}

		cout << translate << endl;
		system("pause");
		system("cls");
		cout << " Press 'r' to try again." << endl;
		cin >> again;
		system("cls");
	}

	return 0;
}
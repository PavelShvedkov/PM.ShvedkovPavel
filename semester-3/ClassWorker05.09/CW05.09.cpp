#include <iostream>
#include "String.h"
#include "Worker.h"
#include <ctime>

using namespace std;

void menu(const Worker*, int);
void menuText();
void consoleWorkText();
void workWithConsole( const Worker*, int);
Worker* randomInitialization( const String*, const String*, const String*, int, int);
void listOfWorkersWithExceedingExperience(const Worker*, int, int, int);
void listOfWorkersWithExceedingSalary(const Worker*, int, int);
void listOfWorkersWithGivenPosition(const Worker*, int, String);

int main()
{
	int length = 6,members=10;
	String* surnames = new String[length]{ "Ivanov","Petrov","Sidorov","Kirilov","Semenov","Pavlov" };
	String* initials = new String[length]{ "G. P.","V. V.","S. P.","A. S.","P. N.","I. S." };
	String* salarys = new String[length]{ "Manager","Locksmith","Cleaner","Advertiser","Turner","Seller" };
	Worker* team = randomInitialization(surnames, initials, salarys, length, members);
	
	menu(team,members);
}

void menu( const Worker* array, int length)
{
	while (true)
	{
		char operation;

		menuText();

		cin >> operation;

		switch (operation)
		{
		case '1':
			workWithConsole(array, length);
			break;
		case '2':
			return;
		default:
			cout << "Invalid operation. Try again." << endl;
		}

		system("pause");
		system("cls");
	}
}

void menuText()
{
	cout.width(50);
	cout << "Welcome" << endl;
	cout << " Press 1 to work with the console" << endl;
	cout << " Press 2 to exit" << endl;
}
void consoleWorkText()
{
	cout.width(50);
	cout << "Work With Console" << endl;
	cout << " Press 1 to crete list of employees, work experience at this enterprise for a n number of years" << endl;
	cout << " Press 2 to crete a list of employees whose salary is higher than the specified one" << endl;
	cout << " Press 3 to crete a list of employees holding a given position" << endl;
	cout << " Press 4 to display team" << endl;
	cout << " Press 5 to exit" << endl;
}

void workWithConsole( const Worker* array, int length)
{
	while (true)
	{
		system("cls");

		char operation;
		String position;
		int startYear = 0, salary = 0,  experience = 0, currentYear = 2020;

		consoleWorkText();

		cin >> operation;

		switch (operation)
		{
		case '1':
			system("cls");

			cout << " Enter experience: ";
			cin >> experience;
			listOfWorkersWithExceedingExperience(array, length, experience, currentYear);
			break;
		case '2':
			system("cls");

			cout << " Enter minimal salary: ";
			cin >> salary;
			listOfWorkersWithExceedingSalary(array, length, salary);
			break;
		case '3':
			system("cls");

			cout << " Enter position: ";
			cin >> position;
			listOfWorkersWithGivenPosition(array, length, position);
			break;
		case '4':
			system("cls");

			for (int i = 0; i < length; i++)
			{
				cout << array[i]<<endl;
			}	
			break;
		case '5':
			return;
		default:
			cout << "Invalid operation. Try again." << endl;
		}

		system("pause");
		system("cls");
	}
}

Worker* randomInitialization(const String* surnames, const String* initials, const String* salarys, int length, int n)
{
	srand(time(NULL));

	Worker* array = new Worker[n];

	for (int i = 0; i < n; i++)
	{
		int year = 0;
		while (year <= 1950 || year >= 2020)
		{
			year = (1950 - rand() % 1950) + 1950;
		}
		array[i] = Worker(surnames[rand() % length], initials[rand() % length], salarys[rand() % length], year, abs(rand() % 1000));
	}
	
	return array;
}
void listOfWorkersWithExceedingExperience(const Worker* array, int length, int experience, int currentYear)
{
	for (int i = 0; i < length; i++)
	{
		if (!array)
		{
			throw std::invalid_argument(" The command does not exist");
		}

		if (currentYear - array[i].getStartYear() >= experience)
		{
			cout << array[i] << endl;
		}
	}
}
void listOfWorkersWithExceedingSalary(const Worker* array, int length, int minSalary)
{
	for (int i = 0; i < length; i++)
	{
		if (!array)
		{
			throw std::invalid_argument(" The command does not exist");
		}

		if (array[i].getSalary() >= minSalary)
		{
			cout << array[i] << endl;
		}
	}
}
void listOfWorkersWithGivenPosition(const Worker* array, int length, String position)
{
	for (int i = 0; i < length; i++)
	{
		if (!array)
		{
			throw std::invalid_argument(" The command does not exist");
		}

		if (array[i].getPosition() == position)
		{
			cout << array[i] << endl;
		}
	}
}

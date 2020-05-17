#include <io.h>
#include <fstream>
#include <iostream>
#include <cstring>
#include "Product.h"

using namespace std;

typedef int(*Comparer)(Product&, Product&, bool);
typedef long(*Key)(fstream&, Product&);

void initFile(char*);
void displayFile(char*);
void addToEndFile(char*);
void changeFile(char*);
int typeOfRemove();
void removeFromFile(char*);
long patternPosition(fstream&, Product&);
void initNumber(long&);
void systemFun();
void initNameFile(char*);
int typeOfSort();
void sortingFile(char*);
int sortByName(const char*, const char*, bool);
int sortByDate(Date, Date, bool);
int sortByGrade(Product&, Product&, bool);
int sortByProductName(Product&, Product&, bool);
int sortByDateOfIssue(Product&, Product&, bool);
int sortByShelfLife(Product&, Product&, bool);
int sortByCost(Product&, Product&, bool);
char toUpper(char);
bool isAlphabet(char);
bool isLower(char);
int menu();

int main()
{
	char fileName[N] = "List.bin";
	enum { Init = 1, Create, Display, Add, Change, Remove, Sort, Exit };
	while (true)
	{
		int key = menu();
		if (key == Exit)
			return 0;
		system("cls");
		switch (key)
		{
		case Init:
			initNameFile(fileName);
			systemFun();
			break;
		case Create:
			initFile(fileName);
			systemFun();
			break;
		case Display:
			displayFile(fileName);
			systemFun();
			break;
		case Add:
			addToEndFile(fileName);
			systemFun();
			break;
		case Change:
			changeFile(fileName);
			systemFun();
			break;
		case Remove:
			removeFromFile(fileName);
			systemFun();
			break;
		case Sort:
			sortingFile(fileName);
			systemFun();
			break;
		default:
			cout << "\nIncorrect input! Try again!";
			systemFun();
		}
	}
}

void initFile(char* fileName)
{
	ofstream streamOut;
	streamOut.open(fileName, ios::binary);
	if (!streamOut.is_open())
	{
		cout << "\nCan't open file to write!";
		systemFun();
		return;
	}
	int bufSize = sizeof(Product);
	Product merch;
	char ok = 'y';
	while (ok == 'y')
	{
		//man->EnterStudent();
		merch.enterProduct();//
		//streamOut.write((char*)man,bufSize);
		streamOut.write((char*)&merch, bufSize);
		cout << " If do you want to continue, press 'y' :";
		cin >> ok;
	}
	//delete man;
	streamOut.close();
}
void addToEndFile(char* fileName)
{
	ofstream streamOut(fileName, ios::app | ios::binary);
	if (!streamOut.is_open())
	{
		cout << "Can't open file to write!";
		systemFun();
		return;
	}
	int bufSize = sizeof(Product);
	Product merch;
	char ok = 'y';
	while(ok == 'y')
	{
		merch.enterProduct();
		streamOut.write((char*)&merch, bufSize);
		cout << " If do you want to continue, press 'y' : ";
		cin >> ok;
	}
	streamOut.close();
}
void changeFile(char* fileName)
{
	fstream streamInOut(fileName, ios::in | ios::out | ios::binary);
	if (!streamInOut)
	{
		cout << "Can't open file to read and write!";
		systemFun();
		return;
	}
	int bufSize = sizeof(Product);
	Product merch;
	long position;
	initNumber(position);
	streamInOut.seekp((position - 1) * bufSize, ios::beg);
	merch.enterProduct();
	streamInOut.write((char*)&merch, bufSize);
	streamInOut.close();
}
void removeFromFile(char* fileName)
{
	int mode = typeOfRemove();
	Key key;
	switch (mode)
	{
	case 1:
		key = patternPosition;
		break;
	default:
		cout << "\nIncorrect input!";
		return;
	}

	fstream streamInOut(fileName, ios::in | ios::out | ios::binary);
	if (!streamInOut.is_open())
	{
		cout << "Can't open file to read and write!";
		systemFun();
		return;
	}
	streamInOut.seekp(0, ios::end);
	long N = streamInOut.tellp();
	int bufSize = sizeof(Product);
	Product merch;

	cout << " Enter pattern for remove: " << endl;
	merch.enterProduct();

	long position = key(streamInOut, merch);

	while (position >= 0)
	{
		position = key(streamInOut, merch);
		streamInOut.seekp(position * bufSize, ios::beg);
		while (streamInOut.read((char*)&merch, bufSize))
		{
			streamInOut.seekp(-2 * bufSize, ios::cur);
			streamInOut.write((char*)&merch, bufSize);
			streamInOut.seekp(bufSize, ios::cur);
		}
	}
	streamInOut.close();
	int DiskriptorFile = open(fileName, 2);//*
	chsize(DiskriptorFile, N - bufSize);//*
	close(DiskriptorFile);//* 
}
int typeOfRemove()
{
	int k;
	cout << "\n Enter number - file remove mode:"
		"\n 1 - REMOVE PATTERN \n";
	cin >> k;
	return k;
}
long patternPosition(fstream& stream, Product& pattern)
{
	Product buffer;
	int buffSize = sizeof(Product);
	long position = 0;

	while (stream.read((char*)&buffer, buffSize))
	{
		if (buffer == pattern)
		{
			position = stream.tellp();
			stream.seekp(-position * buffSize, ios::cur);
			return position;
		}
	}
	return -1;
}
void sortingFile(char* fileName)
{
	int mode = typeOfSort();
	Comparer comparer;
	switch (mode)
	{
	case 1:
		comparer = sortByProductName;
		break;
	case 2:
		comparer = sortByGrade;
		break;
	case 3:
		comparer = sortByDateOfIssue;
		break;
	case 4:
		comparer = sortByShelfLife;
		break;
	case 5:
		comparer = sortByCost;
		break;
	default:
		cout << "\nIncorrect input!";
		return;
	}

	bool flag = true;
	while (flag)
	{
		fstream streamInOut(fileName, ios::in | ios::out | ios::binary);
		if (!streamInOut.is_open())
		{
			cout << "Can't open file to read and write!";
			systemFun();
			return;
		}
		flag = false;
		Product merchOne, merchTwo;
		int bufSize = sizeof(Product);
		streamInOut.read((char*)&merchOne, bufSize);
		while (streamInOut.read((char*)&merchTwo, bufSize))
		{
			if (comparer(merchTwo, merchOne, false) < 0)
			{
				streamInOut.seekp(-2 * bufSize, ios::cur);
				streamInOut.write((char*)&merchTwo, bufSize);
				streamInOut.write((char*)&merchOne, bufSize);
				flag = true;
			}

			streamInOut.seekp(-bufSize, ios::cur);
			streamInOut.read((char*)&merchOne, bufSize);
		}
		streamInOut.close();
	}
}
void displayFile(char* fileName)
{
	ifstream streamIn(fileName, ios::binary);
	if (!streamIn.is_open())
	{
		cout << "Can't open file to read!";
		systemFun();
		return;
	}
	int bufSize = sizeof(Product);
	Product* merch = new Product;
	while (streamIn.read((char*)merch, bufSize))
	{
		merch->displayProduct();
	}
	streamIn.close();
}
void initNumber(long& n)
{
	cout << "Enter the number of record:" << endl;
	cin >> n;
	system("cls");
}
void systemFun()
{
	cout << endl;
	system("pause");
	system("cls");
}
void initNameFile(char* fileName)
{
	cout << "Enter the name of file: " << endl;
	cin.ignore();
	cin.getline(fileName, 256, '\n');
	system("cls");
}
int menu()
{
	int k;
	cout << "\n Enter the number - the mode of operations with file:"
		"\n 1 - INITIALIZATION THE NAME OF FILE"
		"\n 2 - FORMATION OF THE FILE"
		"\n 3 - VIEWING OF CONTENTS OF THE FILE"
		"\n 4 - ADD AN ELEMENT TO AND OF FILE"
		"\n 5 - CHANGE THE ELEMENT IN THE FILE"
		"\n 6 - REMOVE THE ELEMENT IN THE FILE"
		"\n 7 - SORTING THE ELEMENT IN THE FILE"
		"\n 8 - EXIT\n";
	cin >> k;
	return k;
}
int typeOfSort()
{
	int k;
	cout << "\n Enter number - file sort mode:"
		"\n 1 - SORT BY NAME"
		"\n 2 - SORT BY GRADE"
		"\n 3 - SORT BY ISSUE DATE"
		"\n 4 - SORT BY SHELF LIFE"
		"\n 5 - SORT BY COST \n";
	cin >> k;
	return k;
}
int sortByDate(Date lhs, Date rhs, bool option)
{
	if (option)
	{
		//TODO
	}

	if (lhs.getYear() == rhs.getYear())
	{
		if (lhs.getMonth() == rhs.getMonth())
		{
			return (lhs.getDay() - rhs.getDay());
		}
		else
		{
			return (lhs.getMonth() - rhs.getMonth());
		}
	}
	else
	{
		return (lhs.getYear() - rhs.getYear());
	}
}
int sortByDateOfIssue(Product& lhs, Product& rhs, bool option)
{
	Date lhd = lhs.getDateOfIssue(), rhd = rhs.getDateOfIssue();

	return sortByDate(lhd, rhd, option);
}
int sortByShelfLife(Product& lhs, Product& rhs, bool option)
{
	Date lhd = lhs.getShelfLife(), rhd = rhs.getShelfLife();

	return sortByDate(lhd, rhd, option);
}
int sortByCost(Product& lhs, Product& rhs, bool option)
{
	return lhs.getCost() - rhs.getCost();
}
int sortByName(const char* lhs, const char* rhs, bool ordinal)
{
	if (lhs == nullptr)
	{
		throw std::invalid_argument(" String can't be null");
	}

	if (rhs == nullptr)
	{
		throw std::invalid_argument(" String can't be null");
	}

	int lhsLenght = strlen(lhs);

	int rhsLenght = strlen(rhs);

	for (int i = 0; i <= lhsLenght || i <= rhsLenght; i++)
	{
		char lHelper = ordinal ? lhs[i] : toUpper(lhs[i]);
		char rHelper = ordinal ? rhs[i] : toUpper(rhs[i]);


		if (lHelper == rHelper)
		{
			continue;
		}

		if (lHelper > rHelper)
		{
			return 1;
		}
		else
		{
			return -1;
		}
	}

	if (lhsLenght == rhsLenght)
	{
		return 0;
	}
}
int sortByGrade(Product& merchOne, Product& merchTwo, bool ordinal)
{
	const char* lhs = merchOne.getGrade();
	const char* rhs = merchTwo.getGrade();

	return sortByName(lhs, rhs, ordinal);
}
int sortByProductName(Product& merchOne, Product& merchTwo, bool ordinal)
{
	const char* lhs = merchOne.getProductName();
	const char* rhs = merchTwo.getProductName();

	return sortByName(lhs, rhs, ordinal);
}
char toUpper(char symbol)
{
	if (isAlphabet(symbol) && isLower(symbol))
	{
		return symbol - 32;
	}

	return symbol;
}
bool isAlphabet(char symbol)
{
	return 'A' <= symbol && symbol <= 'Z' || 'a' <= symbol && symbol <= 'z';
}
bool isLower(char symbol)
{
	return 'a' <= symbol && symbol <= 'z';
}
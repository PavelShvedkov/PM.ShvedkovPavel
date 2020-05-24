#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include "WordNumber.h"
#include "WorkWithStrings.h"

using namespace std;
using namespace myStrings;

char* readOneWord(const char*);
int button();
void SystemFun();

int main()
{
	const int N = 256;
	int count = 0;
	char text[] = "WarAndPeace.txt";
	char words[] = "WordsInWNP.txt";
	char result[] = "result.txt";
	char result2[] = "result2.txt";


	while (true)
	{
		int key = button();
		if (key == 3)
		{
			return 0;
		}
		switch (key)
		{
		case 1:
		{
			char* pathToText = new char[N];

			cout << " Enter file namå with text: ";
			cin >> pathToText;

			char* pathToList = new char[N];

			cout << " Enter combo file namå: ";
			cin >> pathToList;

			ifstream inWords(pathToList);
			ofstream outResult(result, ios::binary);

			bool isCaseSens = 0;

			cout << " Is wordlist search case sensitive ?" << endl << "1 - yes, 0 - no" << endl;
			cin >> isCaseSens;

			while (!inWords.eof())
			{
				ifstream inText(pathToText);
				char* bufferWord = new char[N];
				inWords >> bufferWord;
				count = 0;

				while (!inText.eof())
				{
					char* bufferText = new char[N];
					inText >> bufferText;

					if (searchFirstSubstringIndex(bufferText, bufferWord, isCaseSens) != -1)
					{
						++count;
					}
					delete[]bufferText;
				}

				if (bufferWord[0] != '\0')
				{
					WordNumber two(bufferWord, count);
					outResult.write((char*)&two, sizeof(WordNumber));
					delete[]bufferWord;
				}
				inText.close();
			}
			inWords.close();
			outResult.close();

			SystemFun();
			break;
		}
		case 2:
		{
			ifstream inResult(result, ios::binary);
			WordNumber* trek = new WordNumber;

			while (inResult.read((char*)trek, sizeof(WordNumber)))
			{
				trek->display();
			}

			inResult.close();

			SystemFun();
			break;
		}
		default:
			cout << "\nIncorrect input! Try again!";
			 SystemFun();
			break;
		}
	}
}

char* readOneWord(const char* path)
{
	ifstream in(path);

	char* buffer = new char[100];
	char symbol[2] = "a";

	while (symbol[0] != ' ')
	{
		in.seekg(sizeof(char) * 4);
		in >> buffer;
		in >> symbol;
		strcpy(buffer, symbol);
	}

	return buffer;
}

int button()
{
	int k;
	cout << "\n Enter the number - the mode of operations with file:"
		"\n 1 - FIND WORDS IN TEXT"
		"\n 2 - DISPLAY RESULT FILE"
		"\n 3 - EXIT\n";
	cin >> k;
	return k;
}

void SystemFun()
{
	cout << endl;
	system("pause");
	system("cls");
}

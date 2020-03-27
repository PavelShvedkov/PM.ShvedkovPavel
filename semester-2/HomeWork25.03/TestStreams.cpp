#include <iostream>
#include <fstream>
#include <string>
#include "WorkWithStrings.h"

using namespace std;
using namespace myStrings;

void createFile(const string&, int);
void showContentsFile(string);
void createNAddToFile(const string&, string);
void deleteWordsByLengthInFile(const string&,string&,int);


/*В текстовом файле имеется набор строк.
Файл можно писать вручную. Удалить из строки все слова заданной длины
(т.е.на выходе получаем новый файл без заданных слов).
Предполагается работа в цикле с несколькими строками.Концом строки принять терминирующий ‘\0’.*/
/*The text file has a set of lines.
The file can be written manually. Delete all words of a given length from a string
(i.e., at the output we get a new file without the given words).
It is supposed to work in a loop with several lines. At the end of the line, accept the terminating*/


int main()
{
	int n = 4;
	const string path1 = "Source.txt";
	string path2 = "NewFile.txt";
	string sourceInfo = "The text file has a set of line\nThe file can be written manually.Delete all words of a given length from a string\n(i.e., at the output we get a new file without the given words).\nIt is supposed to work in a loop with several lines.At the end of the line, accept the terminating\n";

	createNAddToFile(path1, sourceInfo);
	createFile(path2, 5);

	showContentsFile(path1);
	showContentsFile(path2);

	deleteWordsByLengthInFile(path1, path2, n);

	showContentsFile(path1);
	showContentsFile(path2);
}

void createFile(const string& path, int n)
{
	ofstream sout;

	sout.open(path, ios::out);

	if (!sout.is_open())
	{
		cout << "Cannot open file to write!" << endl;
		system("pause");
		exit(1);
	}

	cout << " File " << path << " is created." << endl;

	sout.close();
}

void showContentsFile(string path)
{
	fstream stream;
	stream.open(path, ios::in || ios::app);
	if (!stream.is_open())
	{
		cout << " Cannot open file " << path << " to read!" << endl;
		system("pause");
		exit(1);
	}

	string temp;

	cout << " File contents " << path << ":" << endl;

	while (!stream.eof())
	{
		temp = " ";
		getline(stream, temp);
		cout << temp << endl;
	}

	stream.close();
}

void createNAddToFile(const string& path,string info)
	{
	ofstream sout;

	sout.open(path, fstream::out | fstream::app);

	if (!sout.is_open())
	{
		cout << "Cannot open file to write!" << endl;
		system("pause");
		exit(1);
	}

	sout << info << endl;

	cout << " Information is added to the file " << path << endl;

	sout.close();
}

void deleteWordsByLengthInFile(const string& sourcePath,string& newPath,int length)
{
	ifstream chteniye;
	ofstream zapys;

	chteniye.open(sourcePath, fstream::in);
	zapys.open(newPath, fstream::out);



	if (!chteniye.is_open())
	{
		cout << "\nCannot open file to formating!\n";
		system("pause");
		exit(1);
	}

	if (!zapys.is_open())
	{
		cout << "\nCannot open file to formating!\n";
		system("pause");
		exit(1);
	}

	string buffer1, buffer2;

	while (!chteniye.eof())
	{
		buffer2 = "";
		getline(chteniye, buffer1);

		while (findFirstIndexSubstringLength(buffer1, length) != -1)
		{
			buffer2 = deleteFirstSubstringGivenLength(buffer1, length);
			buffer1 = buffer2;
		}

		zapys << buffer2<<endl;
	}

	chteniye.close();
	zapys.close();//v.1
}
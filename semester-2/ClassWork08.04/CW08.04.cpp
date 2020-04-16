#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>

using namespace std;

void merge(char*, char*, ostream&);

int main()
{
	char path1[] = "source1.txt";
	char path2[] = "source2.txt";
	const char* destination = "out.txt";
	ofstream out(destination);

	merge(path1, path2, out);
	merge(path1, path2, cout);
	out.close();
}

void merge(char* sourcePath1, char* sourcePath2, ostream& out)
{
	ifstream in1(sourcePath1);
	ifstream in2(sourcePath2);
	int buffNumber1 = 0;
	int buffNumber2 = 0;

	in1 >> buffNumber1;
	in2 >> buffNumber2;

	while (in1 && in2)
	{
		if (buffNumber1 > buffNumber2)
		{
			out << buffNumber2 << ' ';
			in2 >> buffNumber2;
		}
		else
		{
			out << buffNumber1 << ' ';
			in1 >> buffNumber1;
		}
	}

	if (in1.eof())
	{
		while (in2)
		{
			out << buffNumber2 << ' ';
			in2 >> buffNumber2;
		}
	}
	else
	{
		while (in1)
		{
			out << buffNumber1 << ' ';
			in1 >> buffNumber1;
		}
	}

	in1.close();
	in2.close();
}




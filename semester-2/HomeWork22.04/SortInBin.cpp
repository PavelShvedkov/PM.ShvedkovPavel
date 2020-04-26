#include <iostream>
#include <fstream>

using namespace std;

void writeInBinRandom(ofstream&, int);
void writeInBin(ofstream&,int*, int);
void displayBin(ifstream&);
void sortInBinV1(const char* );
void sortInBinV2(const char*);
int lengthBinFile(fstream& );

int main()
{
	const char path[] = "test.bin";

	ofstream out(path, ios::binary);
	writeInBinRandom(out, 5);
	out.close();

	ifstream in(path, ios::binary);
	displayBin(in);
	in.close();

	sortInBinV1(path);

	in.open(path, ios::binary);
	displayBin(in);
	in.close();
}

void writeInBin(ofstream& out, int* array, int size)
{
	int typeSize = sizeof(int);

	for (int i = 0; i < size; i++)
	{
		out.write((char*)array[i], typeSize);
	}
}

void writeInBinRandom(ofstream& out, int count)
{
	int typeSize = sizeof(int);

	for (int i = 0; i < count; i++)
	{
		int buffer = rand() % 100;

		out.write((char*)&buffer, typeSize);
	}
}

void displayBin(ifstream& in)
{
	int buff = 0;
	int typeSize = sizeof(int);

	while (in.read((char*)&buff, typeSize))
	{
		cout << buff << '\t';
	}

	cout << endl;
}

void sortInBinV1(const char* path)
{
	fstream stream(path, ios::binary | ios::out | ios::in);

	bool isSorted = false;
	int left = 0, right = 0;
	int typeSize = sizeof(int);

	stream.seekp(0, ios::end);
	int lengthBinFile = stream.tellp() / typeSize;
	stream.seekp(0, ios::beg);

	while (!isSorted)
	{

		isSorted = true;

		stream.read((char*)&left, typeSize);

		while (stream.read((char*)&right, typeSize))
		{
			if (left > right)
			{
				stream.seekp(-2 * typeSize, ios::cur);
				stream.write((char*)&right, typeSize);
				stream.write((char*)&left, typeSize);
				isSorted = false;
			}

			stream.seekp(-1 * typeSize, ios::cur);
			stream.read((char*)&left, typeSize);
		}

		stream.seekp(-lengthBinFile,ios::end);
	}

	stream.close();
}

void sortInBinV2(const char* path)
{
	bool isSorted = false;
	int left = 0, right = 0;
	int typeSize = sizeof(int);

	while (!isSorted)
	{
		fstream stream(path, ios::binary | ios::out | ios::in);

		isSorted = true;

		stream.read((char*)&left, typeSize);

		while (stream.read((char*)&right, typeSize))
		{
			if (left > right)
			{
				stream.seekp(-2 * typeSize, ios::cur);
				stream.write((char*)&right, typeSize);
				stream.write((char*)&left, typeSize);
				isSorted = false;
			}

			stream.seekp(-1 * typeSize, ios::cur);
			stream.read((char*)&left, typeSize);
		}

		stream.close();
	}
}

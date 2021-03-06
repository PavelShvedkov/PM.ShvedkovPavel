#include <iostream>
#include "Service.h"
#include "WorkWithArrays.h"
#include "WorkWithNumbers.h"
#include <ctime>

using namespace std;


int main()
{
	int const n = 100;
	char subStringInsertiable[] = "dors";
	char subStringRemovable[] = "kar";
	char string[] = "Kar kar krya mu kar maooo mu maooo";

	int sizesRelations = compressionStrings(subStringInsertiable, subStringRemovable);
	int sizeS = sizeString(string), sizeSSR = sizeString(subStringRemovable), sizeSSI = sizeString(subStringInsertiable);

	for (int i = 0, index; string[i] != '\0'; i++)
	{
		index = searchFirstSubstringIndex(string, subStringRemovable);

		if (index == -1)
		{
			break;
		}

		switch (sizesRelations)
		{
		case 1:
			for (int k = 0; k < sizeSSR; k++, index++, i++)
			{
				string[index] = subStringInsertiable[k];
			}
			continue;
		case 2:
			for (int k = 0; string[index] != '\0'; k++, index++, i++)
			{
				string[index + sizeSSR + sizeSSI - sizeSSR] = string[index + sizeSSR];

				if (k < sizeSSI)
				{
					string[index] = subStringInsertiable[k];
				}
			}
			continue;
		case 3:
			for (int k = 0; string[index] != '\0'; k++, index++, i++)
			{
				string[index + sizeSSR + sizeSSR- sizeSSI+1] = string[index + sizeSSR-1];

				if (k < sizeSSI)
				{
					string[index] = subStringInsertiable[k];
				}
			}
			continue;
			break;
		}
	}

	cout << string << endl;
	cout << string[13] << endl;
	//cout << searchSubstringIndex(string,lenght,subString,lenghtSubString) << endl;
}



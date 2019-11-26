#include <iostream>
#include "Service.h"
#include "WorkWithArrays.h"
#include "WorkWithNumbers.h"
#include <ctime>

using namespace std;


int main()
{
	int const n = 100;
	char subStringInsertiable[] = "do";
	char subStringRemovable[] = "kar";
	char string[] = "Karkarkryamukarmaooomumaooo";

	bool sizesRelations = equivalenceStrings(subStringInsertiable, subStringRemovable);
	int sizeS = sizeString(string), sizeSSR = sizeString(subStringRemovable), sizeSSI = sizeString(subStringInsertiable);

	for (int i = 0, index; string[i] != '\0'; i++)
	{
		index = searchFirstSubstringIndex(string, subStringRemovable);

		if (index == -1)
		{
			break;
		}

		if (sizesRelations)
		{
			for (int k = 0; k < sizeSSR; k++, index++, i++)
			{
				string[index] = subStringInsertiable[k];
			}
			continue;
		}
		else
		{
			for (int k = 0; string[index] != '\0'; k++, index++, i++)
			{
				if (k < sizeSSI)
				{
					string[index] = subStringInsertiable[k];
				}

				string[index + sizeSSR + sizeSSR - sizeSSI+1] = string[index + sizeSSR +1];
			}
			continue;
		}
	}

	cout << string << endl;
	cout << string[13] << endl;
	//cout << searchSubstringIndex(string,lenght,subString,lenghtSubString) << endl;
}



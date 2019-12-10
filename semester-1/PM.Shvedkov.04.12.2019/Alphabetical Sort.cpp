#include <iostream>
#include "Service.h"
#include "WorkWithArrays.h"
#include"WorkWithNumbers.h"
#include "WorkWithStrings.h"

using namespace std;

int main()
{
	char source[] = "Learn how to use Visual..,.,.,.,/. Studio to@@@@ develop,,,,,, // /.,., applications,"
		"services, and tools? in the          language of your choice, for"
		"your, platforms and. devices";

	int k = 0;
	char** words = createList(source, k);
	
	alphabetInsertSortList(words, k);
	displayList(words, k);
	 
	return 0;
}

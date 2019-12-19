#include <iostream>
#include "Service.h"
#include "WorkWithArrays.h"
#include "WorkWithNumbers.h"
#include "WorkWithStrings.h"

using namespace std;
using namespace myArrays;
using namespace myStrings;

int main()
{
	char string[] = "great ball take hub least try";
	
	cout<<deleteSubstringGivenLength(string, 4)<<endl;

	return 0;
}


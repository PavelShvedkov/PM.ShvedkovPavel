#include <iostream>
#include "TemplateWorker.h"
#include "Integer.h"
#include "Date.h"

using namespace std;

int main()
{
	string fname = "john", lname = "smith", inits = "JS";
	Integer  sYear = 2019, salary = 300;
	Integer& psYear = sYear, &psalary = salary;
	Date start(1, 9, 2019);
	TemplateWorker<Date, Integer> worker1(fname,lname, inits,start,salary);
	TemplateWorker<Integer, string> worker2(fname, lname, inits, psYear, "much");	
	TemplateWorker<int, double> worker3(fname, lname, inits, 2000, 12.3);

	cout << worker1<<endl<<worker2<<endl<<worker3;
}

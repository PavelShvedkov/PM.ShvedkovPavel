#include <fstream>

using namespace std;

class Integer
{
public:
	Integer() :item(0)
	{

	}
	Integer(int);

	void setItem(int);

	Integer operator +(const Integer&);
	Integer operator -(const Integer&);

	friend ostream& operator <<(ostream& out, const Integer&);
	friend istream& operator >>(istream& in,  Integer&);

private:
	int item;
};


// ������������ ������ 3. ������� 11 �)

#include <iostream>

using namespace std;
int main()
{
	float x, y;
	cout << " Enter coordinates\n X:= ";
	cin >> x;
	cout << " Y:= ";
	cin >> y;
	if (x >= 0 and x * x + y * y <= 1)
	{
		cout << "Point inside the figure" << endl;
	}
	else
	{
		if (-1 <= x <= 0 and x * x + y * y <= abs(x) + abs(y))
			cout << "Point inside the figure" << endl;

		else
			cout << "Point outside the figure" << endl;
	}
	return 0;
}
#include "ctime"
#include <iostream>

using namespace std;

struct point
{
	double x, y;

	point()
	{
		//srand(time(0));

		x = rand() % 100;
		y = rand() % 100;
	}

	point(double a, double b)
	{
		x = a;
		y = b;
	}

	void move(double deltaX, double deltaY)
	{
		x += deltaX;
		y += deltaY;
	}

	void display()
	{
		cout << "( " << x << " ; " << y << " )" << endl;
	}

	void enter()
	{
		cout << "Enter x - coordinate:";
		cin >> x;
		cout << "Enter y - coordinate:";
		cin >> y;
	}

	double length()
	{
		return sqrt(x * x + y * y);
	}
};

double* initLengths(point*, int);
void enterPoint(point&);
void displayPoint(const point&);
void enterPoint(point*);
void displayPoint(const point*);
point* initArray(int,bool);
void displayPoints(point*, int);
void sortVectors(point*, int);
void sortVectors(point*, double*, int);
void swap(point*, point*);
void fillingArray(point*, int);
void shuffleArray(point*, int);
bool areEqual(point*, int, point*, int);

bool areEqual(point* lhs, int n, point* rhs, int m)
{
	if (n != m)
	{
		return false;
	}

	for (point* p = lhs, *q = rhs; p < lhs + n; p++, q++)
	{
		if (p->length() != q->length())
		{
			return false;
		}
	}

	return true;
}

void shuffleArray(point* array, int size)
{
	int shuffles = size;

	for (int index1 = 0, index2 = 0, i = 0; i <= shuffles; i++)
	{
		index1 = ((rand() / rand()) % size + ((rand() * 22) / 9)) % size;
		index2 = ((rand() / rand()) % size + ((rand() * 22) / 9)) % size;
		swap(array[index1], array[index2]);
	}

}

double* initLengths(point* coordinates, int n)
{
	double* lengths = new double;

	for (int i = 0; i < n; i++)
	{
		lengths[i] = coordinates[i].length();
	}

	return lengths;
}

void swap(point* a, point* b)
{
	point t = *a;
	*a = *b;
	*b = t;
}

void sortVectors(point* coordinates, double* lengths, int n)
{
	bool isSorted = false;
	int i = 0;

	while (!isSorted)
	{
		isSorted = true;
		for (int j = n - 1; j > i; j--)
		{
			if (lengths[j] < lengths[j - 1])
			{
				swap(lengths[j], lengths[j - 1]);
				swap(coordinates[j], coordinates[j - 1]);
				isSorted = false;
			}
		}
		i++;
	}
}

void sortVectors(point* coordinates, int n)
{
	bool isSorted = false;
	int i = 0;

	while (!isSorted)
	{
		isSorted = true;
		for (int j = n - 1; j > i; j--)
		{
			if (coordinates[j].length() < coordinates[j - 1].length())
			{
				swap(coordinates[j], coordinates[j - 1]);
				isSorted = false;
			}
		}
		i++;
	}
}

void enterPoint(point& point)
{
	std::cout << "Enter x - coordinate:";
	std::cin >> point.x;
	std::cout << "Enter y - coordinate:";
	std::cin >> point.y;
}

void displayPoint(const point& point)
{
	cout << "( " << point.x << " ; " << point.y << " )" << " ";
}

void enterPoint(point* p)
{
	cout << "Enter x - coordinate:";
	cin >> (*p).x;
	cout << "Enter y - coordinate:";
	cin >> p->y;
}

void displayPoint(const point* p)
{
	cout << "( " << p->x << " ; " << p->y << " )" << std::endl;
}

point* initArray(int n,bool test=0)
{
	if (n <= 0)
	{
		throw out_of_range("Count of elements can not be less or equal than zero!");
	}

	point* points = new point[n];

	if (test)
	{
		for (int i = 0; i < n; i++)
		{
			points[i] = point(i, i + 1);
		}
	}

	return points;
}

void displayPoints(point* points, int n)
{
	for (int i = 0; i < n; i++)
	{
		//displayPoint(points[i]);
		points[i].display();
	}
}

void fillingArray(point* vectors, int n)
{
	for (int i = 0; i < n; i++)
	{
		vectors[i].enter();
	}
}



#include "Product.h"

Product::Product(const char* name, const char* grade, Date issueDate, int shelfLife, int cost)
{
	setProduct(name, grade, issueDate, shelfLife, cost);
}

void Product::setProductName(const char* name)
{
	if (!name)
	{
		throw std::invalid_argument(" Invalid product name");
	}
	if (strlen(name) > N)
	{
		throw std::invalid_argument(" Product name too big");
	}

	strcpy(productName, name);
}

void Product::setGrade(const char* name)
{
	if (!name)
	{
		throw std::invalid_argument(" Invalid product grade");
	}
	if (strlen(name) > N)
	{
		throw std::invalid_argument(" Product grade too big");
	}

	strcpy(grade, name);
}

void Product::setDateOfIssue(Date date)
{
	this->dateOfIssue = date;
}

void Product::setShelfLife(int date)
{
	Date buff = dateOfIssue;
	
	buff.setYear(dateOfIssue.getYear() + date);
	this->shelfLife = buff;
}

void Product::setCost(int cost)
{
	if (cost < 0)
	{
		throw std::invalid_argument(" Cost of product can't be less than zero");
	}

	this->cost = cost;
}

void Product::setProduct(const char* name, const char* grade, Date issueDate, int shelfLife, int cost)
{
	setProductName(name);
	setGrade(grade);
	setDateOfIssue(issueDate);
	setShelfLife(shelfLife);
	setCost(cost);
}

char* Product::getProductName() const
{
	char* buffer = new char[strlen(productName) + 1];
	strcpy(buffer, productName);
	return buffer;
}

char* Product::getGrade() const
{
	char* buffer = new char[strlen(grade) + 1];
	strcpy(buffer, grade);
	return buffer;
}

Date Product::getDateOfIssue() const
{
	return dateOfIssue;
}

Date Product::getShelfLife() const
{
	return shelfLife;
}

int Product::getCost() const
{
	return cost;
}

bool Product::operator==(const Product& other) const
{
	if (this->getProductName()==other.getProductName())
	{
		if (this->getGrade() == other.getGrade())
		{
			if (this->getDateOfIssue()==other.getDateOfIssue())
			{
				if (this->getShelfLife()==other.getShelfLife())
				{
					if (this->getCost()==other.getCost())
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}

void Product::enterProduct()
{
	const int N = 256;
	int cost = 0, shelfLife=0;
	char productName[N] = "", grade[N] = "";
	Date dateOfIssue;
	cout << "Enter name of product:";
	cin.ignore();
	cin.getline(productName, N, '\n');
	cout << "Enter grade of product:";
	cin.getline(grade, N, '\n');
	cout << "Enter date of product issue:";
	cin >> dateOfIssue;
	cout << "Enter shelf life of product:";
	cin >> shelfLife;
	cout << " Enter cost of product:";
	cin >> cost;
	this->setProduct(productName, grade, dateOfIssue, shelfLife, cost);
}

void Product::displayProduct()
{
	cout <<endl<< "----------------------------------------------------" << endl;
	cout << endl << " Product name: " << getProductName();
	cout << endl << " Grade of product: " << getGrade() << endl;
	cout.precision(3);
	Date dateIssue = getDateOfIssue();
	Date shelfLife = getShelfLife();
	cout << " Date of issue: " << dateIssue << endl;
	cout << " Shelf life: " << shelfLife << endl;
	cout << " Product cost: " << getCost();
}

ofstream& operator<<(ofstream& out, const Product&other)
{
	out << "----------------------------------------------------" << endl;
	out << endl << " Product name: " << other.getProductName();
	out << endl << " Grade of product: " << other.getGrade() << endl;
	out.precision(3);
	Date dateIssue = other.getDateOfIssue();
	Date shelfLife = other.getShelfLife();
out << " Date of issue: " << dateIssue << endl;
	out << " Shelf life: " << shelfLife << endl;
	out << " Product cost: " << other.getCost();

	return out;
}

#include <iostream>

class WordNumber
{
public:
	static const int N = 25;
	
	WordNumber() {};
	WordNumber(char*,int);
	WordNumber(WordNumber&);

	void setWord(char*);
	void setNumber(int);
	void display()const;
	char* getWord()const;
	int getNumber()const;

private:
	char word[N];
	int number;
};


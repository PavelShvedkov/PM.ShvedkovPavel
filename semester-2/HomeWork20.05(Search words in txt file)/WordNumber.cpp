#define _CRT_SECURE_NO_WARNINGS
#include "WordNumber.h"
#include <iostream>

using namespace std;

WordNumber::WordNumber(char* word, int number)
{
	setWord(word);
	setNumber(number);
}

WordNumber::WordNumber(WordNumber& other)
{
	int length=strlen(other.getWord());
	char* newWord = new char[length + 1];
	strcpy(newWord, other.getWord());
	this->setWord(newWord);
	this->setNumber(other.getNumber());
}

void WordNumber::setWord(char* word)
{
	strcpy(this->word, word);
}
void WordNumber::setNumber(int number)
{
	this->number = number;
}
void WordNumber::display()const
{
	cout << getWord() << '\t' << getNumber()<<endl;
}
char* WordNumber::getWord()const
{
	int length=strlen(word);
	char* buf = new char[length + 1];

	strcpy(buf, word);

	return buf;
}
int WordNumber::getNumber()const
{
	return this->number;
}
#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include "User.h"
#include "Date.h"

using namespace std;

int main()
{
	User me;
	me.registry("Pavel", 0, Date(22,9,2001),male);
	me.usersOnline();
	me.profileInfo();
}
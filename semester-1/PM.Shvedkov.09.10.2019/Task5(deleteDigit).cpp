int modifiedNumber(int number, short removable)
{
	int reflection = 0;

	while (number)
	{
		if (number % 10 != removable)
		{
			reflection = reflection * 10 + number % 10;
		}
		number /= 10;
	}

	while (reflection)
	{
		number = number * 10 + reflection % 10;
		reflection /= 10;
	}

	return number;
}

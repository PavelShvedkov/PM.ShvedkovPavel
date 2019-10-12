int trancfer(int number, short removable, short deputy)
{
	int mirrorImage = 0;

	while (number)
	{
		if (number % 10 == removable)
		{
			mirrorImage = mirrorImage * 10 + deputy;
		}
		else
		{
			mirrorImage = mirrorImage * 10 + number % 10;
		}

		number /= 10;
	}

	while (mirrorImage)
	{
		number = number * 10 + mirrorImage % 10;
		mirrorImage /= 10;
	}

	return number;
}


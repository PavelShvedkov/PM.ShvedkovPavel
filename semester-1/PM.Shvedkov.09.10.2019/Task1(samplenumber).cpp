bool sampleNumber(int number)
{
	bool check = false;

	number = abs(number);

	for (int k = 2; k < number; k++)
	{
		if (number % k == 0)
		{
			return check;
		}
		
			check = true;
	}
	return check;
}

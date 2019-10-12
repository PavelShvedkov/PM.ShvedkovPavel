bool sampleNumber(int number)
{
	bool check = true;

	number = abs(number);

	for (int k = 2; k < number; k++)
	{
		if (number % k != 0)
		{
			continue;
		}
		else
		{
			check = false;
			break;
		}
	}
	return check;
}
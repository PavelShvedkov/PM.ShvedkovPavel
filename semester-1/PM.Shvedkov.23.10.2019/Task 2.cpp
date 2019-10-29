int zeroInBinary(int decimalNumber)
{
	int counter = 0;

	for (; decimalNumber > 0; decimalNumber /= 2)
	{
		if (decimalNumber % 2 == 0)
		{
			counter++;
		}
	}
	return counter;
}
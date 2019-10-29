int unitsInBinary(int decimalNumber)
{
	int counter = 0;

	for (; decimalNumber > 0; decimalNumber /= 2)
	{
		if (decimalNumber % 2)
		{
			counter++;
		}
	}
	return counter;
}
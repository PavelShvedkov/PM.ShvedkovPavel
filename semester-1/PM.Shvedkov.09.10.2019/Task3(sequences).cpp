void sequence(int number, short& requality, short& rmore, short& rsmaller, short& rmorePerUnit, short& rsmallerPerUnit)
{
	int count = 0;

	number = abs(number);

	for (; number >= 10; number /= 10)
	{
		if ((number % 10) < ((number / 10) % 10))
		{
			((number % 10) == (((number / 10) % 10) - 1)) ? rsmallerPerUnit++ : rsmaller++;
		}
		else
		{
			if ((number % 10) > ((number / 10) % 10))
			{
				((number % 10) == (((number / 10) % 10) + 1)) ? rmorePerUnit++ : rmore++;
			}
			else
			{
				requality++;
			}
		}

	}
}

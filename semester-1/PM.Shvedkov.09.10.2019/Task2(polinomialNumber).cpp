bool polindromTaste(int number)
{
	int mirrorImage = 0;

	while (int clone=number)
	{
		mirrorImage = mirrorImage * 10 + clone % 10;
		clone /= 10;
	}

	bool out = false;

	if (mirrorImage == number)
	{
		out = true;
	}

	return out;
}



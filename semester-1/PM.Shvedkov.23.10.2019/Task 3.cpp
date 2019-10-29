int hexadecimalCharacter(int decimalNumber, char symbol)
{
	short digit = 0;

	short counter = 0;

	switch (symbol)
	{
	case '1':
		digit = 1;
		break;
	case '2':
		digit = 2;
		break;
	case '3':
		digit = 3;
		break;
	case '4':
		digit = 4;
		break;
	case '5':
		digit = 5;
		break;
	case '6':
		digit = 6;
		break;
	case '7':
		digit = 7;
		break;
	case '8':
		digit = 8;
		break;
	case '9':
		digit = 9;
		break;
	case 'A':
		digit = 10;
		break;
	case 'B':
		digit = 11;
		break;
	case 'C':
		digit = 12;
		break;
	case 'D':
		digit = 13;
		break;
	case 'E':
		digit = 14;
		break;
	case 'F':
		digit = 15;
		break;
	case '0':
		digit = 0;
		break;
	default:
		cout << " Unkown charakter! " << endl;
	}

	for (; decimalNumber > 0; decimalNumber /= 16)
	{
		if (decimalNumber % 16 == digit)
		{
			counter++;
		}
	}
	return counter;
}
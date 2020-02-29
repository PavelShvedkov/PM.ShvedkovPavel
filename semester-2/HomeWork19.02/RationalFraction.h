class RationalFraction
{
public:
	RationalFraction();
	RationalFraction(int num, int denom);

	int getNumerator() const;
	int getDenominator() const;

	void enter();
	void display(bool newString = 1);
	RationalFraction reverseFraction();

	bool operator ==(const RationalFraction& rho)const;
	bool operator !=(const RationalFraction& rho)const;
	bool operator >(const RationalFraction& rho)const;
	bool operator >=(const RationalFraction& rho)const;
	bool operator <(const RationalFraction& rho)const;
	bool operator <=(const RationalFraction& rho)const;
	RationalFraction operator + (const RationalFraction& rho)const;
	RationalFraction& operator +=( const RationalFraction& rho);
	RationalFraction operator -(const RationalFraction& rho)const;
	RationalFraction& operator -=(const RationalFraction& rho);
	RationalFraction operator *(const RationalFraction& rho)const;
	RationalFraction& operator *=(const RationalFraction& rho);
	RationalFraction operator /(const RationalFraction& rho)const;
	RationalFraction& operator /=(const RationalFraction& rho);

private:
	int numerator;
	int denominator;
	int GCF(int, int);
};

RationalFraction addition(RationalFraction, int);
RationalFraction subtraction(RationalFraction, int);
RationalFraction multiplication(RationalFraction, int);
RationalFraction division(RationalFraction, int);
RationalFraction power(RationalFraction, int);
RationalFraction squareRoot(RationalFraction);
RationalFraction greatestCommonFactor(RationalFraction, RationalFraction);
RationalFraction greatestCommonFactor(RationalFraction, int);
RationalFraction leastCommonMultiple(RationalFraction, RationalFraction);
RationalFraction leastCommonMultiple(RationalFraction, int);
RationalFraction toRationalFraction(int);
RationalFraction abs(const RationalFraction&);


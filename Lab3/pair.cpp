#include "pair.h"

Pair::Pair(const int a, const int b)
{
	setA(a);
	setB(b);
}

int Pair::getA() const
{
	return this->a;
}

int Pair::getB() const
{
	return this->b;
}

void Pair::setA(const int a)
{
	this->a = a;
}

void Pair::setB(const int b)
{
	this->b = b;
}

Pair& Pair::mul(const int n)
{
	setA(getA() * n);
	setB(getB() * n);
	return *this;
}

Pair operator+(const Pair& fst, const Pair& scnd)
{
	return Pair(fst.getA() + scnd.getA(), fst.getB() + scnd.getB());;
}

std::istream& operator>>(std::istream& in, Pair& p)
{
	int a, b;
	in >> a >> b;
	p = Pair(a, b);
	return in;
}

std::ostream& operator<<(std::ostream& out, const Pair& p)
{
	out << p.getA() << ", " << p.getB();
	return out;
}

Money operator+(const Money& m1, const Money& m2)
{	
	return (m1.toCoins() + m2.toCoins());
}

std::istream& operator>>(std::istream& in, Money& m)
{
	int rub;
	unsigned int cent;
	in >> rub >> cent;
	m = Money(rub, cent);
	return in;
}

std::ostream& operator<<(std::ostream& out, const Money& m)
{
	out << m.getRubles() << "RUB " << m.getCents() << " cents";
	return out;
}

int Money::valueToCoins(const int rub, const unsigned int cent) const
{
	if (rub >= 0)
		return rub * CENTS_IN_RUB + cent;
	else
		return -1*(abs(rub) * CENTS_IN_RUB + cent);
}

int Money::toCoins() const
{
	if (getRubles() >= 0)
		return getRubles() * CENTS_IN_RUB + getCents();
	else
		return -1 * (abs(getRubles()) * CENTS_IN_RUB + getCents());
}

Money::Money(const int rub, const unsigned int cent)
{
	setRubles(valueToCoins(rub, cent) / CENTS_IN_RUB);	
	setCents(abs(valueToCoins(rub, cent)) % CENTS_IN_RUB);
}

Money::Money(const int coins)
{
	setRubles(coins / CENTS_IN_RUB);
	setCents(abs(coins) % CENTS_IN_RUB);
}

int Money::getCents() const
{
	return this->b;
}

int Money::getRubles() const
{
	return this->a;
}

void Money::setRubles(const int rub)
{
	this->a = rub;
}

void Money::setCents(const int cent)
{
	this->b = cent;
}

Money Money::sub(const Money& other)
{
	return Money(this->toCoins() - other.toCoins());
}

double Money::div(const Money& other)
{
	return double(this->toCoins()) / double(other.toCoins());
}

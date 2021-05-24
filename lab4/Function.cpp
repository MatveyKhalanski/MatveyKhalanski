#include "Function.h"
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

Func::Func(const double a):a(a){}

double Func::getA() const
{
	return this->a;
}

void Func::setA(double a)
{
	this->a = a;
}

std::istream& operator>>(std::istream& in, Func& f)
{
	double a;
	in >> a;
	f = Func(a);
	return in;
}

std::ostream& operator<<(std::ostream& out, const Func& f)
{
	out << "Value:  " << f.getA() << std::endl;
	return out;
}

double Function::getFunc(const double a) const
{
	return getA();
}

Function::Function(const double a)
{
	if (a > 1 | a < 0) throw "invalid_argument";
	setA(a);
	SetArcsin();
	SetArccos();
	SetDerArcsin();
	SetDerArccos();
}

double Function::getA() const
{
	return this->a;
}

void Function::setA(const double a)
{
	this->a = a;
}

void Function::SetArcsin()
{
	this->Arcsin = asin(getA());
}

void Function::SetArccos()
{
	this->Arccos = acos(getA());
}

void Function::SetDerArcsin()
{
	this->DerArcsin = 1 / sqrt(1 - pow(getA(), 2));
}

void Function::SetDerArccos()
{
	this->DerArccos = -getDerArcsin();
}

double Function::getArcsin() const
{
	return this->Arcsin;
}

double Function::getArccos() const
{
	return this->Arccos;
}

double Function::getDerArcsin() const
{
	return this->DerArcsin;
}

double Function::getDerArccos() const
{
	return this->Arccos;
}

std::istream& operator>>(std::istream& in, Function& f)
{
	double a;
	in >> a;
	f = Function(a);
	return in;
}

std::ostream& operator<<(std::ostream& out, const Function& funct)
{
	out << "arcsin(x)= " << funct.getArcsin() << std::endl 		
		<< "arcsin(x)'= " << funct.getDerArcsin() << std::endl
		<< "arccos(x)= " << funct.getArccos() << std::endl
		<< "arccos(x)'= " << funct.getDerArccos() << std::endl;
	return out;
}
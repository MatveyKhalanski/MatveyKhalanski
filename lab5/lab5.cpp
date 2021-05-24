//18. Функция вычисляет расстояние между двумя точками P1(x1,y1) и P2(x2,y2) по формуле D = ((x1 - x2)2 + (y1 - y2)2)1 / 2
#include <iostream>
#include<cmath>
using namespace std;

struct point {
	double x;
	double y;	
};

//без спецификации исключений
double length1(const point& p1, const point& p2) {
	if (p1.x == p2.x & p1.y == p2.y) throw 'e';	
	return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y),2));
};

//со спецификацией throw();
double length2(const point& p1, const point& p2) throw() {
	if (p1.x == p2.x & p1.y == p2.y) throw 'e';
	return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
};

//с конкретной спецификацией с подходящим стандартным исключением;
double length3(const point& p1, const point& p2) throw(invalid_argument) {
	if (p1.x == p2.x & p1.y == p2.y) throw invalid_argument("Error, points are the same\n");
	return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
}

//Спецификация с собственным реализованным исключением (независимый класс с полями-параметрами функции)
class myException
{
public:
	string e;
	myException(string str)
	{
		e = str;
	}
	string what()
	{
		return e;
	}
};
double length4_1(const point& p1, const point& p2) throw(myException) {
	if (p1.x == p2.x & p1.y == p2.y) throw myException("Error, points are the same\n");
	return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
}
//Спецификация с собственным реализованным исключением (пустой класс)
class nullException {};
double length4_2(const point& p1, const point& p2) throw(nullException) {
	if (p1.x == p2.x & p1.y == p2.y) throw nullException();
	return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
}

//Спецификация с собственным реализованным исключением (наследник от стандартного исключения с полями)
class InvalidValue : public exception
{
public:
	const char* what() const throw() {
		return "Error, points are the same\n";
	}
};
double length4_3(const point& p1, const point& p2) {
	if (p1.x == p2.x & p1.y == p2.y) throw InvalidValue();
	return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
}

int main()
{
	point p1, p2;
	cout << "Enter coord of point 1\nx, y: ";
	cin >> p1.x>>p1.y;
	cout << "Enter coord of point 2\nx, y: ";
	cin >> p2.x >> p2.y;


	cout << "Test error 1: ";
	try {
		double length;
		length= length1(p1, p2);
		cout << "length:  " << length << endl;
	}
	catch (char) {
		cout << "Error 1\n";
	}


	cout << "Test error 2: ";
	try {
		double length;
		length = length2(p1, p2);
		cout << "length:  " << length << endl;
	}
	catch (char) {
		cout << "Error 2\n";
	}


	cout << "Test error 3: ";
	try {
		double length;
		length = length3(p1, p2);
		cout << "length:  " << length << endl;
	}
	catch (invalid_argument& e) {
		cout << e.what();
	}


	cout << "Test error 4_1: ";
	try {
		double length;
		length = length4_1(p1, p2);
		cout << "length:  " << length << endl;
	}
	catch (myException& e) {
		cout << e.what();
	}


	cout << "Test error 4_2: ";
	try {
		double length;
		length = length4_2(p1, p2);
		cout << "length:  " << length << endl;
	}
	catch (nullException& e) {
		cout << "Error 4_2\n";
	}


	cout << "Test error 4_3: ";
	try {
		double length;
		length = length4_3(p1, p2);
		cout << "length:  " << length << endl;
	}
	catch (InvalidValue e) {
		cout << e.what();
	}
}
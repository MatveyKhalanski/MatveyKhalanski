#pragma once
#include <iostream>

/**
* \brief Класс Func для работы с переменной, передаваемой функции
*/
class Func
{	
protected:
	double a;
public:

	/**
	 * \brief Конструктор по умолчанию
	 */
	Func() = default;

	/**
	 * \brief Параметризованный конструктор
	 */
	Func(const double a);

	/**
	 * \brief Деструктор
	 */
	virtual ~Func() = default;

	/**
	 * \brief Получение значения переменной
	 */
	double getA() const;

	/**
	 * \brief сеттер значения переменной
	 */
	void setA(const double a);

	/**
	 * \brief Перегруженный оператор ввода
	 */
	friend std::istream& operator>> (std::istream& in, Func& f);

	/**
	 * \brief Перегруженный оператор вывода
	 */
	friend std::ostream& operator<< (std::ostream& out, const Func& f);
};

/**
* \brief Класс Function для вычисления asin ; acos ; acos' ; asin'
*/
class Function :public Func
{	
protected:

	/**
	* \brief Получение значения переменной
	*/
	double getFunc(const double a) const;

public:

	/**
	* \brief конструктор по умолчанию
	*/
	Function() = default;

	/**
	* \brief параметризованный конструктор
	*/
	Function(const double a);

	/**
	* \brief Деструктор
	*/
	~Function() = default;

	/**
	* \brief Получение значения переменной
	*/
	double getA() const;

	/**
	 * \brief Задаем значение переменной
	 */
	void setA(const double a);

	/**
	* \brief Получение значения asin
	*/
	double getArcsin() const;

	/**
	* \brief Получение значения acos
	*/
	double getArccos() const;

	/**
	* \brief Получение значения asin'
	*/
	double getDerArcsin() const;

	/**
	* \brief Получение значения acos'
	*/
	double getDerArccos() const;

	/**
	 * \brief Перегруженный оператор ввода
	 */
	friend std::istream& operator>> (std::istream& in, Function& f);

	/**
	* \brief Перегруженный оператор вывода
	*/
	friend std::ostream& operator<< (std::ostream& out, const Function& f);

private:
	void SetArcsin();
	void SetArccos();
	void SetDerArcsin();
	void SetDerArccos();
	double Arcsin;
	double Arccos;
	double DerArcsin;
	double DerArccos;
};
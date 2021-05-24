#pragma once
#include <sstream>
/**
* 18. Создать класс Pair (пара целых чисел); 
определить метод умножения на число и операцию сложения пар (а, b) + (с, d) = (а + b, с + d).
Определить класс-наследник Money с полями: рубли и копейки. 
Переопределить операцию сложения и определить методы вычитания и деления денежных сумм.
*/
/**
* \brief Класс Pair (пара целых чисел)
*/
class Pair
{
protected:
	int a, b;

public:

	/**
	 * \brief Конструктор по умолчанию
	 */
	Pair() = default;

	/**
	 * \brief Параметризованный конструктор
	 */
	Pair(const int a, const int b);

	/**
	 * \brief Деструктор
	 */
	~Pair() = default;

	/**
	 * \brief геттер значения поля А
	 */
	int getA() const;
	/**
	 * \brief геттер значения поля В
	 */
	int getB() const;	

	/**
	 * \brief Сеттер поля А
	 */
	void setA(const int a);
	/**
	 * \brief Сеттер поля в
	 */
	void setB(const int b);	
	
	/**
	 * \brief метод умножения на число
	 */
	Pair mul(const int n=1);

	/**
	 * \brief Перегруженный оператор суммы 2 пар полей
	 */
	friend Pair operator+ (const Pair& fst, const Pair& scnd);
	
	/**
	 * \brief Перегруженный оператор ввода
	 */
	friend std::istream& operator>> (std::istream& in, Pair& p);

	/**
	 * \brief Перегруженный оператор вывода
	 */
	friend std::ostream& operator<< (std::ostream& out, const Pair& p);
};

/**
* \brief Класс Money с полями: рубли(a) и копейки(b)
*/
class Money :public Pair {
protected:	
	static constexpr int CENTS_IN_RUB = 100;
	/**
	* \brief Метод перевода денежной суммы в копейки
	*/
	int valueToCoins(const int rub, const unsigned int cent = 0) const;
	/**
	* \brief Метод перевода значения объекта в копейки
	*/
	int toCoins() const;
public:

	/**
	* \brief Параметризованный конструктор для рублей и копеек
	*/
	Money(const int rub, const unsigned int cent);	

	/**
	* \brief Параметризованный конструктор для монет
	*/
	Money(const int coins = 0);

	/**
	* \brief геттер значения поля Rubles
	*/
	int getRubles() const;
	/**
	* \brief геттер значения поля Cents
	*/
	int getCents() const;
	

	/**
	* \brief Сеттер поля Rubles
	*/
	void setRubles(const int rub);
	/**
	 * \brief Сеттер поля Cents
	 */
	void setCents(const int cent);
	
	/**
	 * \brief метод вычитания денежных сумм
	 */
	Money sub(const Money& other);
	/**
	 * \brief метод деления денежных сумм
	 */
	double div(const Money& other);

	/**
	 * \brief Перегруженный оператор сложения 2 денежных сумм
	 */
	friend Money operator+ (const Money & m1, const Money & m2);

	/**
	 * \brief Перегруженный оператор ввода
	 */
	friend std::istream& operator>> (std::istream & in, Money& m);

	/**
	 * \brief Перегруженный оператор вывода
	 */
	friend std::ostream& operator<< (std::ostream & out, const Money& m);
};


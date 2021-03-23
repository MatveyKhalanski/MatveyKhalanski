#pragma once
/**
* Класс Cursor
*/
class Cursor
{
public:
	Cursor();
	Cursor(const unsigned int Point.x, const unsigned int Point.y, const bool CursorView, const int CursorSize);
	Cursor(const Cursor& other);
	~Cursor();

	/**
	 * \brief Метод, возвращающий координату по X
	 * \return координата по X
	 */
	unsigned int GetCoordX() const;
	/**
	 * \brief Метод, возвращающий координату по Y
	 * \return координата по Y
	 */
	unsigned int GetCoordY() const;
	/**
	 * \brief Метод, возвращающий вид курсора
	 * \return горизонтальный или вертикальный
	 */
	bool GetCursorView() const;
	/**
	 * \brief Метод, возвращающий размер курсора от 1 до 15
	 * \return размер курсора
	 */
	unsigned char GetCursorSize() const;
	/**
	 * \brief Метод, изменяющий координаты 
	 */
	void ChangeCoord(const Point& NewCoord);
	/**
	 * \brief Метод, изменяющий вид курсора
	 */
	void ChangeCursorView(const CursorView& other);
	/**
	 * \brief Метод, изменяющий размер курсора 
	 */
	void ChangeCursorSize(const CursorSize& other);
	/**
	 * \brief Метод гашения и востановления 
	 */
	bool IsVisible(const Visible& other);


private:
	struct Point {
		unsigned int x;
		unsigned int y;
	};
	bool CursorView;
	unsigned char CursorSize;
	bool Visible;
};


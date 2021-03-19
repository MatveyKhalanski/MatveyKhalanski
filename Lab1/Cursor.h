#pragma once
/**
* Класс Cursor
*/
class Cursor
{
public:
	Cursor() {};
	Cursor(const int CoordX, const int CoordY, const bool CursorView, const int CursorSize) {};
	Cursor(const Cursor& other) {};
	~Cursor();

	/**
	 * \brief Метод, возвращающий координату по X
	 * \return координата по X
	 */
	int GetCoordX() const {};
	/**
	 * \brief Метод, возвращающий координату по Y
	 * \return координата по Y
	 */
	int GetCoordY() const {};
	/**
	 * \brief Метод, возвращающий вид курсора
	 * \return горизонтальный или вертикальный
	 */
	bool GetCursorView() const {};
	/**
	 * \brief Метод, возвращающий размер курсора от 1 до 15
	 * \return размер курсора
	 */
	int GetCursorSize() const {};
	/**
	 * \brief Метод, изменяющий координаты 
	 */
	Cursor& ChangeCoord(const Cursor& other) const {};
	/**
	 * \brief Метод, изменяющий вид курсора
	 */
	Cursor& ChangeCursorView(const Cursor& other) const {};
	/**
	 * \brief Метод, изменяющий размер курсора 
	 */
	Cursor& ChangeCursorSize(const Cursor& other) const {};
	/**
	 * \brief Метод гашения и востановлени¤ 
	 */
	Cursor& IsVisible(const Cursor& other) const {};


private:
	int CoordX;
	int CoordY;
	bool CursorView;
	int CursorSize;
	bool Visible;
};


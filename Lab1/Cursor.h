#pragma once
enum class Orientation {
	Horisontal, Vertical
};
/**
*† ласс Cursor
*/
class Cursor
{
public:
	Cursor() = default;
	Cursor(const unsigned int x = 0, const unsigned int y = 0, const unsigned int CursorSize = 1, const bool visibility = true);
	~Cursor() = default;

	/**
	* \brief метод, возвращающий координату по X
	* \return координата по X
	*/
	unsigned int getCoordX() const;

	/**
	* \brief метод, возвращающий координату по Y
	* \return координата по Y
	*/
	unsigned int getCoordY() const;

	/**
	 * \brief метод, возвращающий вид курсора
	 * \return горизонтальный или вертикальный
	 */
	Orientation isCursorView() const;

	/**
		* \brief метод, возвращающий размер курсора от 1 до 15
		* \return размер курсора
	*/
	unsigned int getCursorSize() const;

	/**
	* \brief метод возвращающий статус видимости курсора
	*/
	bool isVisible() const;

	/**
	 * \brief метод, изменяющий координаты
	 */
	void setCoord(unsigned int x, unsigned int y);

	/**
	 * \brief метод, изменяющий координату х
	 */
	void setCoordX(unsigned int x);

	/**
	 * \brief метод, изменяющий координату y
	 */
	void setCoordY(unsigned int y);

	void setVisibility(bool visibility);
	/**
	 * \brief метод, изменяющий вид курсора
	 */
	void changeCursorView();

	/**
	 * \brief метод, изменяющий размер курсора
	 */
	void setCursorSize(unsigned int size);

	/**
	 * \brief метод мерцания курсора
	 */
	void flickering(Cursor& cursor);

private:

	unsigned int x;
	unsigned int y;
	unsigned int CursorSize;
	bool visibility;
	Orientation orientation;
};


#include "Cursor.h"

Cursor::Cursor(const unsigned int x, const unsigned int y, const unsigned int CursorSize, const bool visibility)
{
	this->x = x;
	this->y = y;
	if (CursorSize< MAX_CURSOR_SIZE){
	this->CursorSize = CursorSize;
	}
	else{
		this->CursorSize = MAX_CURSOR_SIZE;
	}
	this->visibility = visibility;
	this->orientation = Orientation::Vertical;
}


unsigned int Cursor::getCoordX() const
{
	return this->x;
}

unsigned int Cursor::getCoordY() const
{
	return this->y;
}

Orientation Cursor::isCursorView() const
{
	return this->orientation;
}

unsigned int Cursor::getCursorSize() const
{
	return this->CursorSize;
}

bool Cursor::isVisible() const
{
	return this->visibility;
}

void Cursor::setCoordX(unsigned int x)
{
	this->x = x;
}

void Cursor::setCoordY(unsigned int y)
{
	this->y = y;
}

void Cursor::setVisibility(bool visibility)
{
	this->visibility = visibility;
}

void Cursor::changeCursorView()
{
	if (isCursorView() == Orientation::Vertical) {
		this->orientation = Orientation::Horisontal;
	}
	else
	{
		this->orientation = Orientation::Vertical;
	}
}

void Cursor::setCursorSize(unsigned int size)
{
	if(size<=15){
		this->CursorSize = size;
	}
	
}

void Cursor::flickering()
{
	if (isVisible()) {
		setVisibility(false);
	}
	else
	{
		setVisibility(true);
	}
}

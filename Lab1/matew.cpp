#include "Cursor.h"
#include <iostream>
using namespace std;

int main() {
	auto cursor = Cursor(120, 3);
	cout << cursor.getCoordX() << endl << cursor.getCursorSize() << endl << cursor.isVisible() << endl;
	cursor.setCoord(17, 56);
	cursor.flickering(cursor);
	cout << cursor.getCoordX() << endl << cursor.getCoordY() << endl << cursor.isVisible();
	return 0;
}
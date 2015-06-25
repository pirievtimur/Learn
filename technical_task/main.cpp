#include "Field.h"

int main()
{
	Field* a = new Field();
	Field* b = new Field(20);
	a->printField();
	cout << endl;
	b->printField();
	cout << endl;
	a = b;
	a->drawLine(4,5,9,7);
	a->printField();
	system("pause");
	return 0;
}
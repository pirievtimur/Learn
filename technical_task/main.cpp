#include "Field.h"

int main()
{
	Field* a = new Field();
	a->drawLine(2,9,5,4);
	a->drawLine(4,9,0,4);
	a->printField();
	system("pause");
	return 0;
}

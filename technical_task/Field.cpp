#include "Field.h"
//#include 

void Field::init(int size)
{
	this->size = size;
	ptr = new int*[size];
	for (int i = 0; i < size; i++)
	{
		ptr[i] = new int[size];
		for (int j = 0; j < size; j++)
		{
			ptr[i][j] = 0;
		}
	}
}

void Field::deinit()
{
	for (int i = 0; i < size; i++)
	{
		delete[] ptr[i];
	}
	delete[] ptr;
}

Field::Field()
{
	init(DEFAULT_ARRAY_SIZE);
}

Field::Field(int size)
{
	init(size);
}

Field::Field(Field &fieldToCopy)
{
	if (this->size != fieldToCopy.size)
	{
		deinit();
		init(fieldToCopy.size);
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			ptr[i][j] = fieldToCopy.ptr[i][j];
		}
	}
}

Field::~Field()
{
	deinit();
}

void Field::printField()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << ptr[i][j] << " ";
		}
		cout << endl;
	}
}

void Field::drawLine(int x1, int y1, int x2, int y2)
{
	if (!((x1 >= 0 && x1 < size) && (y1 >= 0 && y1 < size) && (x2 >= 0 && x2 < size) && (y2 >= 0 && y2 < size)))
	{
		return;
	}
	for(int x = min(x1, x2); x < max(x1,x2); x++)
	{
		double y = ((x - x1)*(y2 - y1))/(x2 - x1) + y1;
		y = (y - (int)y) < 0.5 ? floor(y) : ceil(y);
		ptr[(int)y][x] = 1;
	}

	for(int y = min(y1, y2); y < max(y1,y2); y++)
	{
		double x = ((y - y1)*(x2 - x1))/(y2 - y1) + x1;
		x = (x - (int)x) < 0.5 ? floor(x) : ceil(x);
		ptr[y][(int)x] = 1;
	}

	ptr[y1][x1] = 2;
	ptr[y2][x2] = 2;

}
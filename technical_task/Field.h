#define DEFAULT_ARRAY_SIZE 10
#include <iostream>
using namespace std;

class Field
{
private:
	int size;
	int** ptr;
public:
	Field();
	Field(int size);
	Field(Field &fieldToCopy);
	~Field();

	void deinit();
	void init(int size);
	void printField();
	void clearField();
	void drawLine(int x1, int y1, int x2, int y2);
};



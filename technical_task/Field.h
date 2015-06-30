#define DEFAULT_ARRAY_SIZE 10
#include <iostream>
#include <algorithm>

using namespace std;

class Field
{
private:
	int size; //size of field x and y 
	char** ptr; // pointer to array
public:
	Field(); // default constructor
	Field(int size); // constructor with size parameter
	Field(Field &fieldToCopy); // copying constructor
	~Field(); // destructor

	void init(int size); // additional func fo constructor
	void deinit(); // additional func for destructor
	void printField(); // func for display field
	void clearField(); // applying value 'O' to every point
	void drawLine(int x1, int y1, int x2, int y2); // draw line 
};



#include <iostream>
#include <string>
using namespace std;

class Circle;
Circle& operator ++(Circle& c);			//전위 연산자 (++a) 
Circle operator ++(Circle& c, int r);	//후위 연산자 (a++)

class Circle {
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }
	void show() { cout << "radius = " << radius << " 인 원" << endl; }
	
	friend Circle& operator ++(Circle& c);
	friend Circle operator ++(Circle& c, int r);
};

Circle& operator ++(Circle& c)
{
	c.radius++;
	return c;
}

Circle operator ++(Circle& c, int r)
{
	Circle tmp = c;
	c.radius++;
	return tmp;
}

int main()
{
	Circle a(5), b(4);
	++a;
	b = a++;
	a.show();
	b.show();
}

#include <iostream>
#include <string>
using namespace std;

class Color;
Color operator +(Color a, Color c);
bool operator ==(Color a, Color c);

class Color {
	int red, green, blue;
public:
	Color() { red = green = blue = 0; }
	Color(int r, int g, int b) { red = r; green = g; blue = b; }
	void show() { cout << red << ' ' << green << ' ' << blue << endl; }
	friend Color operator + (Color a, Color c)
	{
		Color tmp;
		tmp.red = a.red + c.red;
		tmp.green = a.green + c.green;
		tmp.blue = a.blue + c.blue;
		return tmp;
	}

	friend bool operator == (Color a, Color c)
	{
		if (a.red == c.red && a.green == c.green && a.blue == c.blue)
			return true;
		else
			return false;
	}
};
int main()
{
	Color red(255, 0, 0), blue(0, 0, 255), c;
	c = red + blue;
	c.show();

	Color fuchsia(255, 0, 255);
	if (c == fuchsia)
		cout << "보라색 맞음";
	else
		cout << "보라색 아님";
}

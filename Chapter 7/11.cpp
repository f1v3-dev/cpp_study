#include <iostream>
using namespace std;

class Stack {
	int top;
	int s[10];
public:
	Stack() { top = -1; }
	friend bool operator!(Stack& s);
	friend Stack& operator<<(Stack& s, int num);
	friend Stack& operator>>(Stack& s, int& num);
};

bool operator!(Stack& stc)
{
	if (stc.top == -1) return true;
	else return false;
}

Stack& operator<<(Stack& stc, int num)
{
	stc.s[++stc.top] = num;
	return stc;
}

Stack& operator>>(Stack& stc, int& num)
{
	num = stc.s[stc.top--];
	return stc;
}

int main()
{
	Stack stack;
	stack << 3 << 5 << 10;
	while (true) {
		if (!stack) break;
		int x;
		stack >> x;
		cout << x << ' ';
	}
	cout << endl;

	return 0;
}

#include <iostream>
using namespace std;

class Statistics;
bool operator!(Statistics& s);
void operator>>(Statistics& s, int& x);
Statistics& operator<<(Statistics& s, int x);
void operator~(Statistics& s);

class Statistics {
	int* s;
	int size = 0;
public:
	Statistics() { this->size = 0; this->s = new int[size]; }
	friend bool operator!(Statistics& s);
	friend void operator>>(Statistics& s, int& avg);
	friend Statistics& operator<<(Statistics& s, int x);
	friend void operator~(Statistics& s);
};

bool operator!(Statistics& stat)
{
	if (stat.size == 0) return true;
	else return false;
}

void operator>>(Statistics& stat, int& avg)
{
	int sum = 0;
	for (int i = 0; i < stat.size; i++)
	{
		sum += stat.s[i];
	}
	avg = sum / stat.size;
}

Statistics& operator<<(Statistics& stat, int x)
{
	stat.s[stat.size++] = x;
	return stat;
}

void operator~(Statistics& stat)
{
	for (int i = 0; i < stat.size; i++)
		cout << stat.s[i] << ' ';
	cout << endl;
}

int main()
{
	Statistics stat;
	if (!stat) cout << "현재 통계 데이타가 없습니다." << endl;

	int x[5];
	cout << "5 개의 정수를 입력하라>>";
	for (int i = 0; i < 5; i++)cin >> x[i];

	for (int i = 0; i < 5; i++)stat << x[i];
	stat << 100 << 200;
	~stat;

	int avg;
	stat >> avg;
	cout << "avg=" << avg << endl;
}

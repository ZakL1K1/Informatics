#include <iostream>
#include <cmath>
#include <Windows.h>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	float x, y;
	cout << "Введите значение x и y:";
	cin >> x >> y;
	double PI = 3.1415926;

	float r = ((cos(PI * x)) / (sin(PI * x))) - (1 / cos(y));
	float s = tan(x) - log(abs(pow(x, 3) + pow(y, 3)));
	cout << r << " " << s << "\n";

	float c = max(r, s);
	cout << c << "\n";

	cout << "Введите Enter чтоб закончить программу...\n";
	cin.get();
}

#include <iostream>
#include <random>
#include <iomanip>

using namespace std;

bool isInside(double x, double y) {
    return (y >= 2) && (y <= x) && (y <= -x + 6);
}

double calculateMonteCarlo(int N) {
    double x_min = 2.0, x_max = 4.0;
    double y_min = 2.0, y_max = 3.0;
    double rect_area = (x_max - x_min) * (y_max - y_min);

    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> disX(x_min, x_max);
    uniform_real_distribution<> disY(y_min, y_max);

    int countInside = 0;
    for (int i = 0; i < N; ++i) {
        if (isInside(disX(gen), disY(gen))) {
            countInside++;
        }
    }

    return (double)countInside / N * rect_area;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int tests[] = { 100, 1000, 10000, 100000, 1000000 };
    double exactArea = 1.0;

    cout << setw(10) << "N" << setw(20) << "Площадь:" << setw(20) << "Погрешность в процентах:" << endl;

    for (int N : tests) {
        double area = calculateMonteCarlo(N);
        double error = abs(area - exactArea) / exactArea * 100;
        cout << setw(10) << N << setw(20) << fixed << setprecision(6) << area
            << setw(20) << setprecision(4) << error << "%" << endl;
    }

    return 0;
}

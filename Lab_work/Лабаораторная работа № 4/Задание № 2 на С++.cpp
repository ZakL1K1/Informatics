#include <iostream>
#include <set>
#include <iterator>
#include <algorithm>
using namespace std;

int main() {
    setlocale(LC_ALL, "rus");

    set<int> A, B, C;

    cout << "Введите элементы множества A, для окончания введите любую букву:" << endl;
    int element;
    while (cin >> element) {
        A.insert(element);
    }

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Введите элементы множества Bб для окончания введите любую букву:" << endl;
    while (cin >> element) {
        B.insert(element);
    }

    set_intersection(A.begin(), A.end(),B.begin(), B.end(),inserter(C, C.begin()));

    cout << "Элементы, присутствующие в обоих множествах и кратные 3:" << endl;
    bool found = false;
    for (int elem : C) {
        if (elem % 3 == 0) {
            cout << elem << " ";
            found = true;
        }
    }

    if (!found) {
        cout << "Таких элементов нет";
    }
    cout << endl;

    return 0;
}
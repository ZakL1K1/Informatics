#include <iostream>
using namespace std;

void calculateZn(const int* arr, int size, int& product) {
    product = 1;
    for (int i = 0; i < size; i++) {
        product *= arr[i];
    }
}

void findArrayWithMinZN(const int* arrX, int sizeX, const int* arrY, int sizeY) {
    int productA, productB;

    calculateZn(arrX, sizeX, productA);
    calculateZn(arrY, sizeY, productB);

    cout << "Произведение массива A: " << productA << endl;
    cout << "Произведение массива B: " << productB << endl;

    if (productA <= productB) {
        cout << "\nМассив с наименьшим произведением: A" << endl;
        cout << "Элементы массива A: ";
        for (int i = 0; i < sizeX; i++) {
            cout << arrX[i] << " ";
        }
        cout << "\nПроизведение: " << productA << endl;
    }
    else {
        cout << "\nМассив с наименьшим произведением: B" << endl;
        cout << "Элементы массива B: ";
        for (int i = 0; i < sizeY; i++) {
            cout << arrY[i] << " ";
        }
        cout << "\nПроизведение: " << productB << endl;
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    int* A = new int[5];
    int* B = new int[4];

    cout << "Введите " << 5 << " элементов для массива А:" << endl;
    for (int i = 0; i < 5; i++) {
        cin >> A[i];
    }

    cout << "Введите " << 4 << " элементов для массива B:" << endl;
    for (int i = 0; i < 4; i++) {
        cin >> B[i];
    }

    findArrayWithMinZN(A, 5, B, 4);

    delete[] A;
    delete[] B;

    return 0;
}
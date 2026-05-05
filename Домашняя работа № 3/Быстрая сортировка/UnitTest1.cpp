#include "pch.h"
#include "CppUnitTest.h"
#include <vector>
#include <algorithm>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

namespace SortingTests
{
    TEST_CLASS(QuickSortTests)
    {
    public:
        TEST_METHOD(StandardArray)
        {
            vector<int> arr = { 10, 7, 8, 9, 1, 5 };
            vector<int> expected = { 1, 5, 7, 8, 9, 10 };

            quickSort(arr, 0, (int)arr.size() - 1);

            for (size_t i = 0; i < arr.size(); i++) {
                Assert::AreEqual(expected[i], arr[i]);
            }
        }
        TEST_METHOD(WithDuplicates)
        {
            vector<int> arr = { 3, 1, 3, 2, 2 };
            vector<int> expected = { 1, 2, 2, 3, 3 };

            quickSort(arr, 0, (int)arr.size() - 1);

            for (size_t i = 0; i < arr.size(); i++) {
                Assert::AreEqual(expected[i], arr[i]);
            }
        }
        TEST_METHOD(NegativeNumbers)
        {
            vector<int> arr = { -1, -5, 0, 5, 2 };
            vector<int> expected = { -5, -1, 0, 2, 5 };

            quickSort(arr, 0, (int)arr.size() - 1);

            for (size_t i = 0; i < arr.size(); i++) {
                Assert::AreEqual(expected[i], arr[i]);
            }
        }
        TEST_METHOD(SingleElement)
        {
            vector<int> arr = { 42 };
            quickSort(arr, 0, 0);
            Assert::AreEqual(42, arr[0]);
        }
        TEST_METHOD(EmptyArray)
        {
            vector<int> arr = {};
            quickSort(arr, 0, -1);
            Assert::IsTrue(arr.empty());
        }
    };
}

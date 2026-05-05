#include "pch.h"
#include "CppUnitTest.h"
#include <vector>
#include <algorithm>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
}

namespace SortingTests
{
    TEST_CLASS(BubbleSortTests)
    {
    public:
        TEST_METHOD(StandardArray)
        {
            vector<int> arr = { 64, 34, 25, 12 };
            vector<int> expected = { 12, 25, 34, 64 };

            bubbleSort(arr);

            for (size_t i = 0; i < arr.size(); i++) {
                Assert::AreEqual(expected[i], arr[i]);
            }
        }

        TEST_METHOD(Duplicates)
        {
            vector<int> arr = { 3, 1, 2, 3, 1 };
            vector<int> expected = { 1, 1, 2, 3, 3 };

            bubbleSort(arr);

            for (size_t i = 0; i < arr.size(); i++) {
                Assert::AreEqual(expected[i], arr[i]);
            }
        }

        TEST_METHOD(EmptyArray)
        {
            vector<int> arr = {};
            bubbleSort(arr);
            Assert::IsTrue(arr.empty());
        }
    };
}

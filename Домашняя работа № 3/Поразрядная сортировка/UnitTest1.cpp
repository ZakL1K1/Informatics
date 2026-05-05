#include "pch.h"
#include "CppUnitTest.h"
#include <vector>
#include <algorithm>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

vector<int> combineBuckets(const vector<vector<int>>& buckets) {
    vector<int> combined;
    for (const auto& bucket : buckets) {
        for (int x : bucket) {
            combined.push_back(x);
        }
    }
    return combined;
}


void sortByDigit(vector<int>& arr, int exp) {
    vector<vector<int>> buckets(10);
    for (int num : arr) {
        int bucketIndex = (num / exp) % 10;
        buckets[bucketIndex].push_back(num);
    }
    arr = combineBuckets(buckets);
}

void radixSort(vector<int>& arr) {
    if (arr.empty()) return;
    int maxVal = *max_element(arr.begin(), arr.end());
    int exp = 1;
    while (maxVal / exp > 0) {
        sortByDigit(arr, exp);
        exp *= 10;
    }
}


namespace SortingTests
{
    TEST_CLASS(RadixSortTests)
    {
    public:
        TEST_METHOD(DifferentDigits)
        {
            vector<int> arr = { 170, 45, 75, 90, 802, 24, 2, 66 };
            vector<int> expected = { 2, 24, 45, 66, 75, 90, 170, 802 };

            radixSort(arr);

            for (size_t i = 0; i < arr.size(); i++) {
                Assert::AreEqual(expected[i], arr[i]);
            }
        }
        TEST_METHOD(WithZeros)
        {
            vector<int> arr = { 10, 0, 5, 100, 0 };
            vector<int> expected = { 0, 0, 5, 10, 100 };

            radixSort(arr);

            for (size_t i = 0; i < arr.size(); i++) {
                Assert::AreEqual(expected[i], arr[i]);
            }
        }
        TEST_METHOD(IdenticalElements)
        {
            vector<int> arr = { 42, 42, 42 };
            vector<int> expected = { 42, 42, 42 };

            radixSort(arr);

            for (size_t i = 0; i < arr.size(); i++) {
                Assert::AreEqual(expected[i], arr[i]);
            }
        }
        TEST_METHOD(EmptyArray)
        {
            vector<int> arr = {};
            radixSort(arr);
            Assert::IsTrue(arr.empty());
        }
        TEST_METHOD(SortedArray)
        {
            vector<int> arr = { 1, 11, 111, 1111 };
            vector<int> expected = { 1, 11, 111, 1111 };

            radixSort(arr);

            for (size_t i = 0; i < arr.size(); i++) {
                Assert::AreEqual(expected[i], arr[i]);
            }
        }
    };
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <iomanip>
#include <random>

using namespace std;

void sortByDigit(vector<int>& arr, int exp) {
    vector<vector<int>> buckets(10);
    for (int num : arr) {
        buckets[(num / exp) % 10].push_back(num);
    }
    arr.clear();
    for (auto& bucket : buckets) {
        for (int x : bucket) arr.push_back(x);
    }
}

void radixSort(vector<int>& arr) {
    if (arr.empty()) return;
    int maxVal = *max_element(arr.begin(), arr.end());
    for (int exp = 1; maxVal / exp > 0; exp *= 10) sortByDigit(arr, exp);
}


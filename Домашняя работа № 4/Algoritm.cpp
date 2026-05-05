#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
#include <mutex>

template <typename Func, typename... Args>
auto measure_execution_time(Func&& func, Args&&... args) {
    auto start_time = std::chrono::high_resolution_clock::now();
    func(std::forward<Args>(args)...); // Выполняем переданную функцию
    auto end_time = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    return duration.count();
}

using namespace std;

int Slicer(std::vector<int>& vec, int down, int high)
{
    int main = vec[high];
    int i = down - 1;
    for (int j = down; j <= high - 1; j++)
    {
        if (vec[j] <= main)
        {
            i++;
            std::swap(vec[i], vec[j]);
        }
    }
    std::swap(vec[i + 1], vec[high]);
    return i + 1;
}

void QuickSort(std::vector<int>& vec, int down, int high) {
    if (down < high)
    {
        int mainIndex = Slicer(vec, down, high);
        QuickSort(vec, down, mainIndex - 1);
        QuickSort(vec, mainIndex + 1, high);
    }
}

void ParallelQuickSort(std::vector<int>& vec, int down, int high, int num_threads) {
    if (down < high) {
        if (num_threads <= 1 || (high - down) < 10000) {
            QuickSort(vec, down, high);
            return;
        }

        int mainIndex = Slicer(vec, down, high);

        int next_threads = num_threads / 2;

        std::thread left_thread(ParallelQuickSort, std::ref(vec), down, mainIndex - 1, next_threads);
        ParallelQuickSort(vec, mainIndex + 1, high, num_threads - next_threads);

        if (left_thread.joinable()) {
            left_thread.join();
        }
    }
}

std::vector<int> make_vector(int n) {
    std::vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        vec[i] = std::rand() % 1000000;
    }
    return vec;
}

int main() {
    std::srand(std::time(nullptr));

    int sizes[] = { 1000000, 2000000, 3000000, 4000000, 5000000, 6000000, 7000000, 8000000, 9000000, 10000000 };
    int threads_to_test[] = { 1, 2, 4, 8 };

    for (int threads : threads_to_test) {
        std::cout << "Threads: " << threads << std::endl;
        for (int N : sizes) {
            std::vector<int> vec = make_vector(N);
            auto execution_time = measure_execution_time(ParallelQuickSort, std::ref(vec), 0, N - 1, threads);
            std::cout << execution_time << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}

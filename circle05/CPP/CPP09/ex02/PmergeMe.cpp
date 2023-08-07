#include "PmergeMe.hpp"
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <iomanip>

PmergeMe::PmergeMe(int ac, char** av)
{
    // Put everything in vector and deque
    for(int i = 1; i < ac; ++i) {
        int num = atoi(av[i]);
        if (num < 0)
            throw std::runtime_error("Error: Only positive integers are allowed.");
        _intVec.push_back(num);
        _intDeq.push_back(num);
    }

    // Print before sort values
    print(true);

    // VECTOR
    clock_t start = clock();
    mergeInsertionSort(_intVec);
    clock_t end = clock();
    double duration = (double)(end - start) / CLOCKS_PER_SEC * 10000;

    // DEQUE
    start = clock();
    mergeInsertionSort(_intDeq);
    end = clock();

	// Print after sort values
    print(false);
    std::cout << std::fixed << std::setprecision(5) << "Time to process a range of " << _intVec.size() << " elements with std::vector : " << duration << " us\n";
    duration = (double)(end - start) / CLOCKS_PER_SEC * 10000;
    std::cout << std::fixed << std::setprecision(5) << "Time to process a range of " << _intDeq.size() << " elements with std::deque : " << duration << " us\n";
}

PmergeMe::~PmergeMe() { }

template<typename T> void PmergeMe::mergeInsertionSort(T& arr)
{
    int n = arr.size();
    
    if (n <= 1)
        return;
    
    T L(arr.begin(), arr.begin() + n/2);
    T R(arr.begin() + n/2, arr.end());
    
    mergeInsertionSort(L);
    mergeInsertionSort(R);
    
    merge(arr, L, R);
}

template<typename T> void PmergeMe::merge(T& arr, T& L, T& R)
{
    int nL = L.size();
    int nR = R.size();
    
    int i = 0, j = 0, k = 0;
    
    while(j < nL && k < nR) {
        if(L[j] < R[k])
            arr[i++] = L[j++];
        else
            arr[i++] = R[k++];
    }
    
    while(j < nL)
        arr[i++] = L[j++];
    while(k < nR)
        arr[i++] = R[k++];
}

void PmergeMe::print(bool x)
{
    std::cout << (x ? "Before: " : "After: ");
    int i = 0;
    for(std::vector<int>::iterator it = _intVec.begin(); it != _intVec.end() && i < 5; ++it, ++i)
        std::cout << *it << ' ';
    if (_intVec.size() > 5)
        std::cout << "[...]";
    std::cout << '\n';
}
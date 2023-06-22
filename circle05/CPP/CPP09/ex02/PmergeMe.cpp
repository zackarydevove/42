#include "PmergeMe.hpp"
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <iomanip>

PmergeMe::PmergeMe(int argc, char** argv) {
    _after_printed = 0;
    for(int i = 1; i < argc; ++i) {
        int num = atoi(argv[i]);
        _intVec.push_back(num);
        _intList.push_back(num);
    }
}

PmergeMe::~PmergeMe() { }

void PmergeMe::sortWithVector() {
    clock_t start = clock();

    std::sort(_intVec.begin(), _intVec.end());

    clock_t end = clock();
    double duration = (double)(end - start) / CLOCKS_PER_SEC * 10000;
    if (!_after_printed)
    {
        _after_printed = 1;
        printAfter();
    }
    std::cout << std::fixed << std::setprecision(5) << "Time to process a range of " << _intVec.size() << " elements with std::vector : " << duration << " us\n";
}

void PmergeMe::sortWithList() {
    clock_t start = clock();

    _intList.sort();

    clock_t end = clock();
    double duration = (double)(end - start) / CLOCKS_PER_SEC * 10000;
    if (!_after_printed)
    {
        _after_printed = 1;
        printAfter();
    }
    std::cout << std::fixed << std::setprecision(5) << "Time to process a range of " << _intList.size() << " elements with std::list : " << duration << " us\n";
}

void PmergeMe::printBefore() {
    std::cout << "Before: ";
    int i = 0;
    for(std::vector<int>::iterator it = _intVec.begin(); it != _intVec.end() && i < 5; ++it, ++i)
        std::cout << *it << ' ';
    if (_intVec.size() > 5)
        std::cout << "[...]";
    std::cout << '\n';
}

void PmergeMe::printAfter() {
    std::cout << "After: ";
    int i = 0;
    for(std::vector<int>::iterator it = _intVec.begin(); it != _intVec.end() && i < 5; ++it, ++i)
        std::cout << *it << ' ';
    if (_intVec.size() > 5)
        std::cout << "[...]";
    std::cout << '\n';
}
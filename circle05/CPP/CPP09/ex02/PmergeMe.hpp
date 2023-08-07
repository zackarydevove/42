#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>

class PmergeMe {
private:
    std::vector<int> _intVec;
    std::deque<int> _intDeq;

    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);

public:
    PmergeMe(int argc, char** argv);
    ~PmergeMe();

    template<typename T> void mergeInsertionSort(T& arr);
    template<typename T> void merge(T& arr, T& L, T& R);

    void print(bool x);
};

#endif
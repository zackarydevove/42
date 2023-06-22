#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>
#include <iostream>

class PmergeMe {
private:
    std::vector<int> _intVec;
    std::list<int> _intList;
    int _after_printed;

    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);

public:
    PmergeMe(int argc, char** argv);
    ~PmergeMe();

    void sortWithVector();
    void sortWithList();

    void printBefore();
    void printAfter();
};

#endif
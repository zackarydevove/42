#include "easyfind.hpp"
#include <vector>
#include <iostream>

int main() {
    std::vector<int> numbers;
    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);
    numbers.push_back(4);
    numbers.push_back(5);

    easyfind(numbers, 3);
    easyfind(numbers, 6);

    return 0;
}
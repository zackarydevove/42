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


    std::vector<char> characters;
    characters.push_back('x');
    characters.push_back('1');
    characters.push_back('e');
    characters.push_back('d');
    characters.push_back('0');

    easyfind(characters, '0');
    easyfind(characters, 'z');

    // std::vector<char *> strings;
    // strings.push_back("x");
    // strings.push_back("1");
    // strings.push_back("e");
    // strings.push_back("d");
    // strings.push_back("0");

    // easyfind(strings, '0');
    // easyfind(strings, 'z');

    return 0;
}
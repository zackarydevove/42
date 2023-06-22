#include "Array.hpp"
#include <iostream>

int main() {
    try {
        Array<int> arr(10);
        for (unsigned int i = 0; i < arr.size(); ++i) {
            arr[i] = i * 10;
            std::cout << arr[i] << ' ';
        }
        std::cout << '\n';

        Array<int> arr2(arr);
        for (unsigned int i = 0; i < arr2.size(); ++i)
            std::cout << arr2[i] << ' ';
        std::cout << '\n';
        
        // Trigger out of range exception
        std::cout << arr[11] << '\n';
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
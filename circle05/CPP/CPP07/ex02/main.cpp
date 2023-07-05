#include "Array.hpp"
#include <iostream>

int main() {
    try {
        // Try default constructor
        Array<int> null;
        if (null.getArray() == NULL)
            std::cout << "default constructor array_ = NULL" << ' ';
        std::cout << '\n';


        // Try unsigned n constructor
        Array<int> arr(10);
        for (unsigned int i = 0; i < arr.size(); ++i) {
            arr[i] = i;
            std::cout << arr[i] << ' ';
        }
        std::cout << '\n';

        // Try copy constructor
        Array<int> arr2(arr);
        for (unsigned int i = 0; i < arr2.size(); ++i)
            std::cout << arr2[i] << ' ';
        std::cout << '\n';

        // Try = operator
        Array<int> arr3 = arr;
        for (unsigned int i = 0; i < arr3.size(); ++i)
            std::cout << arr3[i] << ' ';
        std::cout << '\n';
        
        // Trigger out of range exception
        std::cout << arr[11] << '\n';
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
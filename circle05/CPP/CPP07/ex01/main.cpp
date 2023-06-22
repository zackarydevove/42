#include "iter.hpp"

template <typename T>
void print(const T &x) {
    std::cout << x << std::endl;
}

int main() {
    int arrInt[] = {1, 2, 3, 4, 5};
    ::iter(arrInt, sizeof(arrInt)/sizeof(arrInt[0]), print);

    std::string arrStr[] = {"Hello", "World", "Test", "Array"};
    ::iter(arrStr, sizeof(arrStr)/sizeof(arrStr[0]), print);

    return 0;
}
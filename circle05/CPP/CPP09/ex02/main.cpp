
#include "PmergeMe.hpp"

int main(int ac, char** av) {

    if (ac < 4)
    {
        std::cerr << "Error "  << std::endl;
        return (0);
    }

    try {
        PmergeMe sorter(ac, av);
        sorter.printBefore();
        sorter.sortWithVector();
        sorter.sortWithList();
    }
    catch(const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
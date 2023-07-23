#include "PmergeMe.hpp"

int main(int ac, char** av) {

    if (ac >= 4)
    {
        try { PmergeMe sorter(ac, av); }
        catch(const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
    else
        std::cerr << "Error "  << std::endl;
    return 0;
}
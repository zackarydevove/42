#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>

template <typename T>
void easyfind(T &container, int toFind) {
    try 
    {
        typename T::iterator it = std::find(container.begin(), container.end(), toFind);
    
        if (it == container.end())
			throw std::exception();
        else
            std::cout << "Value " << toFind << " found" << std::endl;
    }
    catch(std::exception &e)
	{
			std::cerr << "Value " << toFind << " not found" << std::endl;
	}
}

#endif
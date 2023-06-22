#include "Span.hpp"
#include <iostream>
#include <vector>


int main()
{
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    Span sp2 = Span(11111);
    std::vector<int> tab(11111);
    for (int i = 0; i < 10000; ++i)
            tab[i] = i;
    sp2.addNumber(tab.begin(), tab.end());

    std::cout << sp2.shortestSpan() << std::endl;
    std::cout << sp2.longestSpan() << std::endl;

    Span sp3 = Span(10000);
    std::vector<int> tab2(10000, 1);
    tab2[5000] = 5000;

    sp3.addNumber(tab2.begin(), tab2.end());

    std::cout << sp3.shortestSpan() << std::endl;
    std::cout << sp3.longestSpan() << std::endl;

    return 0;
}
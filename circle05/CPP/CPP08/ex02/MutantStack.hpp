#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
public:
    MutantStack() { }
    MutantStack(const MutantStack& other) : std::stack<T>(other) { }
    virtual ~MutantStack() { }
    MutantStack& operator=(const MutantStack& other) {
        std::stack<T>::operator=(other);
        return *this;
    }

    typedef typename std::stack<T>::container_type::iterator iterator;
    iterator begin() { return std::stack<T>::c.begin(); }
    iterator end() { return std::stack<T>::c.end(); }
};

#endif
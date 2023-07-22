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

        typedef typename std::deque<T>::iterator		iterator;
        iterator begin() {return this->c.begin();};
        iterator end() {return this->c.end();};
};

#endif
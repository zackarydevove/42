#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &other) {
    std::cout << "Brain copy constructor called" << std::endl;
    for (int i = 0; i < 100; ++i) {
        ideas[i] = other.ideas[i];
    }
}

Brain::~Brain() {
    std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &other) {
    if (this != &other)
        for (int i = 0; i < 100; ++i)
            ideas[i] = other.ideas[i];
    return *this;
}

std::string Brain::getIdea(int i) const{
	return ideas[i];
}

void Brain::setIdea(int i, std::string str){
	ideas[i] = str;
}
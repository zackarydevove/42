#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>

Base * generate(void)
{
	int i = rand() % 3;
	if (i == 0){
		std::cout << "Create A" << std::endl;	
		return (new A);
	}
	else if (i == 1){
		std::cout << "Create B" << std::endl;	
		return (new B);
	}
	else
	{
		std::cout << "Create C" << std::endl;	
		return (new C);
	}
};

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
    } catch (std::exception &e) { }
    try {
        (void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
    } catch (std::exception &e) { }
    try {
        (void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
    } catch (std::exception &e) { }
}

int main()
{
	srand(time(NULL));

	Base *base = generate();

	identify(base);
	identify(*base);

	delete base;

	Base *base2 = generate();

	identify(base2);
	identify(*base2);

	delete base2;
}
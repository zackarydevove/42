#ifndef DATA_HPP
#define DATA_HPP

#include <string>
#include <stdint.h>

struct Data
{
	std::string name;
	int number;
};

class Serializer
{
	public:
		Serializer();
		Serializer(const Serializer &);
		~Serializer();
		Serializer & operator = (const Serializer &);

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
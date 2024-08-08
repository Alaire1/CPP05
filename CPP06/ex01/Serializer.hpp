#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <string>
#include <iostream>
#include <stdint.h>

struct Data {
	char c;
    int number;
	std::string emoji;
    bool boolean;
    float f;
    std::string str;
    long l;
};

class Serializer
{
    private:
        Serializer();
        Serializer(Serializer const &src);
        Serializer &operator=(Serializer const &src);
        ~Serializer();

    public:
        static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);
};


#endif
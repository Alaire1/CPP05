
#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(Serializer const &src) 
{
	*this = src;
}

Serializer &Serializer::operator=(Serializer const &src) 
{
	(void)src;
	return *this;
}

Serializer::~Serializer() {}

Data *Serializer::deserialize(uintptr_t raw)
{
	if (raw == 0)
		return (NULL);
    return reinterpret_cast<Data*>(raw);
}

uintptr_t Serializer::serialize(Data *ptr)
{
	if (ptr == NULL)
		return (0);
    return reinterpret_cast<uintptr_t>(ptr);
}

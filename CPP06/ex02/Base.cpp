#include "Base.hpp"

Base::~Base() {}

Base *generate(void)
{
    int random = rand() % 3;
    if (random == 0)
        return new A;
    else if (random == 1)
        return new B;
    else
        return new C;
};

void identify(Base *p)
{

};

void identify(Base &p)
{

};

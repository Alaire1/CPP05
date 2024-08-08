#include "Base.hpp"

Base::~Base() {}

Base *generate(void)
{
    int random = rand() % 3;
    if (random == 0)
    {
        A* a = new A;
        std::cout << "Type A generated. Address: " << a << std::endl;
        return a;
    }
    else if (random == 1)
    {
        B* b = new B;
        std::cout << "Type B generated. Address: " << b << std::endl;
        return b;
    }
    else
    {
        C* c = new C;
        std::cout << "Type C generated. Address: " << c << std::endl;
        return c;
    }
}

void identify(Base *p)
{
    if (p == NULL)
    { 
        std::cout << "Type cannot be defined" << std::endl;
        return;
    }
    identify(*p);  
}

void identify(Base &p) {
    try
    {
        A   &Ap = dynamic_cast<A &>(p);
        std::cout << "Type A detected. Address:  " << &Ap << std::endl;
    }
    catch(std::exception &e)
    {
        try
        {
            B   &Bp = dynamic_cast<B &>(p);
            std::cout << "Type B detected. Address: " << &Bp << std::endl;
        }
        catch(std::exception &e)
        {
            try
            {
                C   &Cp = dynamic_cast<C &>(p);
                std::cout << "Type C detected. Address: " << &Cp << std::endl;
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << " Unknown type detected" << std::endl;
            }
        }
    }

}

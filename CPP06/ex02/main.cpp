#include "Base.hpp"

void printPartition() {
    std::cout << "----------------------------------------" << std::endl;
}

int main() {
    srand(static_cast<unsigned int>(time(0))); 
    std::cout << "\033[33mBase :\033[0m" << std::endl;
    Base* base = generate();
    printPartition();
    Base &ref = *base;
    identify(base); 
    identify(ref);
    delete(base);

    std::cout << "\033[33mBase2 :\033[0m" << std::endl;
    Base* base2 = generate();
    printPartition();
    Base &ref2 = *base2;
    identify(base2);
    identify(ref2);
    delete(base2);

    std::cout << "\033[33mBase3 :\033[0m" << std::endl;
    Base* base3 = generate();
    printPartition();
    identify(base3);
    identify(*base3);
    delete(base3);

    std::cout << "\033[33mBase4 :\033[0m" << std::endl;
    Base* base4 = generate();
    printPartition();
    identify(base4);
    identify(*base4);
    delete(base4);

    std::cout << "\033[33mNULL pointer :\033[0m" << std::endl;
    Base* base5 = NULL;
    identify(base5);
    return 0;
}
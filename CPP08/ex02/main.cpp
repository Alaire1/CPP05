#include "MutantStack.hpp"
#include <iostream>
#include <list>

void testMutantStack() {
    std::cout << YELLOW << "MutantStack Test" << RESET << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "top: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "size: " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
}


void testOtherMutantStack() {
    std::cout << YELLOW << "Other MutantStack Test" << RESET << std::endl;
    MutantStack<int> mstack2;
    int n[] = {1, 12, 3, 11, 33};
    for (int i = 0; i < 5; i++)
        mstack2.push(n[i]);
    MutantStack<int>::iterator it2 = mstack2.begin();
    MutantStack<int>::iterator ite2 = mstack2.end();
    while (it2 != ite2) {
        std::cout << *it2 << std::endl;
        ++it2;
    }
    std::cout << "top: " << mstack2.top() << std::endl;
    std::cout << "size: " << mstack2.size() << std::endl;
    std::cout << "pop" << std::endl;
    mstack2.pop();
    std::cout << "top: " << mstack2.top() << std::endl;
    std::cout << "size: " << mstack2.size() << std::endl;
}


int main() {
    testMutantStack();
    testOtherMutantStack();
    return 0;
}
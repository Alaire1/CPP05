#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>
#include "easyfind.hpp"

void testVector() {
    std::cout << YELLOW << "Vector Test\n" << RESET;
    std::vector<int> vec;
    for (int i = 0; i < 98; i++)
        vec.push_back(i);

    try {
        std::vector<int>::iterator it;
        std::cout << "Vector:\n";

        for (it = vec.begin(); it != vec.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;

        std::cout << "easyfind(vec, 5): ";
        std::vector<int>::iterator element = easyfind(vec, 5);
        std::cout << GREEN << "Found " << *element << RESET << std::endl;

        std::cout << "easyfind(vec, 42): ";
        element = easyfind(vec, 42);
        std::cout << GREEN << "Found " << *element << RESET << std::endl;

        std::cout << "easyfind(vec, 98): ";
        element = easyfind(vec, 100);
        std::cout << GREEN << "Found " << *element << RESET << std::endl;

    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

void testList() {
    std::cout << YELLOW << "List Test\n" << RESET;
    std::list<int> lst;
    for (int i = 0; i < 50; i++)
        lst.push_back(i);

    try {
        std::list<int>::iterator it;
        std::cout << "List:\n";

        for (it = lst.begin(); it != lst.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;

        std::cout << "easyfind(lst, 3): ";
        std::list<int>::iterator element = easyfind(lst, 3);
        std::cout << GREEN << "Found " << *element << RESET << std::endl;

        std::cout << "easyfind(lst, 49): ";
        element = easyfind(lst, 49);
        std::cout << GREEN << "Found " << *element << RESET << std::endl;

        std::cout << "easyfind(lst, 50): ";
        element = easyfind(lst, 50);
        std::cout << GREEN << "Found " << *element << RESET << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

void testDeque() {
    std::cout << YELLOW << "Deque Test\n" << RESET;
    std::deque<int> deq;
    for (int i = 0; i < 42; i++)
        deq.push_back(i);

    try {
        std::deque<int>::iterator it;
        std::cout << "Deque:\n";

        for (it = deq.begin(); it != deq.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;

        std::cout << "easyfind(deq, 3): ";
        std::deque<int>::iterator element = easyfind(deq, 3);
        std::cout << GREEN << "Found " << *element << RESET << std::endl;

        std::cout << "easyfind(deq, 60): ";
        element = easyfind(deq, 60);
        std::cout << GREEN << "Found " << *element << RESET << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

void testSet() {
    std::cout << YELLOW << "Set Test\n" << RESET;
    std::set<int> st;
    for (int i = 0; i < 88; i++)
        st.insert(i);

    try {
        std::set<int>::iterator it;
        std::cout << "Set:\n";

        for (it = st.begin(); it != st.end(); it++)
            std::cout << *it << " ";
        std::cout << std::endl;

        std::cout << "easyfind(st, 2): ";
        std::set<int>::iterator element = easyfind(st, 2);
        std::cout << GREEN << "Found " << *element << RESET << std::endl;

        std::cout << "easyfind(st, 87): ";
        element = easyfind(st, 87);
        std::cout << GREEN << "Found " << *element << RESET << std::endl;

        std::cout << "easyfind(st, 88): ";
        element = easyfind(st, 88);
        std::cout << GREEN << "Found " << *element << RESET << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}


int main(void) {
    testVector();
    testList();
    testDeque();
    testSet();
    return 0;
}
#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#define YELLOW "\033[33m"
#define RESET "\033[0m"

#include <stack>
#include <deque>
template <typename T>
class MutantStack: public std::stack<T> {
public:
    MutantStack();
    MutantStack(MutantStack const &src);
    MutantStack &operator=(MutantStack const &src);
    ~MutantStack();

    typedef typename std::stack<T>::container_type::iterator iterator;
    iterator begin();
    iterator end();
};
#include "MutantStack.tpp"

#endif
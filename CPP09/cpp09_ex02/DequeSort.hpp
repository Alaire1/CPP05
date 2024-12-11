#pragma once

#include <vector>
#include <deque>
#include <utility>
#include <iostream>
#include <exception>
#include <climits>
#include <string> 


class DequeSort {
private:
    std::deque<int> deque;
    std::deque<std::pair<int, int> > pairs;
    std::deque<int> insertionOrder;
    std::deque<int> mainChain;
    std::deque<int> pend;
    std::deque<int> jacobsthalSequence;

    void populateDeque(char *argv[]);
    void createPairs();
    void sortPairs();
    void merge(std::deque<std::pair<int, int> > &array, int begin, int mid, int end);
    void mergeSort(std::deque<std::pair<int, int> > &array, int begin, int end);
    void createMainChainAndPend();
    int binarySearch(std::deque<int> array, int target, int begin, int end);
    void generateJacobsthalSequence();
    int jacobsthalNum(int n);
    void generateInsertionOrder();
    void insertToMainChain();
    //test functions
    void printPairs();
    void printArray(std::deque<std::pair<int, int> > &array);
    void printDeque(const std::deque<int> &deque) const;

public:
    DequeSort();
    DequeSort(const DequeSort& other);
    DequeSort& operator=(const DequeSort& other);
    ~DequeSort();

    void mergeInsert(char *argv[]);
    
    public:
    class Exception : public std::exception {
    public:
        Exception(const std::string& message = "DequeSort Error: invalid input");
        virtual ~Exception() throw();
        virtual const char* what() const throw();
    
    private:
        std::string msg;
    };
};

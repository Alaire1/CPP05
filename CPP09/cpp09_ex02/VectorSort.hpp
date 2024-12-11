#pragma once

#include <vector>
#include <utility>
#include <iostream>
#include <exception>
#include <climits>
#include <string>
#include <cstdlib>
#include <algorithm> 


class VectorSort {
private:
    std::vector<int> vec;
    std::vector<int> insertionOrder;
    std::vector<std::pair<int, int> > vecPair;
    std::vector<int> mainChain;
    std::vector<int> pend;
    std::vector<int> jacobSequence;

    void populateVector(char *argv[]);
    void createPairs();
    void sortPairs();
    void merge(std::vector<std::pair<int, int> > &array, int begin, int mid, int end);
    void mergeSort(std::vector<std::pair<int, int> > &array, int begin, int end);
    void createMainChainAndPend();
    int binarySearch(std::vector<int> array, int target, int begin, int end);
    void generateJacobsthalSequence();
    int jacobsthalNum(int n);
    void generateInsertionOrder();
    void insertToMainChain();

public:
    VectorSort();
    VectorSort(const VectorSort& other);
    VectorSort& operator=(const VectorSort& other);
    ~VectorSort();

    void mergeInsert(char *argv[]);
    void printContainer(const std::vector<int>& container) const;
    void printBefore() const;
    void printAfter() const;

    class Exception : public std::exception {
    public:
        Exception(const std::string& message = "VectorSort Error: invalid input");
        virtual ~Exception() throw();
        virtual const char* what() const throw();
    
    private:
        std::string msg;
    };

};
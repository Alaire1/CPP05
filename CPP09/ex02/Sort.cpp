#include "Sort.hpp"
void printBefore(std::vector<int>& container)
{
    std::cout << "Before: ";
    for (std::vector<int>::const_iterator it = container.begin(); it != container.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void printAfter(std::vector<int>& container)
{
    std::cout << "After: ";
    for (std::vector<int>::const_iterator it = container.begin(); it != container.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void recursiveSort(int size, std::vector<int>& minContainer)
{
  if ()
  
}
void grouping(std::vector<int>& container, int size, std::vector<int>& minContainer, std::vector<int>& maxContainer)
{
  for (int i = 0; i < size; i += 2)
  {
    if (container[i] > container[i + 1])
    {
      //std::swap(container[i], container[i + 1]);
        minContainer.push_back(container[i + 1]);
        maxContainer.push_back(container[i]);
    }
    else
    {
        minContainer.push_back(container[i]);
        maxContainer.push_back(container[i + 1]);
    }
    recursiveSort(container, size, minContainer, maxContainer);
  }
  std::cout << "Min: ";
    printAfter(minContainer);
    std::cout << "Max: ";
    printAfter(maxContainer);
    std::cout << std::endl;
}


void sortvect(std::vector<int>& Container, int size){
    printBefore(Container);
    clock_t startTime = clock();
    std::vector<int> minContaienr;
    std::vector<int> maxContainer;
    std::cout << "Time to process a range of " << size << " elements with std::vector: " << GREEN << std::fixed << (clock() - startTime) / (double)CLOCKS_PER_SEC << " us" << RESET << std::endl;
    grouping(Container, size, minContaienr, maxContainer); 
    // printAfter(Container);
    
}
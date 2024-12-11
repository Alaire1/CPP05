#include "DequeSort.hpp"
#include <cstdlib>
#include <utility>
#include <algorithm> 

DequeSort::DequeSort()
{
}

DequeSort::DequeSort(const DequeSort& other)
    : deque(other.deque),
	 pairs(other.pairs),
      insertionOrder(other.insertionOrder),
      mainChain(other.mainChain),
      pend(other.pend),
      jacobsthalSequence(other.jacobsthalSequence) {
}

DequeSort& DequeSort::operator=(const DequeSort& other) {
    if (this != &other) {
        deque = other.deque;
        insertionOrder = other.insertionOrder;
        pairs = other.pairs;
        mainChain = other.mainChain;
        pend = other.pend;
        jacobsthalSequence = other.jacobsthalSequence;
    }
    return *this;
}

DequeSort::~DequeSort()
{
}

DequeSort::Exception::Exception(const std::string& message) : msg(message) {}


DequeSort::Exception::~Exception() throw() {}

const char* DequeSort::Exception::what() const throw() {
    return msg.c_str();
}

int DequeSort::binarySearch(std::deque<int> array, int target, int begin, int end)
{
	int mid = begin + (end - begin) / 2;

	while (begin <= end)
	{
		mid = begin + (end - begin) / 2;
		if (target == array.at(mid))
			return (mid);
		if (target > array.at(mid))
			begin = mid + 1;
		else
			end = mid - 1;
	}
	if (target > array.at(mid))
		return (mid + 1);
	else
		return (mid);
}

int DequeSort::jacobsthalNum(int n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	int jacobsthalNumber = jacobsthalNum(n - 1) + 2 * jacobsthalNum(n - 2);
	return (jacobsthalNumber);
}

void DequeSort::generateJacobsthalSequence()
{
	size_t size = pend.size();
	size_t jacobsthalIndex;
	int index = 3;

	while ((jacobsthalIndex = jacobsthalNum(index)) < size - 1)
	{
		jacobsthalSequence.push_back(jacobsthalIndex);
		index++;
	}
	std::cout << "Jacobsthal sequence" << std::endl;
	std::deque<int>::iterator it;
	for (it = jacobsthalSequence.begin(); it < jacobsthalSequence.end(); it++)
	{
		std::cout << *it << " ";
	}
}

void DequeSort::generateInsertionOrder()
{
	if (pend.empty())
		return;

	size_t val = 1;
	size_t pos;
	size_t lastPos = 1;
	generateJacobsthalSequence();
	while (!jacobsthalSequence.empty())
	{
		val = jacobsthalSequence.front();
		jacobsthalSequence.pop_front();
		insertionOrder.push_back(val);
		pos = val - 1;
		while (pos > lastPos)
		{
			insertionOrder.push_back(pos);
			pos--;
		}
		lastPos = val;
	}
	while (val++ < pend.size())
		insertionOrder.push_back(val);
}

void DequeSort::insertToMainChain()
{
	int target;
	size_t endPos;
	size_t pos;
	size_t addedCount = 0;
	std::deque<int>::iterator it;

	generateInsertionOrder();
	std::cout << "Insertion Order: " << std::endl;
	printDeque(insertionOrder);
	for (it = insertionOrder.begin(); it < insertionOrder.end(); it++)
	{
		target = pend.at(*it - 1);
		endPos = *it + addedCount;
		pos = binarySearch(mainChain, target, 0, endPos);
		mainChain.insert(mainChain.begin() + pos, target);
		addedCount++;
	}
	if (deque.size() % 2 != 0)
	{
		target = deque.at(deque.size() - 1);
		pos = binarySearch(mainChain, target, 0, mainChain.size() - 1);
		mainChain.insert(mainChain.begin() + pos, target);
	}
}
void DequeSort::printDeque(const std::deque<int> &deque) const
{
    std::cout << "[ ";
    std::deque<int>::const_iterator it;
    for (it = deque.begin(); it != deque.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << "]" << std::endl;
}

void DequeSort::createMainChainAndPend()
{
	size_t i = 0;
	mainChain.push_back(pairs.at(0).second);
	while (i < pairs.size())
	{
		mainChain.push_back(pairs.at(i).first);
		pend.push_back(pairs.at(i).second);
		i++;
	}
	std::cout << "Main chain" << std::endl;
	printDeque(mainChain);
	std::cout << "Pend" << std::endl;
	printDeque(pend);
}


void DequeSort::merge(std::deque<std::pair<int, int> > &array, int begin, int mid, int end)
{
	size_t leftArrayIndex = 0;
	size_t rightArrayIndex = 0;
	size_t mergedArrayIndex = begin;

	std::deque<std::pair<int, int> > leftArray(array.begin() + begin, array.begin() + mid + 1);
	std::deque<std::pair<int, int> > rightArray(array.begin() + mid + 1, array.begin() + end + 1);

	std::cout << "Left array" << std::endl;
	printArray(leftArray);
	std::cout << "Right array" << std::endl;
	printArray(rightArray);

	while (leftArrayIndex < leftArray.size() && rightArrayIndex < rightArray.size())
	{
		if (leftArray[leftArrayIndex].first <= rightArray[rightArrayIndex].first)
		{
			array[mergedArrayIndex] = leftArray[leftArrayIndex];
			leftArrayIndex++;
		}
		else
		{
			array[mergedArrayIndex] = rightArray[rightArrayIndex];
			rightArrayIndex++;
		}
		mergedArrayIndex++;
	}
	while (leftArrayIndex < leftArray.size())
	{
		array[mergedArrayIndex] = leftArray[leftArrayIndex];
		leftArrayIndex++;
		mergedArrayIndex++;
	}
	while (rightArrayIndex < rightArray.size())
	{
		array[mergedArrayIndex] = rightArray[rightArrayIndex];
		rightArrayIndex++;
		mergedArrayIndex++;
	}
	std::cout << "Merged array" << std::endl;
	printArray(array);
}


void DequeSort::printArray(std::deque<std::pair<int, int> > &array)
{
	std::deque<std::pair<int, int> >::iterator it;

	for (it = array.begin(); it < array.end(); it++)
	{
		std::cout << it->first << " " << it->second << std::endl;
	}
}
void DequeSort::mergeSort(std::deque<std::pair<int, int> > &array, int begin, int end)
{
	if (begin >= end)
		return;
	int mid = begin + (end - begin) / 2;
	// std::cout << "Mid: " << mid << std::endl;
	// std::cout << "Begin: " << begin << std::endl;
	// std::cout << "End: " << end << std::endl;
	// printArray(array);
	// std::cout << "The end" << std::endl;	
	mergeSort(array, begin, mid);
	mergeSort(array, mid + 1, end);
	merge(array, begin, mid, end);
	// std::cout << "After merge" << std::endl;
	// printArray(array);
}

void DequeSort::sortPairs()
{
	unsigned int i = 0;
	int tmp;

	while (i < pairs.size())
	{
		if (pairs.at(i).first < pairs.at(i).second)
		{
			tmp = pairs.at(i).first;
			pairs.at(i).first = pairs.at(i).second;
			pairs.at(i).second = tmp;
		}
		i++;
	}
}
void DequeSort::printPairs()
{
    int pairNumber = 1; 
    std::deque<std::pair<int, int> >::iterator it;

    for (it = pairs.begin(); it < pairs.end(); it++)
    {
        std::cout << "Pair " << pairNumber++ << ": " 
                  << it->first << " " << it->second << std::endl;
    }
}

void DequeSort::createPairs()
{
	unsigned int i = 0;
	int size = deque.size() / 2;
	
	while (size != 0)
	{
		pairs.push_back(std::make_pair(deque.at(i), deque.at(i + 1)));
		i += 2;
		size--;
	}
	// printPairs();
}

void DequeSort::populateDeque(char *argv[])
{
	int i = 1;
	char *ptr;
	int val;

	while (argv[i])
	{
		val = strtol(argv[i], &ptr, 10);
		deque.push_back(val);
		i++;
	}
}

void DequeSort::mergeInsert(char *argv[])
{
	populateDeque(argv);
	createPairs();
	sortPairs();
	mergeSort(pairs, 0, pairs.size() - 1);
	createMainChainAndPend();
	insertToMainChain();
}

#include "VectorSort.hpp"

VectorSort::VectorSort() {
}

VectorSort::VectorSort(const VectorSort& other)
    : vec(other.vec),
      insertionOrder(other.insertionOrder),
      vecPair(other.vecPair),
      mainChain(other.mainChain),
      pend(other.pend),
      jacobSequence(other.jacobSequence) {
}

VectorSort& VectorSort::operator=(const VectorSort& other) {
    if (this != &other) {
        vec = other.vec;
        insertionOrder = other.insertionOrder;
        vecPair = other.vecPair;
        mainChain = other.mainChain;
        pend = other.pend;
        jacobSequence = other.jacobSequence;
    }
    return *this;
}
VectorSort::~VectorSort() {
}


VectorSort::Exception::Exception(const std::string& message) : msg(message) {}


VectorSort::Exception::~Exception() throw() {}

const char* VectorSort::Exception::what() const throw() {
    return msg.c_str();
}


void VectorSort::createPairs()
{
	unsigned int i = 0;
	int size = vec.size() / 2;

	while (size != 0)
	{
		vecPair.push_back(std::make_pair(vec.at(i), vec.at(i + 1)));
		i += 2;
		size--;
	}
}

void VectorSort::sortPairs()
{
	unsigned int i = 0;
	int tmp;

	while (i < vecPair.size())
	{
		if (vecPair.at(i).first < vecPair.at(i).second)
		{
			tmp = vecPair.at(i).first;
			vecPair.at(i).first = vecPair.at(i).second;
			vecPair.at(i).second = tmp;
		}
		i++;
	}
}

void VectorSort::merge(std::vector<std::pair<int, int> > &array, int begin, int mid, int end)
{
	size_t indexLeftArray = 0;
	size_t indexRightArray = 0;
	size_t indexMergedA = begin;
	std::vector<std::pair<int, int> > leftArray(array.begin() + begin, array.begin() + mid + 1);
	std::vector<std::pair<int, int> > rightArray(array.begin() + mid + 1, array.begin() + end + 1);

	while (indexLeftArray < leftArray.size() && indexRightArray < rightArray.size())
	{
		if (leftArray[indexLeftArray].first <= rightArray[indexRightArray].first)
		{
			array[indexMergedA] = leftArray[indexLeftArray];
			indexLeftArray++;
		}
		else
		{
			array[indexMergedA] = rightArray[indexRightArray];
			indexRightArray++;
		}
		indexMergedA++;
	}
	while (indexLeftArray < leftArray.size())
	{
		array[indexMergedA] = leftArray[indexLeftArray];
		indexLeftArray++;
		indexMergedA++;
	}
	while (indexRightArray < rightArray.size())
	{
		array[indexMergedA] = rightArray[indexRightArray];
		indexRightArray++;
		indexMergedA++;
	}
}

void VectorSort::mergeSort(std::vector<std::pair<int, int> > &array, int begin, int end)
{
	if (begin >= end)
		return;
	int mid = begin + (end - begin) / 2;
	mergeSort(array, begin, mid);
	mergeSort(array, mid + 1, end);
	merge(array, begin, mid, end);
}

void VectorSort::createMainChainAndPend()
{
	size_t i = 0;
	mainChain.push_back(vecPair.at(0).second);
	while (i < vecPair.size())
	{
		mainChain.push_back(vecPair.at(i).first);
		pend.push_back(vecPair.at(i).second);
		i++;
	}
}

int VectorSort::binarySearch(std::vector<int> array, int target, int begin, int end)
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

void VectorSort::generateJacobsthalSequence()
{
	size_t jcobstalIndex;
	size_t size = pend.size();
	int index = 3;

	while ((jcobstalIndex = jacobsthalNum(index)) < size - 1)
	{
		jacobSequence.push_back(jcobstalIndex);
		index++;
	}
}

int VectorSort::jacobsthalNum(int n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	int jacobsthalNumber = jacobsthalNum(n - 1) + 2 * jacobsthalNum(n - 2);
	return (jacobsthalNumber);
}

void VectorSort::generateInsertionOrder()
{
	
	if (pend.empty())
		return;

	size_t val = 1;
	size_t pos;
	size_t lastPos = 1;
	size_t i = 0;
	generateJacobsthalSequence();

	while (i < jacobSequence.size())
	{
		val = jacobSequence.at(i);
		insertionOrder.push_back(val);
		pos = val - 1;
		while (pos > lastPos)
		{
			insertionOrder.push_back(pos);
			pos--;
		}
		lastPos = val;
		i++;
	}
	while (val++ < pend.size())
		insertionOrder.push_back(val);
}
void VectorSort::insertToMainChain()
{
    size_t addedCount = 0;

   	generateInsertionOrder();
    for (size_t i = 0; i < insertionOrder.size(); ++i)
    {
        int target = pend.at(insertionOrder[i] - 1);
        size_t endPos = insertionOrder[i] + addedCount;

        if (endPos > mainChain.size()) {
            endPos = mainChain.size();
        }
        std::vector<int>::iterator insertPos = std::lower_bound(mainChain.begin(), mainChain.begin() + endPos, target);
        mainChain.insert(insertPos, target);
        ++addedCount;
    }
    if (vec.size() % 2 != 0)
    {
        int target = vec.back();
        std::vector<int>::iterator insertPos = std::lower_bound(mainChain.begin(), mainChain.end(), target);
        mainChain.insert(insertPos, target);
    }
}
// void VectorSort::insertToMainChain()
// {
// 	std::vector<int>::iterator it;
// 	int target;
// 	size_t endPos;
// 	size_t addedCount = 0;
// 	size_t pos;

// 	generatePositions();
// 	for (it = insertionOrder.begin(); it < insertionOrder.end(); it++)
// 	{
// 		target = pend.at(*it - 1);
// 		endPos = *it + addedCount;
// 		pos = binarySearch(mainChain, target, 0, endPos);
// 		mainChain.insert(mainChain.begin() + pos, target);
// 		addedCount++;
// 	}
// 	if (vec.size() % 2 != 0)
// 	{
// 		target = vec.at(vec.size() - 1);
// 		pos = binarySearch(mainChain, target, 0, mainChain.size() - 1);
// 		mainChain.insert(mainChain.begin() + pos, target);
// 	}
// }

void VectorSort::populateVector(char *argv[])
{
	int i = 1;
	char *ptr;
	int val;
	while (argv[i])
	{
		val = strtol(argv[i], &ptr, 10);
		vec.push_back(val);
		i++;
	}
}

void VectorSort::mergeInsert(char *argv[])
{
	populateVector(argv);
	createPairs();
	sortPairs();
	mergeSort(vecPair, 0, vecPair.size() - 1);
	createMainChainAndPend();
	insertToMainChain();
}

void VectorSort::printContainer(const std::vector<int>& container) const {
    for (std::vector<int>::const_iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void VectorSort::printBefore() const
{
	printContainer(vec);
}

void VectorSort::printAfter() const
{
	printContainer(mainChain);
}

#include "iter.hpp"

int main()
{
   
    std::cout << "\033[33mArray of ints :\033[0m" << std::endl;
    int arr[] = {1, 2, 3, 4, 5};
    size_t len = sizeof(arr) / sizeof(arr[0]);
    iter(arr, len, printElement<int>);

    std::cout << "\033[33mArray of chars :\033[0m" << std::endl;
    char arrC[] = {'a', 'b', 'c', 'd', 'e'};
    len = sizeof(arrC) / sizeof(arrC[0]);
    iter(arrC, len, printElement<char>);
 std::cout << "\033[33mPointers: \033[0m" << std::endl;
    int* intpointer[5];
    char* charpointer[5];
    for (int i = 0; i < 5; i++)
    {
        charpointer[i] = &arrC[i];
        intpointer[i] = &arr[i];
    }
    iter(intpointer, 5, printElement<int*>);
    iter(*charpointer, 5, printElement<char>);

     std::cout << "\033[33mArray of doubles :\033[0m" << std::endl;
    double arrD[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    len = sizeof(arrD) / sizeof(arrD[0]);
    iter(arrD, len, printElement<double>);

    std::cout << "\033[33mArray of strings :\033[0m" << std::endl;
    std::string arrS[] = {"hello", "world", "this", "is", "test"};
    len = sizeof(arrS) / sizeof(arrS[0]);
    iter(arrS, len, printElement<std::string>);

    std::cout << "\033[33mArray of floats :\033[0m" << std::endl;
    float arrF[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
    len = sizeof(arrF) / sizeof(arrF[0]);
    iter(arrF, len, printElement<float>);

    // Edge cases
    std::cout << "\033[33mArray of min and max ints :\033[0m" << std::endl;
    int arrMinMaxInt[] = {std::numeric_limits<int>::min(), std::numeric_limits<int>::max()};
    len = sizeof(arrMinMaxInt) / sizeof(arrMinMaxInt[0]);
    iter(arrMinMaxInt, len, printElement<int>);

    std::cout << "\033[33mArray of min and max doubles :\033[0m" << std::endl;
    double arrMinMaxDouble[] = {std::numeric_limits<double>::min(), std::numeric_limits<double>::max()};
    len = sizeof(arrMinMaxDouble) / sizeof(arrMinMaxDouble[0]);
    iter(arrMinMaxDouble, len, printElement<double>);

    std::cout << "\033[33mArray of empty strings :\033[0m" << std::endl;
    std::string arrEmptyString[] = {"", ""};
    len = sizeof(arrEmptyString) / sizeof(arrEmptyString[0]);
    iter(arrEmptyString, len, printElement<std::string>);

    std::cout << "\033[33mArray of min and max floats :\033[0m" << std::endl;
    float arrMinMaxFloat[] = {std::numeric_limits<float>::min(), std::numeric_limits<float>::max()};
    len = sizeof(arrMinMaxFloat) / sizeof(arrMinMaxFloat[0]);
    iter(arrMinMaxFloat, len, printElement<float>);

    // std::cout << "\033[33mVery long array of ints :\033[0m" << std::endl;
    // const size_t longArraySize = 10000;
    // int longArray[longArraySize];
    // for (size_t i = 0; i < longArraySize; ++i)
    // {
    //     longArray[i] = i;
    // }
    // iter(longArray, longArraySize, printElement<int>);
    return(0);

}
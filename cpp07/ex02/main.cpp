#include <iostream>
#include "Array.hpp"


void testDefaultConstructor() {
    std::cout << "\033[33mTest default constructor:\033[0m" << std::endl;
    Array<int> arr1;
    std::cout << "arr1 size: " << arr1.size() << std::endl;
}

void testConstructorWithSize() {
    std::cout << "\033[33mTest constructor with size:\033[0m" << std::endl;
    Array<int> arr2(5);
    std::cout << "arr2 size: " << arr2.size() << std::endl;
    for (unsigned int i = 0; i < arr2.size(); ++i) {
        arr2[i] = i + 1;
        std::cout << "arr2[" << i << "]: " << arr2[i] << std::endl;
    }
}

void testCopyConstructor() {
    std::cout << "\033[33mTest copy constructor:\033[0m" << std::endl;
    Array<int> arr2(5);
    for (unsigned int i = 0; i < arr2.size(); ++i) {
        arr2[i] = i + 1;
    }
    Array<int> arr3(arr2);
    std::cout << "arr3 size: " << arr3.size() << std::endl;
    for (unsigned int i = 0; i < arr3.size(); ++i) {
        std::cout << "arr3[" << i << "]: " << arr3[i] << std::endl;
    }
}

void testAssignmentOperator() {
    std::cout << "\033[33mTest assignment operator:\033[0m" << std::endl;
    Array<int> arr2(5);
    for (unsigned int i = 0; i < arr2.size(); ++i) {
        arr2[i] = i + 1;
    }
    Array<int> arr4 = arr2;
    std::cout << "arr4 size: " << arr4.size() << std::endl;
    for (unsigned int i = 0; i < arr4.size(); ++i) {
        std::cout << "arr4[" << i << "]: " << arr4[i] << std::endl;
    }
}

void testOutOfBoundsException() {
    std::cout << "\033[33mTest out of bounds exception:\033[0m" << std::endl;
    Array<int> arr2(5);
    try {
        std::cout << "Accessing out of bounds element: " << arr2[10] << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

void testDifferentDataTypes() {
    std::cout << "\033[33mTest different data types:\033[0m" << std::endl;
    Array<double> arrDouble(3);
    arrDouble[0] = 1.1;
    arrDouble[1] = 2.2;
    arrDouble[2] = 3.3;
    for (unsigned int i = 0; i < arrDouble.size(); ++i) {
        std::cout << "arrDouble[" << i << "]: " << arrDouble[i] << std::endl;
    }

    Array<std::string> arrString(2);
    arrString[0] = "Hello";
    arrString[1] = "World";
    for (unsigned int i = 0; i < arrString.size(); ++i) {
        std::cout << "arrString[" << i << "]: " << arrString[i] << std::endl;
    }

}

void testModifyingElements() {
    std::cout << "\033[33mTest modifying elements:\033[0m" << std::endl;
    Array<int> arr2(5);
   for (unsigned int i = 0; i < arr2.size(); ++i) {
    std::cout << "arr2[" << i << "]: " << arr2[i] << std::endl;
    }
    arr2[0] = 42;
    std::cout << "After modification of arr2[0]: " << std::endl;
    for (unsigned int i = 0; i < arr2.size(); ++i) {
    std::cout << "arr2[" << i << "]: " << arr2[i] << std::endl;
    }
}

void testSelfAssignment() {
    std::cout << "\033[33mTest self-assignment:\033[0m" << std::endl;
    Array<int> arr2(5);
    arr2 = arr2;
    std::cout << "arr2 size after self-assignment: " << arr2.size() << std::endl;
}

void testEmptyArray() {
    std::cout << "\033[33mTest empty array:\033[0m" << std::endl;
    Array<int> arrEmpty;
    std::cout << "arrEmpty size: " << arrEmpty.size() << std::endl;
    try {
        std::cout << "Accessing element in empty array: " << arrEmpty[0] << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

void testLargeArray() {
    std::cout << "\033[33mTest large array:\033[0m" << std::endl;
    Array<int> arrLarge(1000);
    for (unsigned int i = 0; i < arrLarge.size(); ++i) {
        arrLarge[i] = i;
    }
    std::cout << "arrLarge[999]: " << arrLarge[999] << std::endl;
}

void testCopyConstructorAndDeepCopy() {
    std::cout << "\033[33mTest copy constructor and deep copy:\033[0m" << std::endl;
    Array<int> original(5);
    for (unsigned int i = 0; i < original.size(); ++i) {
        original[i] = i + 1;
    }
    Array<int> copyConstructed(original);
    std::cout << "Original array before modification: ";
    for (unsigned int i = 0; i < original.size(); ++i) {
        std::cout << original[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Copy constructed array before modification: ";
    for (unsigned int i = 0; i < copyConstructed.size(); ++i) {
        std::cout << copyConstructed[i] << " ";
    }
    std::cout << std::endl;

    original[0] = 42;
    copyConstructed[1] = 99;
    std::cout << "Original array after modification: ";
    for (unsigned int i = 0; i < original.size(); ++i) {
        std::cout << original[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Copy constructed array after modification: ";
    for (unsigned int i = 0; i < copyConstructed.size(); ++i) {
        std::cout << copyConstructed[i] << " ";
    }
    std::cout << std::endl;
}

void testAssignmentOperatorAndDeepCopy() {
    std::cout << "\033[33mTest assignment operator and deep copy:\033[0m" << std::endl;
    Array<int> original(5);
    for (unsigned int i = 0; i < original.size(); ++i) {
        original[i] = i + 1;
    }
    Array<int> assigned;
    assigned = original;
    std::cout << "Original array before modification: ";
    for (unsigned int i = 0; i < original.size(); ++i) {
        std::cout << original[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Assigned array before modification: ";
    for (unsigned int i = 0; i < assigned.size(); ++i) {
        std::cout << assigned[i] << " ";
    }
    std::cout << std::endl;

    original[2] = 77;
    assigned[3] = 88;
    std::cout << "Original array after modification of element at index 2: ";
    for (unsigned int i = 0; i < original.size(); ++i) {
        std::cout << original[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Assigned array after modification of element at index 3: ";  
    for (unsigned int i = 0; i < assigned.size(); ++i) {
        std::cout << assigned[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    try {
        testDefaultConstructor();
        testConstructorWithSize();
        testCopyConstructor();
        testAssignmentOperator();
        testOutOfBoundsException();
        testDifferentDataTypes();
        testModifyingElements();
        testSelfAssignment();
        testEmptyArray();
        testLargeArray();
        testCopyConstructorAndDeepCopy();
        testAssignmentOperatorAndDeepCopy();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

// int main() {
//     int *a = new int(); 
//     std::cout << "*a: " << *a << std::endl; 
//     delete a; 
//     int *b = new int; 
//     std::cout << "*b: " << *b << std::endl; 
//     return 0;
//  }
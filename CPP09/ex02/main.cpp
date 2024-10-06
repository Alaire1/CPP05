#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <sstream>
#include "PmergeMe.hpp"



bool isValidInteger(const char* str) {
    if (*str == '\0') return false;  // Empty string is not valid

    // Check for negative numbers (optional, based on your requirements)
    if (*str == '-')
        return false;  // Negative numbers are not valid

    while (*str) {
        if (!std::isdigit(*str)) {
            return false;  // Found a non-digit character
        }
        str++;
    }
    return true;  // All characters are digits
}

// Function to check values and populate containers
bool checkValues(int ac, char **av) {
    std::list<int> listContainer;
    std::deque<int> deqContainer;

    for (int i = 1; i < ac; i++) { // Change `i <= ac` to `i < ac`
        if (av[i]) {
            
            if (!isValidInteger(av[i])) {
                std::cout << "Error: Invalid argument: " << av[i] << std::endl;
                return false; // Indicate failure
            }
            listContainer.push_back(std::atoi(av[i]));
            deqContainer.push_back(std::atoi(av[i]));
        }
    }
    sortlist(listContainer, listContainer.size());
    sortdeq(deqContainer, deqContainer.size());

    return true; // Indicate success
}

int main(int ac, char **av) {
    if (ac < 2) {
        std::cout << "Error: bad arguments" << std::endl;
        return 1;
    } else {
        if (!checkValues(ac, av)) {
            return 1; // Handle invalid values
        }
    }
    return 0;
}
// bool checkValues(int ac, char **av) {
//     std::list<int> listContainer;
//     std::deque<int> deqContainer;
//     for (int i = 1; i <= ac; i++) { 
//             if (av[i]) {
//                 if (!isdigit(av[i])) {
//                     std::cout << "Error: Invalid argument: " << av[i] << std::endl;
//                     return 1;
//                 }
//                 listContainer.push_back(std::atoi(av[i]));
//                 deqContainer.push_back(std::atoi(av[i]));
//             }
//     sortlist(listContainer, ac - 1);
//     sortdeq(deqContainer, ac - 1);
//     }
// }

// int main(int ac, char **av) {
//     if (ac < 2) {
//         std::cout << "Error: bad arguments" << std::endl;
//         return 1;
//     } else {
//         checkValues(ac, av); 
//     }
//     return 0;
// }
// int main(int ac, char **av){
// 	if(ac < 2){
// 		std::cout << "Error: bad arguments" << std::endl;
// 		return 1;
// 	}
// 	else{
// 		std::list<int> listContainer;
// 		std::deque<int> deqContainer;
// 		for (int i = 1; i <= ac; i++){
// 			if (av[i]){
// 				for(int j = 0; av[i][j]; j++){
// 					if (!std::isdigit(av[i][j])){
// 						std::cout << "Error: Invalid argument: " << av[i] << std::endl;
// 						return 1;
// 					}
// 				}
// 				listContainer.push_back(std::atoi(av[i]));
// 				deqContainer.push_back(std::atoi(av[i]));
// 			}
// 		}
// 		sortlist(listContainer, ac - 1);
// 		sortdeq(deqContainer, ac - 1);
// 	}
// }
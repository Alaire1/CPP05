#include "PmergeMe.hpp"


void checkValues(int ac, char **av){
    std::vector<int> vectContainer;
    std::deque<int> deqContainer;
    bool isSorted = true; 
	for (int i = 1; i <= ac; i++){
		if (av[i]){
			for(int j = 0; av[i][j]; j++){
				if (!std::isdigit(av[i][j])){
					std::cout << RED <<"Error: Invalid argument: " << RESET << av[i] << std::endl;
					return;
				}
                int value = std::atoi(av[i]);
                if (!vectContainer.empty() && value < vectContainer.back()) {
                    isSorted = false; 
                }
			}
    		vectContainer.push_back(std::atoi(av[i]));
			deqContainer.push_back(std::atoi(av[i]));
		}
	}
    if (isSorted) {
        std::cout << GREEN << "Notice: The input values are already sorted." << RESET << std::endl;
        return;
    }
    sortvect(vectContainer, ac - 1);
	sortdeq(deqContainer, ac - 1);
}

int main(int ac, char **av){
	if(ac < 2){
		std::cout << RED << "Error: bad arguments" << RESET << std::endl;
		return 1;
	}
    checkValues(ac, av);
}
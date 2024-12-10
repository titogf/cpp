#include "PmergeMe.hpp"

int check(char **argv){
    for (int j = 1; argv[j]; j++){
        for (int i = 0; argv[j][i]; i++){
            if (!std::isdigit(argv[j][i]) && argv[j][i] != ' '){
                std::cout << RED << "Error" << NOC << std::endl;
                return 0;
            }
        }
    }
    return 1;
}

int main(int argc, char **argv){
    if (argc < 2 || argc > 3001){
        std::cout << RED << "Error: Between 2 and 3001 arguments are expected" << NOC << std::endl;
        return -1;
    }
    if (!check(argv)) return -1;
    PmergeMe m = PmergeMe(argv);
    return 0;
}
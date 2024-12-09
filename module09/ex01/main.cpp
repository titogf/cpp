#include "RPN.hpp"

int check(std::string argv){
    for (int i = 0; argv[i]; i++){
        if ((!std::isdigit(argv[i]) && argv[i] != '+' && argv[i] != '-' && argv[i] != '*' && argv[i] != '/' && argv[i] != ' ')
            || (argv[i] != ' ' && argv[i + 1] && argv[i + 1] != ' ')){
            std::cout << RED << "Error" << NOC << std::endl;
            return 0;
        }
    }
    return 1;
}

int main(int argc, char **argv){
    if (argc != 2){
        std::cout << RED << "Error: Two arguments are expected" << NOC << std::endl;
        return -1;
    }
    if (!check(argv[1])) return -1;
    RPN rpn = RPN(argv[1]);
    return 0;
}
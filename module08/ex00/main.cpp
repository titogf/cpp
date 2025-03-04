#include "easyfind.hpp"

int main(void){

    std::vector<int> vec;
    std::list<int> lst;

    for (int i = 0; i < 10; i++){
        vec.push_back(i + 1);
        lst.push_back(i + 1);
    }
    std::cout << "Vector: " << std::endl;
    easyfind(vec, 5);
    easyfind(vec, 42);
    std::cout << std::endl << "List: " << std::endl;
    easyfind(lst, 5);
    easyfind(lst, 42);

    return 0;
}
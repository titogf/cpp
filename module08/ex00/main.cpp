#include "easyfind.hpp"

int main(void){

    std::vector<int> vec;
    std::array<int, 5> arr = {1, 2, 3, 4, 5};

    for (int i = 0; i < 10; i++)
        vec.push_back(i + 1);
    int vector = ::easyfind(vec, 1);
    int array = ::easyfind(arr, 6);
    std::cout << "VECTOR: " << vector << std::endl << "ARRAY: " << array << std::endl;

    return 0;
}
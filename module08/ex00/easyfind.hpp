#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

template<typename T>
int easyfind(T t, int i){
    typename T::const_iterator value = std::find(t.begin(), t.end(), i);
    if (value == t.end()){
        std::cout << "Value not found" << std::endl;
        return -1;
    }
    std::cout << "Value found: " << *value << std::endl;
    return 0;
}

#endif
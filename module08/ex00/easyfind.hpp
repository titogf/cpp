#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

template<typename T>
typename T::iterator easyfind(T t, int i){
    typename T::iterator it = std::find(t.begin(), t.end(), i);
    if (it == t.end()){
        std::cout << "Value not found" << std::endl;
        return it;
    }
    std::cout << "Value found: " << *it << std::endl;
    return it;
}

#endif
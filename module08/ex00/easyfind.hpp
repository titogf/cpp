#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>

template<typename T>
int easyfind(T t, int i){
    typename T::const_iterator value = std::find(t.begin(), t.end(), i);
    if (value == t.end())
        return -1;
    return 0;
}

#endif
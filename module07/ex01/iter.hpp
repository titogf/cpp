#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *address, int len, void(*fn)(T)){
    for (int i = 0; i < len; i++)
        fn(address[i]);
}

#endif
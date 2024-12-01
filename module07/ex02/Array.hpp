#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept> // For std::out_of_range

template<typename T>
class Array{
    private:
        T *arr;
        unsigned int _i;

    public:
        Array();
        Array(unsigned int n);
        Array(const Array<T>& other);
        Array<T>& operator=(const Array<T>& other);
        ~Array();

        T& operator[](unsigned int index);
        const T& operator[](unsigned int index) const;

        void setArr(const Array<T>& t);
        const T* getArr(void) const;
};

#include "Array.tpp"

#endif
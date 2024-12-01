#include "Array.hpp"

template<typename T>
Array<T>::Array() : arr(NULL), _i(0) {}

template<typename T>
Array<T>::Array(unsigned int n) : _i(n) {
    arr = (_i > 0) ? new T[_i] : NULL;
    for (unsigned int i = 0; i < _i; i++)
        arr[i] = T();
}

template<typename T>
Array<T>::Array(const Array<T>& other) : _i(other._i) {
    arr = (_i > 0) ? new T[_i] : NULL;
    for (unsigned int i = 0; i < _i; i++)
        this->arr[i] = other.arr[i];
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
    if (this == &other)
        return *this;

    delete[] arr;
    _i = other._i;
    arr = (_i > 0) ? new T[_i] : NULL;
    for (unsigned int i = 0; i < _i; i++)
        this->arr[i] = other.arr[i];
    return *this;
}

template<typename T>
Array<T>::~Array(void) {
    delete[] arr;
}

template<typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= _i) {
        throw std::out_of_range("Index out of bounds");
    }
    return arr[index];
}

template<typename T>
const T& Array<T>::operator[](unsigned int index) const {
    if (index >= _i) {
        throw std::out_of_range("Index out of bounds");
    }
    return arr[index];
}

template<typename T>
void Array<T>::setArr(const Array<T>& t) {
    if (this == &t)
        return;

    delete[] arr;
    _i = t._i;
    arr = (_i > 0) ? new T[_i] : NULL;
    for (unsigned int i = 0; i < _i; i++) {
        arr[i] = t.arr[i];
    }
}

template<typename T>
const T* Array<T>::getArr(void) const { return arr; }

template<typename T>
unsigned int Array<T>::size(){return _i;}
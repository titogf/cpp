#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>
#include <iterator>
#include <iostream>

template<typename T>
class MutantStack : public std::stack<T> {
public:
    typedef typename std::deque<T>::reverse_iterator iterator;

    MutantStack() : std::stack<T>() {}
    MutantStack(const MutantStack& other) : std::stack<T>(other) {}
    ~MutantStack() {}
    
    MutantStack& operator=(const MutantStack& other) {
        if (this != &other) {
            std::stack<T>::operator=(other);
        }
        return *this;
    }

    iterator begin() { return this->c.rbegin(); }
    iterator end() { return this->c.rend(); }
};

#endif

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>

class Span{
    private:
        unsigned int currentIndex;
        unsigned int size;
        std::vector<int> value;
    public:
        Span();
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span(void);

        void addNumber(int num);
        int shortestSpan();
        int longestSpan();

};

#endif
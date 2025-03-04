#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>

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
        void addNumber(unsigned int numbers, time_t time);
        int shortestSpan();
        int longestSpan();

};

#endif
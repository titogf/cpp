#include "Span.hpp"

Span::Span() : currentIndex(0), size(0) {}

Span::Span(unsigned int n) : currentIndex(0), size(n) {
    value.resize(n);
}

Span::Span(const Span& other) : currentIndex(other.currentIndex), size(other.size), value(other.value) {}

Span& Span::operator=(const Span& other) {
    if (this == &other)
        return *this;
    value = other.value;
    currentIndex = other.currentIndex;
    return *this;
}

Span::~Span(void) {}

void Span::addNumber(int num) {
    if (currentIndex >= size) {
        throw std::runtime_error("Span is full, cannot add more numbers");
    }
    value[currentIndex] = num;
    currentIndex++;
}

int Span::shortestSpan(){
    if (size < 2)
        throw std::runtime_error("Size to small");
    int min = -1;
    std::sort(value.begin(), value.end());
    for (unsigned int i = 1; i < size; i++){
        int aux = value[i] - value[i - 1];
        if (min == -1 || min > aux)
            min = aux;
    }
    return min;
}

int Span::longestSpan(){
    if (size < 2)
        throw std::runtime_error("Size to small");
    std::sort(value.begin(), value.end());
    return value[size - 1] - value[0];
}

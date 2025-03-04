#include "Span.hpp"

int main(void){
    Span sp = Span(5);
    
    std::cout << "-----------------------------------" << std::endl;
    try {
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest: " << sp.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "-----------------------------------" << std::endl;
    Span sp2 = Span(15);
    try {
        sp2.addNumber(15, time(NULL));
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        std::cout << "Shortest: " << sp2.shortestSpan() << std::endl;
        std::cout << "Longest: " << sp2.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    
    return 0;
}
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <sstream>
#include <ctime>
#include <iomanip>

#define NOC	"\033[0m"
#define GREEN "\033[1;32m"
#define RED	"\033[1;31m"

class PmergeMe{
    private:
        std::vector<int> vector;
        std::list<int> list;
    public:
        PmergeMe();
        PmergeMe(char **numbers);
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();
        
        void mergeInsertionSortVector(std::vector<int>& arr, size_t left, size_t right);
        void mergeVectors(std::vector<int>& arr, size_t left, size_t mid, size_t right);
        void insertionSortVector(std::vector<int>& arr, size_t left, size_t right);
        void mergeInsertionSortList(std::list<int>& lst);
        std::list<int> mergeLists(const std::list<int>& left, const std::list<int>& right);
        void insertionSortList(std::list<int>& lst);
};

#endif
#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(char **numbers) {
    if (!numbers[1]) {
        std::cout << RED << "Error: No numbers provided" << NOC << std::endl;
        return;
    }

    std::cout << "Before: ";
    for (int i = 1; numbers[i]; i++) {
        std::istringstream ss(numbers[i]);
        int num;
        while (ss >> num) {
            std::cout << num << " ";
            vector.push_back(num);
            list.push_back(num);
        }
    }
    std::cout << std::endl;

    clock_t vectorStart = clock();
    mergeInsertionSortVector(vector, 0, vector.size() - 1);
    clock_t vectorEnd = clock();
    std::cout << "After: ";
    for (size_t i = 0; i < vector.size(); i++) {
        std::cout << vector[i] << " ";
    }
    std::cout << std::endl;
    double vectorDuration = double(vectorEnd - vectorStart) / CLOCKS_PER_SEC;
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Time to process a range of " << vector.size() << " elements with std::vector : " 
              << vectorDuration << " us" << std::endl;


    clock_t listStart = clock();
    mergeInsertionSortList(list);
    clock_t listEnd = clock();
    double listDuration = double(listEnd - listStart) / CLOCKS_PER_SEC;
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Time to process a range of " << list.size() << " elements with std::list   : " 
              << listDuration << " us" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe& other) : vector(other.vector){}
PmergeMe& PmergeMe::operator=(const PmergeMe& other){
    if (this != &other){
        vector = other.vector;
    }
    return *this;
}
PmergeMe::~PmergeMe() {}



// Implementación del algoritmo Merge-Insertion Sort para vector
void PmergeMe::mergeInsertionSortVector(std::vector<int>& arr, size_t left, size_t right) {
    if (right - left + 1 <= 5) {
        insertionSortVector(arr, left, right);
        return;
    }
    size_t mid = left + (right - left) / 2;
    mergeInsertionSortVector(arr, left, mid);
    mergeInsertionSortVector(arr, mid + 1, right);
    mergeVectors(arr, left, mid, right);
}

void PmergeMe::mergeVectors(std::vector<int>& arr, size_t left, size_t mid, size_t right) {
    std::vector<int> temp(right - left + 1);
    size_t i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    for (size_t m = 0; m < temp.size(); m++) {
        arr[left + m] = temp[m];
    }
}

void PmergeMe::insertionSortVector(std::vector<int>& arr, size_t left, size_t right) {
    for (size_t i = left + 1; i <= right; i++) {
        int key = arr[i];
        size_t j = i;
        while (j > left && arr[j - 1] > key) {
            arr[j] = arr[j - 1];
            --j;
        }
        arr[j] = key;
    }
}

// Implementación del algoritmo Merge-Insertion Sort para list
void PmergeMe::mergeInsertionSortList(std::list<int>& lst) {
    if (lst.size() <= 5) {
        insertionSortList(lst);
        return;
    }

    std::list<int>::iterator mid = lst.begin();
    std::advance(mid, lst.size() / 2);
    std::list<int> left(lst.begin(), mid);
    std::list<int> right(mid, lst.end());

    mergeInsertionSortList(left);
    mergeInsertionSortList(right);
    lst = mergeLists(left, right);
}

std::list<int> PmergeMe::mergeLists(const std::list<int>& left, const std::list<int>& right) {
    std::list<int> result;
    std::list<int>::const_iterator it1 = left.begin();
    std::list<int>::const_iterator it2 = right.begin();
    while (it1 != left.end() && it2 != right.end()) {
        if (*it1 <= *it2) {
            result.push_back(*it1++);
        } else {
            result.push_back(*it2++);
        }
    }
    result.insert(result.end(), it1, left.end());
    result.insert(result.end(), it2, right.end());
    return result;
}

void PmergeMe::insertionSortList(std::list<int>& lst) {
    for (std::list<int>::iterator it = ++lst.begin(); it != lst.end(); ++it) {
        int key = *it;
        std::list<int>::iterator j = it;
        while (j != lst.begin() && *--std::list<int>::iterator(j) > key) {
            *j = *--std::list<int>::iterator(j);
            --j;
        }
        *j = key;
    }
}
#include "Array.hpp"

int main(void){
    Array<int> a (4);
    for (int j = 0; j < 4; j++){
        try {
            a[j] = j + 1;
        } catch (std::out_of_range &e) {
            std::cout << e.what() << std::endl;
        }
    }

    Array<int> i = a;
    std::cout << "i[3] = " << i[3] << " a[3] = " << a[3] << std::endl;

    //Array<int> b(i);
    Array<int> b;
    b.setArr(i);
    for (int j = 0; j < 4; j++){
        try {
            std::cout << b[j] << std::endl;
        } catch (std::out_of_range &e) {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << "Size: " << b.size() << std::endl;
    Array<int> k (32);
    std::cout << "Size: " << k.size() << std::endl;
}
#include "Array.hpp"

int main(void){
    Array<int> i;

    Array<int> a (4);
    for (int j = 0; j < 4; j++){
        a[j] = j + 1;
    }
    i = a;

    Array<int> b(i);
    //b.setArr(i);
    for (int j = 0; j < 4; j++){
        std::cout << b[j] << std::endl;
    }
}
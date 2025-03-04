#include "MutantStack.hpp"
#include <list>

int main(void)
{
    MutantStack<int> mstack;
    std::list<int> lst;

    lst.push_back(5);
    mstack.push(5);

    lst.push_back(17);
    mstack.push(17);

    std::cout << "Mstack top:" << mstack.top() << std::endl;
    std::cout << "Lst top   :" << lst.back() << std::endl;

    mstack.pop();
    lst.pop_back();

    std::cout << "Mstack size:" << mstack.size() << std::endl;
    std::cout << "Lst size   :" << lst.size() << std::endl;

    lst.push_back(3);
    mstack.push(3);

    lst.push_back(5);
    mstack.push(5);

    lst.push_back(737);
    mstack.push(737);

    lst.push_back(0);
    mstack.push(0);

    std::cout << "---------------------------------" << std::endl;
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
        std::cout << *it << std::endl;

    std::cout << "---------------------------------" << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    return 0;
}
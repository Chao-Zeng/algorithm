#include "stack.hpp"
#include <iostream>

int main()
{
    stack<int> test_stack;
    for (int i = 0; i < 5; i++)
    {
        test_stack.push(i);
    }
    std::cout << test_stack << "\n";

    std::cout << "pop 2 elements\n";
    test_stack.pop();
    test_stack.pop();
    std::cout << test_stack << "\n";

    std::cout << test_stack.top() << "\n";
    

    return 0;
}

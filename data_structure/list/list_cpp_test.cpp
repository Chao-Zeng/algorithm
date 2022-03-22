#include "list_cpp.h"

int main()
{
    list<int> test_list;

    std::cout << "push back 10-19\n";
    for (int i = 10; i < 20; i++)
    {
        test_list.push_back(i);
    }
    print_list(test_list);

    std::cout << "push front 0-9\n";
    for (int i = 9; i >= 0; i--)
    {
        test_list.push_front(i);
    }
    print_list(test_list);
    
    std::cout << "pop back\n";
    test_list.pop_back();
    print_list(test_list);

    std::cout << "pop front\n";
    test_list.pop_front();
    print_list(test_list);

    std::cout << "back\n";
    std::cout << test_list.back() << "\n";
    print_list(test_list);

    std::cout << "front\n";
    std::cout << test_list.front() << "\n";
    print_list(test_list);

    std::cout << "clean\n";
    test_list.clean();
    print_list(test_list);    

    return 0;
}

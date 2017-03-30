#include "list.h"

//#define list_value_type int

int main(int argc, char* argv[])
{
    list l = create_list();
    printf("empty list\n");
    print_list(l);

    //insert at head
    printf("insert at first\n");
    insert(l, 1);
    print_list(l);

    //insert at last
    printf("insert at last\n");
    node_ptr pos = find(l, 1);
    insert(pos, 10);
    print_list(l);

    //insert elements
    printf("insert elements\n");
    insert(l,2);
    insert(l,3);
    insert(l,4);
    insert(l,5);
    print_list(l);

    //delete first
    printf("delete first\n");
    pos = first(l);
    delete(l, pos);
    print_list(l);

    //delete last
    printf("delete last\n");
    pos = find(l, 10);
    delete(l, pos);
    print_list(l);
    return 0;
}
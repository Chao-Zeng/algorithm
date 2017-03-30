#include <stddef.h>
#include <stdio.h>

void insertion_sort(int* array, size_t n)
{
    for(int i = 1; i < n; ++i)
    {
        int key = array[i];
        int j = i - 1;
        while(j >= 0 && array[j] > key)
        {
            array[j+1] = array[j];
            j -= 1;
        }

        array[j+1] = key;
    }
}

int main(int argc, char* argv[])
{
    int a[10] = {2,1,4,7,9,3,6,5,8,0};

    insertion_sort(a, 10);

    for(int i = 0; i < 10; ++i)
    {
        printf("%d, ", a[i]);
    }
    printf("\n");

    return 0;
}


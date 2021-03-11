#include "stdio.h"
#include "stdlib.h"
#define N       100
#define NOVAL   -1

int arr[N];

/*tablice nieuporządkowane == kolejność elementów nieznana*/
int search(int *arr, int val, size_t n)
{
        // for (short i = 0; i < n; i++) {
        //         if (*(arr + i) == val)
        //                 return i;
        // }
        // return NOVAL;
        short i = 0;
        while 
}

int search_sentinel(int *arr, int val, size_t n)
{
        // *(arr + n) = val;
        arr[n] = val;
        short i = 0;
        while (arr[i] != val)
                i++;

        if (i < n)
                return i;
        return NOVAL;
}
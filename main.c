#include "stdlib.h"
#include "linked-lists/single_linked_list.c"
#include "arrays/array.c"



int main(void)
{
        int arr[] = { 10, 20, 180, 30, 60, 50, 110, 100, 70 };
        int inorder[] = {11 ,20, 30, 50, 60, 70, 100, 110, 180};
        int n = sizeof(arr) / sizeof(arr[0]);
        int key = 180;
        int x = search(arr, key, n);
        x = sentinel_search(arr, key, n);
        x = binary_search(inorder, 20, n);
        x = inter_search(inorder, 50, n);
        int tmp = 0;

        return 0;
}

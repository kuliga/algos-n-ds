#include "stdio.h"
#include "stdlib.h"
#define N       100
#define NOVAL   -1


/*tablice nieuporządkowane == kolejność elementów nieznana*/
int search(int *arr, int val, size_t n)
{
        for (short i = 0; i < n; i++) {
                if (arr[i] == val)
                        return i;
        }
        return NOVAL;
}

int sentinel_search(int *arr, int val, size_t n)
{
        int tmp = arr[n - 1];
        arr[n - 1] = val;
        short i = 0;
        while (arr[i] != val)
                i++;

        arr[n - 1] = tmp;
        if (i < n)
                return i;
        return NOVAL;
}

/*tablice uporządkowane*/
//tablica uporządkowana niemalejąkco*/
int binary_search(int *arr, int val, size_t n)
{
        short l, r, k; //lewa prawa granica, kolejny indeks
        l = 0;
        r = n - 1;
        k = n / 2;
        int tmp;
        while (l <= r) { 
                k = (l + r) / 2;
                tmp = arr[k];
                if (tmp == val)
                        return k;
        
                if (tmp < val)
                        l = k + 1;
                else 
                        r  = k - 1;
        }
        return NOVAL;
}

int inter_search(int *arr, int val, size_t n)
{
        short l, r, k; //lewa, prawa granica, kolejny indeks
        float coeff; //współczynnik interpolacji
        int tmp;
        l = 0;
        r = n - 1;
        coeff = (val - arr[l]) / (arr[r] - arr[l]);
        if (coeff > 1 || coeff < 0)
                goto exit;
        do {
                k = l + coeff * (r - l);
                tmp = arr[k];
                if (tmp == val)
                        return k;
                
                if (tmp < val)
                        l = k + 1;
                else 
                        r = k - 1;

                coeff = (val - arr[l]) / (arr[r] - arr[l]);
        } while (coeff < 1 || coeff > 0);
exit:
        return NOVAL;
}
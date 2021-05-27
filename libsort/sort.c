
#include <stdlib.h>

#define SWAP(type, a, b) 	\
	do {		 	\
		type eee = a;	\
		a = b;		\
		b = eee;	\
	} while (0)
		


void selsort(int *arr, size_t len)
{	
	size_t idxofmin = 0;
	for (size_t i = 0; i < len - 1; i++) {
		idxofmin = i;
		for (size_t j = i + 1; j < len; j++) {
			if (arr[idxofmin] > arr[j])
				idxofmin = j;
		}
		SWAP(int, arr[i], arr[idxofmin]);
	}
}		

void inssort(int *arr, size_t len)
{
	int tmp;
	for (size_t i = 1; i < len; i++) {
		tmp = arr[i];
		size_t j = i - 1;
		while ((j > 0) && (tmp < arr[j])) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = tmp;
	}
}





#include "vector.h"

int* splice(int arr1[], int len1, int arr2[], int len2, int pos){

    int index1 = 0; int index2 = 0; int index3 = 0;
    int* new_arr = new int[len1 + len2];

    if (pos < 0 || pos > len1) return NULL;

    for(index1, index2; index1 < pos; index1++, index2++) new_arr[index1] = arr1[index2];

    for (index2, index3; index3 < len2; index2++, index3++) new_arr[index2] = arr2[index3];

    for  (; index1 < len1; index1++, index2++) new_arr[index2] = arr1[index1];


    return new_arr;
     
}



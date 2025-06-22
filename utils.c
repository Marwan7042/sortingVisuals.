/*
    utils.c
    -------
    This file implements utility functions for the sorting algorithms.
    swap() exchanges two integers. merge() merges two sorted subarrays
    into a single sorted segment (used by merge sort).
*/

#include "utils.h"
#include <stdlib.h>

// Swaps the values at two integer pointers
void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Merges two sorted subarrays a[low..mid] and a[mid+1..high] into a single sorted array
void merge(int a[], int low, int mid, int high)
{
    int s1 = mid - low + 1;
    int s2 = high - mid;

    int *arr1 = malloc(s1 * sizeof(int));
    int *arr2 = malloc(s2 * sizeof(int));
    int *resultant = malloc((s1 + s2) * sizeof(int));

    if (!arr1 || !arr2 || !resultant) {
        // Handle allocation failure
        free(arr1); free(arr2); free(resultant);
        return;
    }

    for (int x = 0; x < s1; x++)
        arr1[x] = a[low + x];
    for (int x = 0; x < s2; x++)
        arr2[x] = a[mid + 1 + x];

    int i = 0, j = 0, k = 0;
    while (i < s1 && j < s2)
    {
        if (arr1[i] < arr2[j])
            resultant[k++] = arr1[i++];
        else
            resultant[k++] = arr2[j++];
    }
    while (i < s1)
        resultant[k++] = arr1[i++];
    while (j < s2)
        resultant[k++] = arr2[j++];

    for (int x = 0; x < s1 + s2; x++)
        a[low + x] = resultant[x];

    free(arr1);
    free(arr2);
    free(resultant);
}
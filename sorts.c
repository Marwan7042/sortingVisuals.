/*
    sorts.c
    -------
    This file contains the implementations of three sorting algorithms:
    Selection Sort, Bubble Sort, and Merge Sort. Each function sorts an
    array and calls print_bars() after each key step to visualize the
    sorting process as horizontal bars.
*/

#include <stdio.h>
#include "sorts.h"
#include "utils.h"
#include "visuals.h"

// Selection Sort: Finds the smallest element and puts it in place
void selection_sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if(a[minIndex] > a[j])
                minIndex = j;
        }
        swap(&a[i], &a[minIndex]);
        print_bars(a, n, "Selection step:");
    }
}

// Bubble Sort: Repeatedly swaps adjacent elements if they are in the wrong order
void bubble_sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(&a[j + 1], &a[j]);
                swapped = 1;
                print_bars(a, n, "Bubble step:");
            }
        }
        if (swapped == 0) break; // Stop if already sorted
    }
}

// Merge Sort: Recursively splits the array and merges sorted halves
void merge_sort(int a[], int low, int high)
{
    if (low >= high) return;
    int mid = low + (high - low) / 2;
    merge_sort(a, low, mid);
    merge_sort(a, mid + 1, high);
    merge(a, low, mid, high);
    print_bars(a + low, high - low + 1, "Merge step:");
}

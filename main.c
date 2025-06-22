/*
    main.c
    -------
    This is the entry point of the sorting visualization project.
    It creates an array, copies it for each sorting algorithm, and
    runs Selection Sort, Bubble Sort, and Merge Sort on the same data.
    The program visualizes each sorting process with bars and compares
    their run times, printing which algorithm was the fastest.
*/

#include <stdio.h>
#include <time.h>
#include "sorts.h"
#include "visuals.h"

#define N 20 // You can change this for a bigger or smaller array

int main(void)
{
    int original[N], a[N], b[N], c[N];
    clock_t start, end;
    double t_sel, t_bub, t_mer;

    // Fill the original array with values in descending order
    for (int i = 0; i < N; i++)
        original[i] = N - i;

    printf("Initial array:\n");
    print_bars(original, N, NULL);

    // Selection Sort
    for (int i = 0; i < N; i++) a[i] = original[i]; // Copy original for fairness
    printf("\n--- Selection Sort Visualization ---\n");
    start = clock();
    selection_sort(a, N);
    end = clock();
    t_sel = (double)(end - start) / CLOCKS_PER_SEC;

    // Bubble Sort
    for (int i = 0; i < N; i++) b[i] = original[i];
    printf("\n--- Bubble Sort Visualization ---\n");
    start = clock();
    bubble_sort(b, N);
    end = clock();
    t_bub = (double)(end - start) / CLOCKS_PER_SEC;

    // Merge Sort
    for (int i = 0; i < N; i++) c[i] = original[i];
    printf("\n--- Merge Sort Visualization ---\n");
    start = clock();
    merge_sort(c, 0, N - 1);
    end = clock();
    t_mer = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nFinal Results:\n");
    printf("Selection: "); print_array(a, N, NULL);
    printf("Bubble: ");    print_array(b, N, NULL);
    printf("Merge: ");     print_array(c, N, NULL);

    printf("\n--- Sorting Times ---\n");
    printf("Selection Sort Time: %.6f seconds\n", t_sel);
    printf("Bubble Sort Time:    %.6f seconds\n", t_bub);
    printf("Merge Sort Time:     %.6f seconds\n", t_mer);

    // Print which algorithm was the fastest
    printf("\n--- Sorting Winner ---\n");
    if (t_sel < t_bub && t_sel < t_mer)
        printf("Selection Sort is the winner!\n");
    else if (t_bub < t_sel && t_bub < t_mer)
        printf("Bubble Sort is the winner!\n");
    else if (t_mer < t_sel && t_mer < t_bub)
        printf("Merge Sort is the winner!\n");
    else
        printf("It's a tie!\n");

    return 0;
}
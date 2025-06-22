/*
    visuals.c
    ---------
    This file implements visualization functions for arrays.
    print_array() prints the array as numbers.
    print_bars() prints the array as horizontal bars, and clears the
    screen before each step to create an animation effect.
*/

#include <stdio.h>
#include <windows.h> // For Sleep and system("cls")
#include "visuals.h"

// Prints the array as numbers, with an optional label
void print_array(const int arr[], int n, const char *label) {
    if (label) printf("%s", label);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Prints the array as horizontal bars for visualization
void print_bars(const int arr[], int n, const char *label) {
#ifdef _WIN32
    system("cls"); // Clear the terminal screen on Windows
#else
    system("clear"); // On Linux/Mac
#endif
    if (label) printf("%s\n", label);
    for (int i = 0; i < n; i++) {
        printf("%2d: ", arr[i]);
        for (int j = 0; j < arr[i]; j++)
            printf("#");
        printf("\n");
    }
    printf("\n");
    // Sleep(1); // Uncomment for a very short delay if needed
}
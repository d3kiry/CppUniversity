#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

typedef float* TDynArray;  

int main() {
    printf("------------------------------------\nLabWork number 2\nCreator : Borisov Vadim Pavlovich\nGroup : BBSO - 01 - 24\nVariant : 6\n------------------------------------\n");
    int n = 5;
    printf("Size of array:\n");
    scanf("%i", &n);
    TDynArray A;
    A = malloc(sizeof(float) * n); 
    printf("------------------------------------\nGenerating array...\n");
    srand(time(NULL)); 
    for (int i = 0; i < n; i++) {
        A[i] = -20 + 1.0 * rand() / RAND_MAX * 40; 
        printf("%.3f\n", A[i]);
    }
    int a, b, ans4task1 = 0;
    printf("------------------------------------\nTask 1\nInput A:\n");
    scanf("%i", &a);
    printf("Input B:\n");
    scanf("%i", &b);
    if (a < 0 || b < 0 || a >= n || b >= n || a == b || b < a) {
        printf("Invalid input\n");
    } else {
        for (int i = a; i < b; i++) {
            ans4task1++;
        }
        printf("elements on segment [a:b]: %i\n", ans4task1);
    }
    printf("------------------------------------\nTask 2\n");
    float max = A[0];
    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (A[i] > max) {
            max = A[i];
            maxIndex = i;
        }
    }
    printf("Maximum element: %.3f at index %d\n", max, maxIndex);
    if (maxIndex < n - 1) {
        float ans4task2 = 1.0;
        for (int i = maxIndex + 1; i < n; i++) {
            ans4task2 *= A[i];
        }
        printf("Product of elements after the maximum element: %.3f\n", ans4task2);
    } else {
        printf("No elements after max element.\n");
    }
    printf("------------------------------------\nTask 3\n");
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (fabs(A[j]) < fabs(A[j + 1])) {
                float temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%.3f\n", A[i]);
    }   
    free(A);
}
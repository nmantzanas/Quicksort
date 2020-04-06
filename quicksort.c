//
//  main.c
//  quick_sort
//
//  Created by Nico Mantzanas on 02.04.20.
//  Copyright © 2020 Nico Mantzanas. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void swap(int* a, int* b)
{
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}


int LomutoPartition(int A[], int l, int r)
{
    int x, i, j;

    x = A[r];
    i = l - 1;

    for (j = l; j <= r - 1; j++) {

        if (A[j] <= x) {
            i++;
            swap(&A[i], &A[j]);
        }
    }

    swap(&A[i+1], &A[r]);

    return i + 1;
}


void QuickSort(int A[], int l, int r)
{
    if (l < r) {
        int m = LomutoPartition(A, l, r);
        QuickSort(A, l, m-1);
        QuickSort(A, m+1, r);
    }
}




void printArray(int A[], int n)
{
  int i;
  for (i = 0; i < n; i++) {
    printf("%d ", A[i]);
  }
}

int main()
{
    int A[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int size = sizeof(A) / sizeof(A[0]);

    QuickSort(A, 0, size-1);
    printArray(A, size);
}



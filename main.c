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
#define MAX 100

void swap(int a, int b)
{
  int t = a;
  a = b;
  b = t;
}

/*
int HoarePartition(int A[], int l, int r)
{
    int x = A[r];
    int i = l - 1;
    int j = r + 1;

    while (1) {
        
        do {
            j--;
        } while (A[j] > x);
        
        do {
            i++;
        } while (A[i] < x);
       
        if (i < j) {
           swap(A[i], A[j]);
        }
        else
            return j;
    }
}
 */

int RandomisedLomutoPartition(int A[], int l, int r)
{
    int xIndex = l + rand()%(r - l + 1); //generates a random number as a pivot
    int x;
    int i = l - 1;
    int j;
    x = A[xIndex];
    swap(A[xIndex], A[r]);
    for (j = l; j < r; j++)
    {
        if (A[j] < x)
        {
            i++;
            swap(A[i], A[j]);
        }
 
    }
    swap(A[i+1], A[r]);
    return i + 1;
}

int LomutoPartition(int A[], int l, int r)
{
    int x, i, j;

    x = A[r];
    i = l - 1;

    for (j = l; j <= r - 1; j++) {
        if (A[j] <= x) {
            i++;
            swap(A[i], A[j]);
        }
    }

    swap(A[i+1], A[r]);

    return i + 1;
}


void QuickSort(int A[], int l, int r)
{
    if (r <= l) {
        return;
    }
    
    if (l < r) {
        int m = RandomisedLomutoPartition(A, l, r);
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



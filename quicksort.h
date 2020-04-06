void swap(int a, int b)
{
  int t = a;
  a = b;
  b = t;
}

void printArray(int A[], int n)
{
  int i;
  for (i = 0; i < n; i++) {
    printf("%d ", A[i]);
  }
}

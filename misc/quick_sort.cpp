#ifndef ZX_QUICK_SORT
#define ZX_QUICK_SORT

#include <cstdlib>
#include <ctime>

void quick_sort(int * A, int i, int j);
static void _quick_sort(int * A, int i, int j);
static int partition(int * A, int i, int j, int p);
static inline void swap(int * A, int i, int j);

void quick_sort(int * A, int i, int j) {
  if ( !(i < j) ) {
    return;
  }
  srand(time(0));
  int p = i + rand() % (j-i+1);
  int k = partition(A, i, j, p);
  _quick_sort(A, i, k-1);
  _quick_sort(A, k+1, j);
}
static void _quick_sort(int * A, int i, int j) {
  if ( !(i < j) ) {
    return;
  }
  int p = i + rand() % (j-i+1);
  int k = partition(A, i, j, p);

  _quick_sort(A, i, k-1);
  _quick_sort(A, k+1, j);
}
static int partition(int * A, int i, int j, int p) {
  int l=0, r=0, k=0;
  swap(A, p, j);
  l=i-1;
  r=j;

  for (k=i; l+1<r; ) {
    if (A[k] <= A[j]) {
      l++;
      k++;
    } else {
      r--;
      swap(A, k, r);
    }
  }
  swap(A, r, j);
  return r;
}
static inline void swap(int * A, int i, int j) {
  int tmp = 0;
  tmp = A[i];
  A[i] = A[j];
  A[j] = tmp;
  return;
}

#include <cstdio>
void test1() {
  int A[5] = {5,4,3,2,1};
  quick_sort(A, 0, 4);
  for (int i = 0; i < 5; i++) {
    printf("%d, ", A[i]);
  }
  printf("\n");
  return;
}
void test2()
{
  int A[1] = {2};
  quick_sort(A, 0, 0);
  for (int i = 0; i < 1; i++) {
    printf("%d, ", A[i]);
  }
  printf("\n");
  return;
}
void test3()
{
  int A[3] = {3, 2, 1};
  quick_sort(A, 0, 2);
  for (int i = 0; i < 3; i++) {
    printf("%d, ", A[i]);
  }
  printf("\n");
  return;
}

int main(int argc, const char *argv[])
{
  test1();
  test2();
  test3();
  return 0;
}
#endif

#include <cstdio>
void insertion_sort(int * A, int n)
{
  if (n < 2) {
    return;
  }
  int tmp = 0;
  for (int i = 1; i < n; i++) {
    for (int j = i; j >= 1; j--) {
      if ( A[j] < A[j-1] ) {
        tmp = A[j];
        A[j] = A[j-1];
        A[j-1] = tmp;
      }
    }
  }
}

#define TEST_CODE do {    int N_ELEMENT = sizeof(A) / sizeof(A[0]); \
                          for (int i = 0; i < N_ELEMENT; i++) {     \
                          insertion_sort(A, N_ELEMENT);             \
                          printf("%d ", A[i]);                      \
                          }                                         \
                          printf("\n\n");                           \
                      } while(0);
void test0()
{
  int A[] = {5, 4, 3, 2, 1};
  TEST_CODE;
 }
void test1()
{
  int A[] = {5};
  TEST_CODE;
}
void test2()
{
  int A[] = {5, 2};
  TEST_CODE;
}

int main(int argc, const char *argv[])
{
  test0();
  test1();
  test2();
  return 0;
}

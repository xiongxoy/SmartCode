#include <cstdio>
void bubble_sort(int * A, int n)
{
  if (n < 2) {
    return;
  }
  int tmp = 0;
  for (int i = 0; i < n-1; i++) {
    for (int j = n-1; j > i; j--) {
      if (A[j] < A[j-1]) {
        tmp = A[j-1];
        A[j-1] = A[j];
        A[j] = tmp;
      }
    }
  }
}

#define TEST_CODE do {    int N_ELEMENT = sizeof(A) / sizeof(A[0]); \
                          for (int i = 0; i < N_ELEMENT; i++) {     \
                          bubble_sort(A, N_ELEMENT);             \
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

#include <cstdio>

int *  merge_sort(int A[], int i, int j) {
  if ( i==j ) {
    int * R = new int[1];
    R[0] = A[i];
    return R;
  } else if (i+1 == j) {
    int * R = new int[2];
    if (A[i] <= A[j]) {
      R[0] = A[i];
      R[1] = A[j];
    } else {
      R[0] = A[j];
      R[1] = A[i];
    }
    return R;
  }
  int mid = (i+j) / 2;
  int * R1 = merge_sort(A, i, mid);
  int * R2 = merge_sort(A, mid+1, j);
  int len1 = mid-i+1;
  int len2 = j-mid;

  int * R = new int[j-i+1];
  for (int m = 0, n = 0; m+n < len1+len2; ) {
    if ( m == len1 ) {
      for (; n<len2; n++) {
        R[m+n] = R2[n];
      }
    }
    else if ( n == len2 ) {
      for (; m<len1; m++) {
        R[m+n] = R1[m];
      }
    }
    else {
      if (R1[m] <= R2[n]) {
        R[m+n] = R1[m];
        m++;
      } else {
        R[m+n] = R2[n];
        n++;
      }
    }
  }
  delete [] R1;
  delete [] R2;
  return R;
}
int main(int argc, const char *argv[])
{
  int A[5] = {  1};
  int * R  = merge_sort(A, 0, 0);
  for (int i = 0; i < 1; i++) {
    printf("%d\n", R[i]);
  }
  delete [] R;
  return 0;
}


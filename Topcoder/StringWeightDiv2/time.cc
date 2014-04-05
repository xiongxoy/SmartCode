#include <string>
#include <cassert>
#include <stdlib.h>
#include <iostream>
#include <vector>

class StringWeightDiv2 {
  public:
    int lcountMinimums(int L);
  private:
    /* data */
};

namespace Combinatorics {
#define M 1010
#define N 1010
#define MOD 1000000009
  int arrange( int n, int m ) {
    static long long A[M][N] = {0};
    int i,j;
    long ret = 1;

    if ( A[n][m] > 0) {
      return A[n][m];
    }
    for ( i = 0, j = n; i < m; i++, j-- ) {
      ret = (ret * j) % MOD;
    }
    A[n][m] = ret;

    return ret;
  }

  long long comb( int n, int r ) {
    static long long C[M][N] = {0};
    int i, j;

    if ( C[n][r] > 0 ) {
      return C[n][r];
    }

    for ( i = 0; i <= n; i++ ) {
      for ( j = 0; j <= std::min(i, r); j++ ) {
        if ( C[i][j] > 0 )
          continue;

        if ( 0==j || j==i ) {
          C[i][j] = 1;
        }
        else {
          C[i][j] = C[i-1][j-1] + C[i-1][j];
          C[i][j] %= MOD;
        }
      }
    }

    return C[n][r];
  }
};

int StringWeightDiv2::lcountMinimums(int L) {
  long ret=0;
  int i;

  if ( L<= 26 ) {
    /* smaller than 26, take arrangement */
    ret = Combinatorics::arrange( 26, L );
  }
  else {
    /* large than 26, take arrangement and take choice */
    ret = Combinatorics::arrange( 26, 26 ) % MOD;
    int n = L - 26; // balls
    int k = 26; // bins
    long r = Combinatorics::comb( n+k-1, k-1 ); // n balls in k bins
    ret = ( ret * r ) % MOD;
  }

  return ret;
}

int main(int argc, const char *argv[])
{
  StringWeightDiv2 s;
  int L;

  L = 1;
  assert( 26 == s.countMinimums(L) );

  L = 2;
  assert( 650 == s.countMinimums(L) );

  L = 50;
  assert( 488801539 == s.countMinimums(L) );

  return 0;
}

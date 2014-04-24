/*
ID: xiong.x1
PROG: crypt1
LANG: C++
*/

#include <fstream>

using namespace std;

int crypt1_io();
int main() {
	return crypt1_io();
}

bool checkInSet(int * a, int n, basic_string<int> &d_set) {
  for (int i = 0; i < n; i++) {
    std::basic_string<int>::size_type found = d_set.find(a[i]);
    if (found == std::basic_string<int>::npos)
      return false;
  }
  return true;
}
bool checkValid(int * a, int * b, basic_string<int> &d_set) {
    int result_mid[2][3];
    int result_mid_append[2][4];
    int result_final[4];
    int tmp;
    int carry = 0;
    for (int j = 0; j < 2; j++) {
      for (int i = 2; i >= 0; i--) {
        tmp = a[i] * b[j];
        if (carry) {
          tmp+=carry;
        }
        carry = 0;
        carry = tmp / 10;
        tmp %= 10;
        result_mid[j][i] = tmp;
      }
      if (carry) {
        return false; // carry bit remaining, overflow
      }
    }
    result_mid_append[1][0] = 0;
    result_mid_append[1][1] = result_mid[1][0];
    result_mid_append[1][2] = result_mid[1][1];
    result_mid_append[1][3] = result_mid[1][2];

    result_mid_append[0][0] = result_mid[0][0];
    result_mid_append[0][1] = result_mid[0][1];
    result_mid_append[0][2] = result_mid[0][2];
    result_mid_append[0][3] = 0;

    carry = false;
    for (int i = 3; i >= 0; i--) {
      result_final[i] = result_mid_append[0][i] + result_mid_append[1][i];
      if (carry) {
        result_final[i]+=carry;
        carry = 0;
      }
      carry = result_final[i]/10;
      result_final[i] %= 10;
    }
    if (carry) {
      return false; // overflow
    }

    if( checkInSet(result_final,  4, d_set) &&
        checkInSet(result_mid[0], 3, d_set) &&
        checkInSet(result_mid[1], 3, d_set) )
      return true;
    else
      return false;
}

int m1[9*9*9][3];
int m2[9*9][2];
int crypt1_io() {
	ifstream in;
	ofstream out;
	basic_string<int> d_set;

	in.open("crypt1.in");
	out.open("crypt1.out", ios_base::out|ios_base::trunc);
	{
		// input digit set
		int n=0;
		int v=0;
		in >> n;
    for (int i = 0; i < n; i++) {
			in >> v;
			d_set += v;
    }
	}

	// test the input
  int len = d_set.length();
  int m1_len = len * len * len;
  int m2_len = len * len;
	{
    // populate m1 and m2
        int tmp = 0;
		for(int i=0; i<m1_len; i++) {
      tmp = i;
      m1[i][2] = d_set[tmp % len];          // lower bits
      m1[i][1] = d_set[(tmp / len) % len];
      m1[i][0] = d_set[(tmp / len / len)];  // higher bits
      //printf("%d %d %d.\n", m1[i][0], m1[i][1], m1[i][2]);
    }
    for(int i=0; i<m2_len; i++) {
      tmp = i;
      m2[i][1] = d_set[tmp % len];
      m2[i][0] = d_set[tmp / len];
      //printf("%d %d.\n", m2[i][0], m2[i][1]);
    }
	}
  {
    bool pass = true;
    int count = 0;
    // check each pair of m1 and m2
    for (int i = 0; i < m1_len; i++) {
      for (int j = 0; j < m2_len; j++) {
        if (checkValid(m1[i], m2[j], d_set)) {
          count++;
        }
      }
    }
    out << count << endl;
  }

	return 0;
}


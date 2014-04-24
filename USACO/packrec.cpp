/*
ID: xiong.x1
PROG: packrec
LANG: C++
*/

#include <string>
#include <iostream>
#include <fstream>
#include <cctype>
#include <algorithm>
#include <vector>


using namespace std;

bool checkValid1(const int ** rects, const vector<int> &numbers,
                int *area, int *p, int *q)
{
  int side1 = rects[numbers[0]][0] +
              rects[numbers[1]][0] +
              rects[numbers[2]][0] +
              rects[numbers[3]][0];
  if ( (rects[numbers[0]][0] <= rects[numbers[1]][0]) &&
       (rects[numbers[1]][0] <= rects[numbers[1]][0])
  int side2 = max( max(rects[numbers[0]][1],
                       rects[numbers[1]][1]),
                   max(rects[numbers[2]][1],
                       rects[numbers[3]][1])
                 );
  if (side1 < side2) {
    *p = side1;
    *q = side2;
  } else {
    *p = side2;
    *q = side1;
  }
  *area = side1 * side2;
  return true;
}
bool checkValid2(const int ** rects, const vector<int> &numbers,
                int *area, int *p, int *q)
{
  if ( (rects[numbers[0]][1] + rects[numbers[1]][1] + rects[numbers[2]][1] <= rects[numbers[3]][0])
       && (rects[numbers[0]][0] <= rects[numbers[1]][0])
       && (rects[numbers[1]][0] <= rects[numbers[2]][0]) )
  {
    int side1 = rects[numbers[3]][0];
    int side2 = rects[numbers[2]][0];
    if (side1 <= side2) {
      *p = side1;
      *q = side2;
    } else {
      *p = side2;
      *q = side1;
    }
    *area = side1 * side2;
    return true;
  } else {
    return false;
  }
}
void io_packrec() {
	ifstream in;
	ofstream out;
  int rects[4][2];
  int number_array[4] = {0, 1, 2, 3};
  int area=0, p=0, q=0; // p <= q, area = p*q
  int max_area=-1;
  vector<vector<int>> ans;
  vector<int> numbers(number_array, number_array+4) ;

	in.open("packrec.in");
	out.open("packrec.out",ios_base::out|ios_base::trunc);

  for (int i = 0; i < 4; i++) {
    in >> rects[i][0] >> rects[i][1];
    if ( rects[i][0]>rects[i][1] ) {
      swap(rects[i][0], rects[i][1]);
    }
  }

  do {
    cout << numbers[0] << " "
         << numbers[1] << " "
         << numbers[2] << " "
         << numbers[3] << endl;
    if (checkValid(rects, numbers, &area, &p, &q)) {
      if (area >= max_area) {
        if (area > max_area) {
          ans.clear();
          max_area = area;
        }
        vector<int> tmp(2);
        tmp[0] = p;
        tmp[1] = q;
        ans.push_back(tmp);
      }
    }
  } while (std::next_permutation(numbers.begin(), numbers.end()));
  cout << "After Loop:\n";
  cout << numbers[0] << " "
    << numbers[1] << " "
    << numbers[2] << " "
    << numbers[3] << endl;
}
int main(int argc, const char *argv[])
{
  io_packrec();
  return 0;
}


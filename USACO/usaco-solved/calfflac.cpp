/*
ID: xiong.x1
PROG: calfflac
LANG: C++
*/

#include <string>
#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

#define MAX_LEN 20050
char raw[MAX_LEN];      // raw string with punctuation
char text[MAX_LEN];     // alpha only
int  pos[MAX_LEN];      // position in raw string

int io_calfflac() {
	ifstream in;
	ofstream out;

	in.open("calfflac.in");
	out.open("calfflac.out",ios_base::out|ios_base::trunc);

	// 输入字符串，只读取字母，并将其转成小写
  char tmp = 0;
  int  i=0, p=0; // p is the length of text string
  while(in.get(tmp)) {
    raw[i] = tmp;
    if (isalpha(tmp)) {
      text[p] = tolower(tmp);
      pos[p] = i;
      p++;
      i++;
    } else {
      i++;
    }
  }
  int len = -1;         // max length of palindrome
  int r;                // radius of palindrome
  bool flag = false;    // found different char
  int left=0, right=0;  // mark for result
  // if the palindrome's length is odd
  for (i = 0; i <= p; i++) {
    for(r = 0; i-r>=0 && i+r <= p; r++) {
      if (text[i-r] != text[i+r]) {
        break;
      }
    }
    if (len < (r-1)*2 + 1) {
      len   = (r-1)*2 + 1;
      left  = i-(r-1);
      right = i+(r-1);
    }
  }
  // if the palindrome's length is even
  for (i = 0; i < p; i++) {
    for (r = 0; i-r>=0 && i+r+1 <= p; r++) {
      if (text[i-r] != text[i+r+1]) {
        break;
      }
    }
    if (len < r*2) {
      len   = r*2;
      left  = i-(r-1);
      right = i+(r-1)+1;
    }
  }

  out << len << endl;
  for(i = pos[left]; i <= pos[right]; i++) {
    out << raw[i];
  }
  out << endl;
  return 0;
}
int main(int argc, const char *argv[])
{
  io_calfflac();
  return 0;
}


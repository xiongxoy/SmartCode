/*
ID: xiong.x1
PROG: calfflac
LANG: C++
*/

#include <string>
#include <assert.h>
#include <iostream>
#include <fstream>

using namespace std;

int io_calfflac();

#define MAX_LEN 20010
short dp[2][MAX_LEN];

int hash(string s) {
	int sum=0;
	int len = s.length();
	for (int i=0; i<len ; i++) {
		sum += s[i];
	}
	return sum;
}
int hash_roll(int hval, char pre, char next, int len) {
	return hval-pre+next;
}


int index_s[MAX_LEN];
int io_calfflac() {
	string s, s1, s2;
	ifstream in;
	ofstream out;
	char c;

	in.open("calfflac.in");
	out.open("calfflac.out",ios_base::out|ios_base::trunc);
	// 输入字符串，只读取字母，并将其转成小写
	int s_index=0;
	int sub_index=0;
	while( !in.eof() ) {
		c=in.get();
		s += c;
		if(isalpha(c)) {
			c = tolower(c);
			s1 = s1 + c;
			s2 = c + s2;
			index_s[++sub_index] = s_index;
		}
		s_index++;
	}
	// 找两个字符串的最长公共子串，用DP
	int len1 = s1.length();
	int len2 = s2.length();
	int max_start = 0;
	int max_len = 0;
	//assert(len1 <= MAX_LEN && len2 <= MAX_LEN);
	for(int i=0; i<len1; i++) {
		for(int j=0; j<len2; j++) {
			if( s1[i] == s2[j] ) {
				if( i>0 && j>0 ) {
					dp[i%2][j] = dp[(i-1)%2][(j-1)] + 1;
				}
				else if( i==0 || j==0 ) {
					dp[i%2][j] = 1;
				}
				if( dp[i%2][j] > max_len ) {
					max_len = dp[i%2][j];
					max_start = i - max_len + 1;
				}
			}
			else {
				dp[i%2][j] = 0;
			}
		}
	}

	cout << max_start <<endl;
	cout << max_len <<endl;
	out << max_len <<endl;
	for(int i=index_s[max_start]; i<index_s[max_start+max_len]; i++) {
		out << s[i];
	}
	out << endl;

	return 0;
}

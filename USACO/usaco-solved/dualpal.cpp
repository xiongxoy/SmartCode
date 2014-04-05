/*
ID: xiong.x1
PROG: dualpal
LANG: C++
*/

#include <iostream>
#include <vector>
#include <assert.h>
#include <algorithm>
#include <fstream>
using namespace std;

int dualpal_io();


vector<int> to_base_n(int val, int n) {
	vector<int> tmp;
	assert(val != 0);
	while(val != 0) {
		tmp.insert(tmp.begin(), val % n);
		val = val / n;
	}
	return tmp;
}
bool is_pal(const vector<int> num) {
	int d = num.size();
	for(int i=0; i<= d/2; i++) {
		if( num[i] != num[d-1-i])
			return false;
	}
	return true;
}
string to_base_n_str(vector<int> num) {
	string result = "";
	for(int i=0; i<num.size(); i++) {
		result += (num[i]<10?num[i]+'0':(num[i]-10)+'A');
	}
	return result;
}
string to_base_n_str(int val, int n) {
	vector<int> num;
	num = to_base_n(val, n);
	return to_base_n_str(num);
}


int main() {
	dualpal_io();
    return 0;
}

int dualpal_io() {
	ifstream in;
	ofstream out;
	int n, s, count;
	in.open("dualpal.in");
	out.open("dualpal.out", ios_base::out|ios_base::trunc);

	in >> n;
	in >> s;

	for(int i=s+1; ;i++) {
		for(int j=2, count=0; j<=10; j++) {
			if( is_pal(to_base_n(i, j)) ) {
				if(++count == 2) {
					out << i <<endl;
					if( --n == 0 ) return 0;
					break;
				}
			}
		}
	}
}


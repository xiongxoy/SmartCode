/*
ID: xiong.x1
PROG: palsquare
LANG: C++
*/

#include <iostream>
#include <vector>
#include <assert.h>
#include <algorithm>
#include <fstream>
using namespace std;

int palsquare_io();

int main() {
	palsquare_io();
    return 0;
}


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

int palsquare_io() {
	ifstream in;
	ofstream out;
	int base;
	vector<int> tmp;

	in.open("palsquare.in");
	out.open("palsquare.out", ios_base::out|ios_base::trunc);

	in >> base;
	for(int i=1; i<=300; i++) {
		tmp = to_base_n(i*i, base);
		if(is_pal(tmp))  {
			out << to_base_n_str(i, base) << " ";
			out << to_base_n_str(tmp) <<endl;
		}
	}
	return 0;
}

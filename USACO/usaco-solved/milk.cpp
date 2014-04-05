/*
 ID: xiong.x1
 PROG: milk
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int milk_io();

int main() {
	return milk_io();
}

bool less_pair(const pair<int,int> & m1, const pair<int,int> & m2) {
        return m1.first < m2.first;
}

#define MAX_F 5000

typedef pair<int,int> farmer;
int milk_io() {
	ifstream in;
	ofstream out;
	int n=0, total=0, price=0;
	vector<farmer> farmers;

	in.open("milk.in");
	out.open("milk.out", ios_base::out|ios_base::trunc);

	in  >> total >> n;
	while(n-->0) {
		farmer tmp;
		in >> tmp.first >> tmp.second;
		farmers.push_back(tmp);
	}
	sort(farmers.begin(), farmers.end(), less_pair);
	for(int i=0; i<farmers.size(); i++) {
		if(total-farmers[i].second > 0) {
			total -= farmers[i].second;
			price += farmers[i].first * farmers[i].second;
		}
		else {
			price += total * farmers[i].first;
			break;
		}
	}
	out << price << endl;
	in.close();
	out.close();
	return 0;
}



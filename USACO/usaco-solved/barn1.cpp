/*
ID: xiong.x1
PROG: barn1
LANG: C++
 */

#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int barn1_io();

int main() {
	return barn1_io();
}

typedef pair<int, int> interval;
void print_intervals(const vector<interval> & intervals) {
	for( int i=0; i<intervals.size(); i++) {
		cout << intervals[i].first <<" " <<intervals[i].second <<endl;
	}
}
int barn1_io() {
	vector<interval> a, b;
	ifstream in;
	ofstream out;
	int m, s, c;
	vector<int> stalls;

	in.open("barn1.in");
	out.open("barn1.out", ios_base::out|ios_base::trunc);

	in >> m >> s >> c;
	for(int i=0; i<c; i++) {
		int tmp;
		in >> tmp;
		stalls.push_back(tmp);
	}
	sort(stalls.begin(), stalls.end());
	for( int i=0; i<c; i++) {
		if( a.empty() ) {
			interval tmp;
			tmp.first = stalls[i];
			tmp.second = stalls[i];
			a.push_back(tmp);
		} else {
			interval & tmp = a.back();
			if( tmp.second+1 == stalls[i] ) {
				tmp.second = stalls[i];
			}
			else {
				a.push_back(interval(stalls[i], stalls[i]));
			}
		}
	}

	// print_intervals(a);
	// merge the intervals, shortest gap intervals first
	while( a.size() > m) {
		int gap_min = 99999;
		int i_min = -1;
		for( int i=0; i<a.size()-1; i++) {
			if( a[i+1].first - a[i].second < gap_min ) {
				gap_min = a[i+1].first - a[i].second;
				i_min = i;
			}
		}
		interval tmp;
		tmp.first = a[i_min].first;
		tmp.second = a[i_min+1].second;
		//cout <<"A:"<< a.size() <<endl;
		a.erase(a.begin()+i_min, a.begin()+i_min+2);
		//cout <<"B:"<< a.size() <<endl;
		a.insert(a.begin()+i_min, tmp);
		//cout <<"C:"<< a.size() <<endl;
	}
	//print_intervals(a);
	int sum = 0;
	for( int i=0; i<a.size(); i++) {
		sum += a[i].second - a[i].first + 1;
	}

	out << sum <<endl;
	in.close();
	out.close();
	return 0;
}

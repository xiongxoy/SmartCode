#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Klink{
	int k;
	int link;
};
class Cube{
	vector<pair<Klink,int> > links;
	int in;
	int out;
};
Cube cubes[1000];
int elimination() {
	int c;
	cin >> c;
	for( ; c>0; c--) {

	}
	return 0;
}
int light() {
	int c, n, m, h;
	int count[100001] = { 0 };
	int pos;
	cin >> c;
	for( ; c>0 ; c--) {
		cin >> n >> m >> h;
		for( ; m>0; m--) {
			cin >> pos;
			count[pos] = h;
			for(int i=pos-h, grow=0; i<pos; i++, grow++) {
				if( i >= 0)
					count[i] = std::max(grow, count[i]);
				if( 2*pos - i <= n )
					count[2*pos-i] = std::max(grow, count[2*pos-i]);
			}
		}
		for(int i=1; i<=n; i++) {
			cout << count[i] <<endl;
		}
		for(int i=0; i<100001; i++)
			count[i] = 0;
	}
	return 0;
}

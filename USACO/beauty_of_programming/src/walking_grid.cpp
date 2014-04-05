#include <iostream>

using namespace std;

typedef enum {
	N = 0,
	W,
	E
} direction;
long long sum;
void walk(int n, direction pre) {
	if(n == 0) {
		sum++;
		return;
	}
	if( pre == N ) {
		walk(n-1, N);
		walk(n-1, W);
		walk(n-1, E);
	}
	if( pre == E ) {
		walk(n-1, E);
		walk(n-1, N);
	}
	if( pre == W )
	{
		walk(n-1, W);
		walk(n-1, N);
	}
}
int main() {
	walk(4, N);
	cout <<sum <<endl;
	string s;
	s.c_str();
}

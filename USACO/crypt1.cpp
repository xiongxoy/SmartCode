#include <fstream>

using namespace std;

int crypt1_io();
int main() {
	return crypt1_io();
}

bool test(int m, int digit) {
	return false;
}

#define D1 01
#define D2 010
#define D3 0100
#define D4 01000
#define D5 010000
#define D6 0100000
#define D7 01000000
#define D8 010000000
#define D9 0100000000

short DIGITS;
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
		while( n-->0 ) {
			in >> v;
			d_set += v;
			if( 1 == v)
				DIGITS |= D1;
			else if( 2 == v)
				DIGITS |= D2;
			else if( 2 == v)
				DIGITS |= D2;
			else if( 3 == v)
				DIGITS |= D3;
			else if( 4 == v)
				DIGITS |= D4;
			else if( 5 == v)
				DIGITS |= D5;
			else if( 6 == v)
				DIGITS |= D6;
			else if( 7 == v)
				DIGITS |= D7;
			else if( 8 == v)
				DIGITS |= D8;
			else if( 9 == v)
				DIGITS |= D9;
		}
	}
	// test the input
	{
		int m1, m2;
		for(int i=0; i<d_set.length(); i++) {
			for(int j=0; j<5; j++) {

			}
		}
	}
	return 0;
}

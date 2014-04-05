/*
ID: xiong.x1
PROG: transform
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<vector<char> > chr_mat;

int transform_io();
int transform(const chr_mat & p_src, const chr_mat& p_dst );
template<class T>
bool isEqual(const T & a, const T & b);
template<class T>
T rotate_90(const T & p_src);
template<class T>
T rotate_180(const T & p_src);
template<class T>
T rotate_270(const T & p_src);
template<class T>
T reflection(const T & p_src);
template<class T>
bool combination(const T & p_src, const T & p_dst );
template<class T>
void print_mat( const T & m );

template<class T>
void print_mat( const T & m ) {
	int d = m.size();
	for(int i=0; i<d; i++) {
		for(int j=0; j<d; j++)
			cout << m[i][j] ;
		cout <<std::endl;
	}
}

int main() {
	transform_io();
    return 0;
}


#include <assert.h>
#include <exception>
int transform_io() {
	ifstream in;
	ofstream out;
	int d;
	char c;
	chr_mat src,dst;
	vector<char> tmp;
	string line;

	try{
		in.open("transform.in");
		out.open("transform.out", ios_base::out|ios_base::trunc);
	} catch (exception & e) {
		assert(0);
	}
	in >> d;
	tmp.resize(d);

	/* read src and dst pattern */
	for(int i=0; i<d; i++) {
		tmp.clear();
		for(int j=0; j<d; j++) {
			in >> c;
			tmp.push_back(c);
		}
		src.push_back(tmp);
	}
	for(int i=0; i<d; i++) {
		tmp.clear();
		for(int j=0; j<d; j++) {
			in >> c;
			tmp.push_back(c);
		}
		dst.push_back(tmp);
	}

	/* try to transform */
	out << transform(src, dst) <<endl;
	return 0;
}

/**
   #1: 90 Degree Rotation: The pattern was rotated clockwise 90 degrees.
   #2: 180 Degree Rotation: The pattern was rotated clockwise 180 degrees.
   #3: 270 Degree Rotation: The pattern was rotated clockwise 270 degrees.
   #4: Reflection: The pattern was reflected horizontally (turned into a mirror image of itself by reflecting around a vertical line in the middle of the image).
   #5: Combination: The pattern was reflected horizontally and then subjected to one of the rotations (#1-#3).
   #6: No Change: The original pattern was not changed.
   #7: Invalid Transformation: The new pattern was not obtained by any of the above methods.
 */
int transform(const chr_mat & p_src, const chr_mat& p_dst ) {
	chr_mat tmp(p_src);

	if(isEqual(rotate_90(p_src), p_dst))
		return 1;
	else if(isEqual(rotate_180(p_src), p_dst))
		return 2;
	else if(isEqual(rotate_270(p_src), p_dst))
		return 3;
	else if(isEqual(reflection(p_src), p_dst))
		return 4;
	else if(combination(p_src, p_dst))
		return 5;
	else if(isEqual(p_src, p_dst))
		return 6;
	else
		return 7;
}
template<class T>
bool isEqual(const T & a, const T & b) {
	int d = a.size();
	if( b.size() != d) return false;
	for(int i=0; i<d; i++)
		for(int j=0; j<d; j++)
			if(a[i][j] != b[i][j]) return false;
	return true;
}
template<class T>
T rotate_90(const T & p_src) {
	T tmp(p_src);
	int d = tmp.size();
	for(int i=0; i<d; i++)
		for(int j=0; j<d; j++)
			tmp[j+0][-i+d-1] = p_src[i][j];
	return tmp;
}
template<class T>
T rotate_180(const T & p_src) {
	T tmp(p_src);
	int d = tmp.size();
	for(int i=0; i<d; i++)
		for(int j=0; j<d; j++)
			tmp[-i+d-1][-j+d-1] = p_src[i][j];
	return tmp;
}
template<class T>
T rotate_270(const T & p_src) {
	T tmp(p_src);
	int d = tmp.size();
	for(int i=0; i<d; i++)
		for(int j=0; j<d; j++)
			tmp[-j+d-1][i] = p_src[i][j];
	return tmp;
}
template<class T>
T reflection(const T & p_src) {
	T tmp(p_src);
	int d = tmp.size();
	for(int i=0; i<d; i++)
		if( d-1-i <= i)
			break;
		else
			for(int j=0; j<d; j++) {
				tmp[j][d-1-i] = p_src[j][i];
				tmp[j][i] = p_src[j][d-1-i];
			}
	/*
	cout << "src" <<endl;
	print_mat(p_src);
	cout << "ref" <<endl;
	print_mat(tmp);
	*/
	return tmp;
}
template<class T>
bool combination(const T & p_src, const T & p_dst ) {
	T tmp = reflection(p_src);
	if(isEqual(rotate_90(tmp), p_dst) 	||
	   isEqual(rotate_180(tmp), p_dst) 	||
	   isEqual(rotate_270(tmp), p_dst))
		return true;
	return false;
}


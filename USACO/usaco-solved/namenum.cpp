/*
ID: xiong.x1
PROG: namenum
LANG: C++
*/

#include <iostream>
#include <vector>
#include <assert.h>
#include <algorithm>
#include <fstream>
using namespace std;

int namenum_io();

int main() {
	namenum_io();
    return 0;
}

struct frame {
	string name;
	unsigned int i;
	frame() {};
	frame(string name, unsigned int i) { this->name = name; this->i = i;};
};
bool str_binary(const string & name, const vector<string> & dict) {
	int low = 0;
	int high = dict.size();
	int mid = 0;
	while(low <= high) {
		mid = (low + high) / 2;
		if( dict[mid] == name ) return true;
		if( dict[mid] > name )
			high = mid -1;
		if( dict[mid] < name)
			low = mid + 1;
	}
	return false;
}
void tree_traverse(vector<string> & result, const vector<vector<char> > & tree, unsigned int i, string name, const vector<string> & dict) {
	vector<frame> stack;
	frame node;
	node.name = name;
	node.i = i;

	stack.push_back(node);
	while(!stack.empty()) {
		node = stack.back();
		stack.pop_back();
		if(tree.size() == node.i) {
			if( str_binary(node.name, dict)  )
				result.push_back(node.name);
			continue;
		}
		for(int j=0; j<tree[node.i].size(); j++) {
			stack.push_back(frame(node.name+tree[node.i][tree[node.i].size()-1 - j], node.i+1));
		}
	}

	return;

	/* 递归解 */
	if(tree.size() == i) {
		if( find(dict.begin(), dict.end(), name) != dict.end() )
			result.push_back(name);
		return;
	}
	vector<char> level = tree[i]; // 先广遍历是怎么实现的呢？ //
	for(int j=0; j<level.size(); j++) {
		tree_traverse(result, tree, i+1, name+level[j], dict);
	}
}

vector<vector<char> > get_trans() {
	vector<vector<char> > tmp;
	vector<char> tmp1;
	tmp1.push_back('A'); tmp1.push_back('B'); tmp1.push_back('C');
	tmp.push_back(tmp1); // number 2, stored in tmp[0];

	tmp1.clear();
	tmp1.push_back('D'); tmp1.push_back('E'); tmp1.push_back('F');
	tmp.push_back(tmp1);

	tmp1.clear();
	tmp1.push_back('G'); tmp1.push_back('H'); tmp1.push_back('I');
	tmp.push_back(tmp1);

	tmp1.clear();
	tmp1.push_back('J'); tmp1.push_back('K'); tmp1.push_back('L');
	tmp.push_back(tmp1);

	tmp1.clear();
	tmp1.push_back('M'); tmp1.push_back('N'); tmp1.push_back('O');
	tmp.push_back(tmp1);

	tmp1.clear();
	tmp1.push_back('P'); tmp1.push_back('R'); tmp1.push_back('S');
	tmp.push_back(tmp1);

	tmp1.clear();
	tmp1.push_back('T'); tmp1.push_back('U'); tmp1.push_back('V');
	tmp.push_back(tmp1);

	tmp1.clear();
	tmp1.push_back('W'); tmp1.push_back('X'); tmp1.push_back('Y');
	tmp.push_back(tmp1);

	assert(tmp.size() == 8);

	return tmp;
}

struct out_it {
	ofstream & out_;
	out_it(ofstream & out):out_(out) {
	}
	void operator() (string s) {
		out_ << s;
		out_ << endl;
	}
};
int namenum_io() {
	ifstream in,dict_in;
	ofstream out;
	vector<string> dict;
	vector<char> ch_trans;
	vector<vector<char> > translation;

	in.open("namenum.in");
//	dict_in.open("namenumdict.txt");
	dict_in.open("dict.txt");
	out.open("namenum.out", ios_base::out|ios_base::trunc);
	translation = get_trans();

	string name;
	while(!dict_in.eof()) {
		dict_in >> name;
		dict.push_back(name);
	}
	dict_in.close();

	string number;
	in >> number;
	vector<vector<char> > name_tree;
	for(int i=0; i<number.size(); i++) {
		ch_trans = translation[number[i] - '0' - 2];
		name_tree.push_back(ch_trans);
	}
	vector<string> result;
	tree_traverse(result, name_tree, 0, "", dict);
	if(result.empty())
		out << "NONE" <<endl;
	else
		for_each(result.begin(), result.end(), out_it(out));
	out.close();
	return 0;
}

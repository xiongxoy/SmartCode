/*
ID: xiong.x1
PROG: coin
LANG: C++
*/

#include <iostream>
#include <vector>
#include <assert.h>
#include <algorithm>
#include <fstream>
using namespace std;

#define MAX_T 10
#define MAX_N 20000

int min_coin(const vector<int> & types, const int amount) {
	assert( types.size() <= MAX_T && amount <= MAX_N);

	// 获取1种硬币的时候，1到amount所需要的硬币数
	int table[MAX_T][MAX_N+1];
	for(int i=0; i<types.size(); i++) {
		table[i][0] = 0;
	}
	// 初始化面值为1的硬币
	for(int i=1; i<= amount; i++) {
		table[0][i] = i;
	}
	// 从1种里面，衍生出很多种，动态规划
	for(int t=1; t<types.size(); t++) {
		for(int i=1; i<= amount; i++) {
			int t_num=0; // t类型硬币的数量;
			int min_num=table[t-1][i]; // 最少硬币数量
			int tmp_num;
			while(i - (t_num+1) * types[t] >= 0) {
				t_num++;
				tmp_num = t_num + table[t-1][i - t_num * types[t]];
				if( tmp_num < min_num ) min_num = tmp_num;
			}
			table[t][i] = min_num;
		}
	}

	return table[types.size()-1][amount];
}

int coin_io() {
	vector<int>  coin_types;
	int amount = 87;

	coin_types.push_back(1);
	coin_types.push_back(5);
	coin_types.push_back(8);
	coin_types.push_back(10);
	cout << min_coin(coin_types, amount) <<endl;

	return 0;
}

int main() {
	coin_io();
	return 0;
}

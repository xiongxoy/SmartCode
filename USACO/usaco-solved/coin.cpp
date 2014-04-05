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

	// ��ȡ1��Ӳ�ҵ�ʱ��1��amount����Ҫ��Ӳ����
	int table[MAX_T][MAX_N+1];
	for(int i=0; i<types.size(); i++) {
		table[i][0] = 0;
	}
	// ��ʼ����ֵΪ1��Ӳ��
	for(int i=1; i<= amount; i++) {
		table[0][i] = i;
	}
	// ��1�����棬�������ܶ��֣���̬�滮
	for(int t=1; t<types.size(); t++) {
		for(int i=1; i<= amount; i++) {
			int t_num=0; // t����Ӳ�ҵ�����;
			int min_num=table[t-1][i]; // ����Ӳ������
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

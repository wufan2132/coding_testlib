#pragma once
#include <iostream>
#include "My_str_fun.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <iterator>
using namespace std;

class Solution9_14
{
public:
	Solution9_14();
	~Solution9_14();

	int run_count = 0;


	vector<int> get_input(){ // [1,2,3,4]->vector<num>
		string str;
		vector<int> nums;
		cin >> str;
		str = str.substr(1, str.size() - 2);
		for (string s : My_str_fun::str_spilt(str, { ',' }))
			nums.push_back(stoi(s));
		return nums;
	}

	bool canCross1(vector<int>& stones) {
		//if (*(stones.end() - 1) == 99999999) return 0;
		unordered_map<int, bool> m;
		int ret = step(stones, 0, 0, 1, m);
		cout << "run_count:" << run_count << endl;;
		return ret;
	}

	int step(vector<int>& stone, int pos, int jump, int k, unordered_map<int, bool>& m)
	{

		int key = pos | k << 10 | jump << 15;
		if (m.count(key)) return m[key];
		run_count++;
		int stone_pos = stone[pos] + jump + k;
		//计算出跳之后的位置，看看能不能找到
		for (int i = pos + 1; i < stone.size(); i++)
		{
			if (stone_pos == stone.at(i))
			{
				pos = i;
				k = jump + k;
				break;
			}
			else if (stone.at(i) > stone_pos)
			{
				return m[key] = 0;
			}
		}
		if (stone.back() < stone_pos)
			return m[key] = 0;
		if (pos == stone.size() - 1)
			return 1;

		if (step(stone, pos, 0, k, m)) return m[key] = 1;
		if (step(stone, pos, 1, k, m)) return m[key] = 1;
		if (step(stone, pos, -1, k, m)) return m[key] = 1;
		return 0;
	}





	bool canCross2(vector<int>& stones) {
		unordered_map<int, bool> m;
		bool ret = helper(stones, 0, 0, m);
		cout << "run_count:" << run_count << endl;
		return ret;
	}
	bool helper(vector<int>& stones, int pos, int jump, unordered_map<int, bool>& m) {
		int n = stones.size(), key = pos + jump*100;
		if (pos >= n - 1) return true;
		run_count++;
		for (int i = pos + 1; i < n; ++i) {
			int dist = stones[i] - stones[pos];
			if (dist < jump - 1) continue;
			if (dist > jump + 1) 
				return m[key] = false;
			int new_key = i + dist *100;
			if (m.count(new_key)) 
				continue;
			else
			{
				if (helper(stones, i, dist, m)) return m[key] = true;
			}
		}
		return m[key] = false;

	}
};


//Solution9_14 solution;
//vector<int> nums = solution.get_input();

//clock_t start = clock();
////int ret = solution.canCross1(nums);

//clock_t ends = clock();
////cout << "ret: " << ret << endl;

////cout << "Running Time1 : " << (double)(ends - start) / CLOCKS_PER_SEC << endl;

//start = clock();
//int ret = solution.canCross2(nums);

//ends = clock();
//cout << "ret: " << ret << endl;

//cout << "Running Time2 : " << (double)(ends - start) / CLOCKS_PER_SEC << endl;
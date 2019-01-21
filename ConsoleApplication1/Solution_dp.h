#pragma once
#include<vector>
#include <iostream>
#include<algorithm>
#include<set>
#include<unordered_map>
#include "My_str_fun.h"
using namespace std;
class Solution_dp
{
public:
	Solution_dp();
	~Solution_dp();
	//输入函数
	vector<int> get_input(){ // [1,2,3,4]->vector<num>
		string str;
		vector<int> nums;
		cin >> str;
		str = str.substr(1, str.size() - 2);
		for (string s : My_str_fun::str_spilt(str, { ',' }))
			nums.push_back(stoi(s));
		return nums;
	}


	//给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。
	/************lowB的递归方法*******************/
	int solve(vector<int>& coins, int amount){
		if (coins.size() == 0) return -1;
		sort(coins.begin(), coins.end());
		int pos = coins.size() - 1, coin_count = 0;
		return step(coins, pos, amount, coin_count);
	}

	int step(vector<int>& coins, int pos, int amount, int coin_count){
		int res, min_count = INT_MAX;
		//isfinish?
		if (amount == 0)
			return coin_count;
		if (coin_count > min_count)
			return coin_count;

		//choose_action
		for (int i = pos; i >= 0; i--)
		{
			if (amount >= coins[i])
			{
				res = step(coins, i, amount - coins[i], coin_count + 1);
				//after get a solvtion,is continue?
				if (res != -1)
					min_count = min(res, min_count);
			}
		}
		if (min_count == INT_MAX)
			return -1;
		else
			return min_count;
	}
	/************动态规划*******************/
	int coinChange(vector<int>& coins, int amount) {	
		set<int> operate;
		set<int> temp;
		if (amount == 0) return 0;
		if (coins.size() == 0) return -1;
		sort(coins.begin(), coins.end());
		unordered_map<int, int> value;
		int pos = coins.size() - 1, coin_count = 0;
		for (int c : coins)
		{
			value[c] = 1;
			operate.insert(c);
		}
		while (1)
		{
			temp = operate;
			operate.clear();
			for (int n : temp)
			{
				for (int c : coins)
				{
					if (n + c > amount)
						continue;
					if (!value.count(n + c))
						value[n + c] = value[n] + 1;
					else
						value[n + c] = min(value[n] + 1, value[n + c]);
					operate.insert(n + c);
				}
			}
			if (value.count(amount))
				return value[amount];
			else if (operate.size()==0||*operate.begin() >= amount)
			{
				return -1;
			}
		}
	}

};


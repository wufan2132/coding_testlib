#pragma once
#include<vector>
#include <iostream>
#include<algorithm>
#include "My_str_fun.h"

#include<hash_set>
using namespace std;
class Solution_divide
{
public:
	Solution_divide();
	~Solution_divide();

	vector<int> get_input(){ // [1,2,3,4]->vector<num>
		string str;
		vector<int> nums;
		cin >> str;
		str = str.substr(1, str.size() - 2);
		for (string s : My_str_fun::str_spilt(str, { ',' }))
			nums.push_back(stoi(s));
		return nums;
	}


	//你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
	//给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。
	//利用分治的思想，将一个长断划分
	int rob(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		if (nums.size() == 1) return nums.front();
		vector<int> result(4);
		rob_small(nums, 0, nums.size() - 1, result);
		return result[0];
	}

private:
	//解决size<=3的问题
	//result[0]:两头都可以取
	//result[1]:左边不可取
	//result[2]:右边不可取
	//result[3]:两头都不可以取
	void rob_small(vector<int>& nums, int start, int end, vector<int>& result)
	{
		if (end - start <= 2)
		{
			if (end - start == 2)
			{
	
				result[0] = max(nums[start + 1], nums[start + 0] + nums[start + 2]);
				result[1] = max(nums[start + 1], nums[start + 2]);
				result[2] = max(nums[start + 0], nums[start + 1]);
				result[3] = nums[start + 1];
			}
			else if (end - start == 1)
			{
				result[0] = max(nums[start + 1], nums[start + 0]);
				result[1] = nums[start + 1];
				result[2] = nums[start + 0];
				result[3] = 0;
			}
		}
		else
		{
			vector<int> result1(4);
			vector<int> result2(4);
			int mid = (start + end) / 2;
			rob_small(nums, start, mid, result1);
			rob_small(nums, mid+1, end, result2);
			result[0] = max(result1[0] + result2[1], result1[2] + result2[0]);
			result[1] = max(result1[1] + result2[1], result1[3] + result2[0]);
			result[2] = max(result1[0] + result2[3], result1[2] + result2[2]);
			result[3] = max(result1[1] + result2[3], result1[3] + result2[2]);
		}
	}

};


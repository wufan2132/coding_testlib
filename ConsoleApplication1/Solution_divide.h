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


	//����һ��רҵ��С͵���ƻ�͵���ؽֵķ��ݡ�ÿ�䷿�ڶ�����һ�����ֽ�Ӱ����͵�Ե�Ψһ��Լ���ؾ������ڵķ���װ���໥��ͨ�ķ���ϵͳ������������ڵķ�����ͬһ���ϱ�С͵���룬ϵͳ���Զ�������
	//����һ������ÿ�����ݴ�Ž��ķǸ��������飬�������ڲ���������װ�õ�����£��ܹ�͵�Ե�����߽�
	//���÷��ε�˼�룬��һ�����ϻ���
	int rob(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		if (nums.size() == 1) return nums.front();
		vector<int> result(4);
		rob_small(nums, 0, nums.size() - 1, result);
		return result[0];
	}

private:
	//���size<=3������
	//result[0]:��ͷ������ȡ
	//result[1]:��߲���ȡ
	//result[2]:�ұ߲���ȡ
	//result[3]:��ͷ��������ȡ
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


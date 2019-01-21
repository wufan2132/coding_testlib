#pragma once
#include <iostream>
#include "My_str_fun.h"
#include <vector>
#include <string>
#include <iterator>
//给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。
class Solution9_17
{
public:
	Solution9_17();
	~Solution9_17();
	vector<int> get_input(){ // [1,2,3,4]->vector<num>
		string str;
		vector<int> nums;
		cin >> str;
		str = str.substr(1, str.size() - 2);
		for (string s : My_str_fun::str_spilt(str, { ',' }))
			nums.push_back(stoi(s));
		return nums;
	}
	
	//time 0.169
	vector<vector<int>> threeSum(vector<int>& nums) { 
		vector<vector<int>> nums_array;
		if (nums.size()<3) return nums_array;
		quick_sort(nums);
		//std::sort(nums.begin(), nums.end());
		//思路是固定前两个滑动第三个
		int pos = nums.size() - 1;
		for (int i = 0; i < nums.size() - 2; ++i)
		{
			pos = nums.size() - 1;
			for (int j = i + 1; j < nums.size() - 1; ++j)
			{
				//
				if (pos<j + 1) pos = j + 1;
				if (pos>nums.size() - 1) pos = nums.size() - 1;
				while (pos>j)
				{
					if (-nums[i] - nums[j] < nums[pos])
						pos--;
					else if (-nums[i] - nums[j] > nums[pos])
					{
						pos++;
						break;
					}
					else
					{
						int n_list[3] = { nums[i], nums[j], nums[pos] };
						vector<int> n_temp(n_list, n_list + 3);
						//判断是否重复
						int flag = 0;
						for (vector<int> nums_t : nums_array)
						if (nums_t == n_temp)
						{
							flag = 1;
							break;
						}
						if (flag == 0)
							nums_array.push_back(n_temp);
						break;
					}
				}
			}
		}
		return nums_array;
	}


	void quick_sort(vector<int>& nums, int low = 0, int high = -2){
		if (high == -2) high = nums.size() - 1;
		int begin = low, end = high;
		if (low >= high) return;
		int pivot = nums[low];

		while (low<high)
		{
			while (nums[high] >= pivot&&low<high) high--;
			if (low < high) { nums[low] = nums[high]; low++; }
			while (nums[low] <= pivot&&low<high) low++;
			if (low < high) { nums[high] = nums[low]; high--; }
		}
		nums[low] = pivot;
		if (begin < end)
		{
			quick_sort(nums, begin, low - 1);
			quick_sort(nums, low + 1, end);
		}
	}

};


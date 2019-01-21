#pragma once

#include <iostream>
#include "My_str_fun.h"
#include <vector>
#include <string>
#include <iterator>
using namespace std;

class Solution9_10
{
public:
	Solution9_10();
	~Solution9_10();

	vector<int> get_input(){ // [1,2,3,4]->vector<num>
		string str;
		vector<int> nums;
		cin >> str;
		str = str.substr(1, str.size() - 2);
		for (string s : My_str_fun::str_spilt(str, { ',' }))
			nums.push_back(stoi(s));
		return nums;
	}

	void wiggleSort(vector<int>& nums) {
		if (nums.size() == 0)
			return;
		vector<int> new_nums;
		quick_sort(nums);
		int mid_pos = ceil(nums.size() / 2.0) - 1;
		int begin = mid_pos, end = mid_pos; 
		while (nums[begin] == nums[mid_pos]) begin--;
		while (nums[end] == nums[mid_pos]) end++;
		int down_pos = begin+1;
		int up_pos = end;
		while (new_nums.size() <= nums.size())
		{
			new_nums.push_back(nums[down_pos++]);//Êä³öÖÐ¼ä
			if (new_nums.size() == nums.size()) break;
			new_nums.push_back(nums[up_pos++]);
			if (new_nums.size() == nums.size()) break;
			if (up_pos == nums.size())
			{
				up_pos = down_pos;
				down_pos = 0;
			}
			if (down_pos == end)
			{
				down_pos = 0;
			}

		}
		nums = new_nums;
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

//Solution9_10 solution;
//vector<int> nums = solution.get_input();
//solution.wiggleSort(nums);
//for each (int var in nums)
//{
//	cout << var << " ";
//}


//void wiggleSort(vector<int>& nums) {
//	if (nums.size() == 0)
//		return;
//	vector<int> new_nums;
//	new_nums.push_back(nums[0]);
//	for (int i = 1; i < nums.size(); i++)
//	{
//		if (nums[i] == *new_nums.rbegin())
//		{
//			int pos = new_nums.size() - 2;
//			while ((pos >= 0) && !is_right(new_nums, nums[i], pos))
//			{
//				pos--;
//			}
//			if (pos != -1)
//			{
//				nums.push_back(new_nums[pos]);
//				new_nums[pos] = nums[i];
//			}
//			else
//				nums.push_back(nums[i]);
//			continue;
//		}
//		place(new_nums, nums[i]);
//	}
//	nums = new_nums;
//}
//bool is_right(vector<int>& new_nums, int num, int pos){
//	if (pos % 2 == 1)
//	{
//		if (num > new_nums[pos + 1] && (pos == 0 || num > new_nums[pos - 1]))
//			return 1;
//		else
//			return 0;
//	}
//	else
//	{
//		if (num < new_nums[pos + 1] && (pos == 0 || num > new_nums[pos - 1]))
//			return 1;
//		else
//			return 0;
//	}
//}
//void place(vector<int>& new_nums, int num){
//	if (new_nums.size() % 2 == 1)
//	{
//		if (num > *new_nums.rbegin())
//			new_nums.push_back(num);
//		else
//		{
//			int n = *new_nums.rbegin();
//			new_nums.push_back(n);
//			new_nums[new_nums.size() - 2] = num;
//		}
//	}
//	else
//	{
//		if (num < *new_nums.rbegin())
//			new_nums.push_back(num);
//		else
//		{
//			new_nums.push_back(*new_nums.rbegin());
//			new_nums[new_nums.size() - 2] = num;
//		}
//	}
//}
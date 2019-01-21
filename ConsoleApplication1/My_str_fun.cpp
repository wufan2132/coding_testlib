#include "My_str_fun.h"


My_str_fun::My_str_fun()
{
}


My_str_fun::~My_str_fun()
{
}


vector<string> My_str_fun::str_spilt(string str, vector<char> s_char){
	vector<string> s_out = {""};
	for (char s : str)
	{
		if (is_s_in_char(s, s_char))
		{
			s_out.push_back("");
		}
		else
		{
			s_out.at(s_out.size() - 1).push_back(s);
		}
	}
	return s_out;
}

bool My_str_fun::is_s_in_char(char s, vector<char> s_char){
	for (char s_ : s_char)
	if (s_ == s) return 1;
	return 0;
}

void My_str_fun::quick_sort(vector<int>& nums, int low = 0, int high = -2){
	if (high == -2) high = nums.size() - 1;
	int begin = low, end = high;
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
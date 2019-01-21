#pragma once
class meituan
{
public:
	meituan();
	~meituan();
	bool is4mi(int n){
		int s;
		while (n > 4)
		{
			s = n % 4;
			if (s != 0)
				return 0;
			else
			{
				n = n / 4;
			}
		}
		if (n == 4)
			return 1;
	}

	int getmaxsum(int* nums, int len){
		int maxnum = 0;
		int thismaxnum = 0;
		int n =0;
		int i = 0;
		for (i = 0; i < len; i++)
		{	
				if (n + 1 == nums[i])
				{
					thismaxnum += nums[i];
					n = nums[i];
					if (thismaxnum > maxnum)
						maxnum = thismaxnum;
				}
				else
				{
					thismaxnum = nums[i];
					n = nums[i];
					if (thismaxnum > maxnum)
						maxnum = thismaxnum;
				}
		}
		return maxnum;
	}
};


//int a[] = { 1, 2, 5, 5, 5 };
//meituan m;
//cout << m.getmaxsum(a, 5);
//Solution9_17 solution;
//vector<int> nums = solution.get_input();
//vector<vector<int>> nums_array = solution.threeSum(nums);
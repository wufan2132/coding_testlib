#pragma once
#include<vector>
#include <iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;
class Solution_sort
{
public:
	Solution_sort();
	~Solution_sort();

	//前K个高频元素
	typedef pair<int, int> PAIR;

	static bool cmp_by_value(const PAIR& lhs, const PAIR& rhs) {
		return lhs.second < rhs.second;
	}
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> m;
		vector<int> res;
		for (int n : nums)
		{
			if (!m.count(n))
				m[n] = 1;
			else
				m[n]++;
		}
		vector<PAIR> vec(m.begin(), m.end());
		sort(vec.begin(), vec.end(), cmp_by_value);
		for (int i = 0; i<k; i++)
		{
			res.push_back(vec[i].first);
		}
		return res;
	}
};


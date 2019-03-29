#pragma once
#include<vector>
#include <iostream>
#include<algorithm>
#include <sstream>
#include "My_str_fun.h"
#include<hash_set>
#include<unordered_map>
using namespace std;
class Solution_arrary
{
public:
	Solution_arrary();
	~Solution_arrary();

	vector<int> get_input(){// 1 2 3 4 ->vector<num>
		vector<int> nums;
		string s;
		while(cin >> s)
		nums.push_back(stoi(s));
		return nums;
	}
	//
	vector<int> get_input(char c){ // [1,2,3,4]->vector<num>
		string str;
		vector<int> nums;
		cin >> str;
		str = str.substr(1, str.size() - 2);
		for (string s : My_str_fun::str_spilt(str, { c }))
			nums.push_back(stoi(s));
		return nums;
	}
//数组是否重复
#pragma region containsDuplicate
	bool containsDuplicate(vector<int>& nums) {
		hash_set<int> m;
		for (int i = 0; i<nums.size(); i++)
		{
			if (m.find(nums[i]) == m.end(nums[i]))
				m.insert(nums[i]);
			else
			{
				return 0;
			}
		}
		return 1;
	}
#pragma endregion

//找出只出现一次的数字//用异或可以计算 重复这一类问题  
#pragma region singleNumber
	int singleNumber(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		if (nums[0] != nums[1]) return nums[0];
		if (*nums.cbegin() != *(nums.cbegin()-1)) return nums.back();
		for (int i = 1; i<nums.size()-1; i++)
		{
			if (nums[i] != nums[i - 1] && nums[i] != nums[i + 1])
			{
				return nums[i];
			}
		}
	}
	//用异或可以计算 重复这一类问题  
	int singleNumber_BEST(vector<int>& nums) {
		int r = nums[0];
		for (int i = 1; i < nums.size(); i++){
			r ^= nums[i];
		}
		return r;
	}
#pragma endregion

	//两个数组求交集
#pragma region intersect
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		vector<int> same_array;
		if (nums1.empty() || nums2.empty()) return same_array;
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		int pos1 = 0, pos2 = 0;
		while (pos1<nums1.size() && pos2<nums2.size())
		{
			if (nums1[pos1] == nums2[pos2])
			{
				same_array.push_back(nums1[pos1]);
				pos1++;
				pos2++;
			}
			else if (nums1[pos1]<nums2[pos2])
			{
				pos1++;
			}
			else
			{
				pos2++;
			}
		}
		return same_array;
	}
#pragma endregion

	//加一
#pragma region plusOne
	vector<int> plusOne(vector<int>& digits) {

		for (int i = digits.size() - 1; i >= 0; i--)
		{
			//某一位加一
			if (digits[i] == 9)
			{
					digits[i] = 0;
					if (i == 0)
					{
						digits.insert(digits.begin(), 1);
						break;
					}
			}
			else{
				digits[i]++;
				break;
			}
		}
		return digits;
	}
#pragma endregion

	//求数组中的两数之和
#pragma region twoSum
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> result;
		if (nums.size()<2)  return result;
		vector<int> num_copy = nums;
		sort(nums.begin(), nums.end());

		for (int i = 0; i<nums.size(); i++)
		for (int j = i + 1; j<nums.size(); j++)
		{
			if (nums[i] + nums[j]>target)
				break;
			else if (nums[i] + nums[j] == target)
			{
				int n1 = find(num_copy.begin(), num_copy.end() ,nums[i]) - num_copy.begin();
				int n2 = find(num_copy.begin(), num_copy.end(), nums[j]) - num_copy.begin();
				result.push_back(n1);
				result.push_back(n2);
				return result;
			}
		}
		return result;
	}
#pragma endregion

	//三数之和
#pragma region threeSum
	vector<vector<int>> threeSum(vector<int>& nums){
		vector<vector<int>> nums_array;
		if (nums.size()<3) return nums_array;
		hash_set<long> m;
		//先排序
		std::sort(nums.begin(), nums.end());
		//思路是固定前两个滑动第三个，时间复杂度O（n3）
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
						long n_list[3] = { nums[i], nums[j], nums[pos] };
						vector<int> n_temp(n_list, n_list + 3);
						long hash_num = n_list[0] + (n_list[1] << 16);
						//判断是否重复
						if (!m.count(hash_num))
						{
							nums_array.push_back(n_temp);
							m.insert(hash_num);
						}
						break;
					}
				}
			}
		}
		return nums_array;
	}
#pragma endregion

	//寻找数组中最小的K个值
#pragma region GetLeastNumbers
public:
	vector<int> GetLeastNumbers(vector<int> input, int k){
		vector<int> vec;
		if (input.size() <= k) return input;
		if (k == 0) return vec;
		int start = 0;
		int end = input.size() - 1;
		int index = partern(input, start, end);
		while (index != k - 1){
			if (index < k - 1){
				start = index + 1;
				index = partern(input, start, end);
			}
			else{
				end = index - 1;
				index = partern(input, start, end);
			}
		}
		input.resize(k);
		return input;
	}
private:
	int partern(vector<int>& input, int start, int end){
		if (start == end) return start;
		int index = (start + end) / 2;
		swap(input[index], input[end]);
		int small = start;
		for (index = start; index<end; index++){
			if (input[index]<input[end]){
				if (small != index)
					swap(input[index], input[small]);
				small++;
			}
		}
		swap(input[small], input[end]);
		return small;
	}

	void swap(int& a, int& b){
		int temp = a;
		a = b;
		b = temp;
	}
#pragma endregion

	//复原IP
#pragma region restoreIpAddresses
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string>  sout;
		if (s.size()<4 || s.size()>12) return sout;
		int lost_num = 12 - s.size();
		restoreIpAddresses_core(sout, s, 0, lost_num, 0);
		return sout;
	}
private:
	void restoreIpAddresses_core(vector<string>& sout, string s, int pos, int lost_num, int ipnum){
		if (ipnum == 3){
			if (pos<s.size()&&isvavid(s.substr(pos)))
				sout.push_back(s);
			return;
		}
		string ss;
		string s_copy = s;
		if (lost_num >= 2 && pos + 1<s.size()){
			ss = s.substr(pos, 1);
			if (isvavid(ss)){
				s_copy = s;
				s_copy.insert(s_copy.begin() + pos + 1, '.');
				restoreIpAddresses_core(sout, s_copy, pos + 2, lost_num - 2, ipnum + 1);
			}
		}
		if (lost_num >= 1 && pos + 2<s.size()){
			ss = s.substr(pos, 2);
			if (isvavid(ss)){
				s_copy = s;
				s_copy.insert(s_copy.begin() + pos + 2, '.');
				restoreIpAddresses_core(sout, s_copy, pos + 3, lost_num - 1, ipnum + 1);
			}
		}
		if (lost_num >= 0&&pos+3<s.size()){
			ss = s.substr(pos, 3);
			if (isvavid(ss)){
				s_copy = s;
				s_copy.insert(s_copy.begin() + pos + 3, '.');
				restoreIpAddresses_core(sout, s_copy, pos + 4, lost_num, ipnum + 1);
			}
		}
	}

	bool isvavid(string s){
		if (s.size() == 0)
			return 0;
		if (s.size() == 1)
			return 1;
		if (s.size() == 2){
			if (s[0] != '0')
				return 1;
			return 0;
		}
		if (s.size() == 3)
		{
			if (s[0] == '0')
				return 0;
			int num = atoi(s.c_str());
			if (num <= 255)
				return 1;
		}
		return 0;
	}
#pragma endregion

//输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。例如输入数组{ 3，32，321 }，则打印出这三个数字能排成的最小数字为321323
#pragma region PrintMinNumber
public:
static bool comp(const int& a, const int& b){
		stringstream s1,s2;
		s1 << a << b;
		string str1 = s1.str();

		s2 << b << a;
		string str2 = s2.str();
		return str1<str2;
	}
public:
	string PrintMinNumber(vector<int> numbers) {
		if (numbers.size()>=2)
			sort(numbers.begin(), numbers.end(), &Solution_arrary::comp);
		stringstream stream;
		for (auto n : numbers)
			stream << n;
		return stream.str();
	}

#pragma endregion

#pragma region 数字翻译字符串
public:
	vector<string> num_trans(int num){
		vector<string>  sout;
		if (num < 0) return sout;
		stringstream stream;
		stream << num;
		string numstring = stream.str();

		
		if (numstring.size() == 0) return sout;

		string wordstring;
		num_trans_core(sout, numstring, 0, wordstring);
		return sout;
	}
private:
	void  num_trans_core(vector<string>& sout, string numstring, int pos, string& wordstring){
		if (pos >= numstring.size()){
			sout.push_back(wordstring);
			return;
		}
		string ss;
		string s_copy = wordstring;
		//选一位
		if (pos<numstring.size()){
			ss = numstring.substr(pos, 1);
			int ret = isnumvavid(ss);
			if (ret!=-1){
				s_copy.push_back('a' + ret);
				num_trans_core(sout , numstring, pos + 1, s_copy);
			}
		}
		s_copy = wordstring;
		//选两位
		if (pos+1<numstring.size()){
			ss = numstring.substr(pos, 2);
			int ret = isnumvavid(ss);
			if (ret != -1){
				s_copy.push_back('a' + ret);
				num_trans_core(sout, numstring, pos + 2, s_copy);
			}
		}


	}
	int isnumvavid(string s){
		if (s.size() == 0)
			return -1;
		if (s.size() <= 2)
		{
			int num = atoi(s.c_str());
			if (num <= 25)
				return num;
		}
		return -1;
	}

#pragma endregion

//一个整型数组里除了两个数字之外，其他的数字都出现了偶数次。请写程序找出这两个只出现一次的数字。
#pragma region 只出现一次的数字
	public:
		void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
			int sum = 0;
			for (int n : data)
				sum ^= n;
			int bit = 1;
			while (!(sum&bit))
				bit = bit << 1;
			//devide
			*num1 = 0;
			*num2 = 0;
			for (int n : data){
				if (n&bit)
					*num1 ^= n;
				else
					*num2 ^= n;
			}
		}
#pragma endregion

//一个数组中只包含0,1, 求使得其中0,1个数相等的最大子数组
#pragma region 0,1个数相等的最大子数组
	public:
		vector<int> maxSonVec01(vector<int> vec){
			int len = vec.size();
			vector<int> num(len+1);
			num[0] = 0;
			int zeroCnt = 0, oneCnt = 0;
			for (int i = 0; i < len; i++){
				if (vec[i])
					oneCnt++;
				else
					zeroCnt++;
				num[i + 1] = zeroCnt - oneCnt;
			}
			//
			int maxvalue = -1;
			int maxS = 0, maxE = 0;
			unordered_map<int, int> map;
			for (int i = 0; i < len + 1; i++){
				map.insert(pair<int, int>(num[i], i));
				if (i - map[num[i]]>maxvalue){
					maxvalue = i - map[num[i]];
					maxS = map[num[i]];
					maxE = i;
				}
			}
			return vector<int>(vec.begin() + maxS, vec.begin() + maxE);
		}
#pragma endregion
};
//
//Solution_arrary solution;
//
//vector<int> nums1 = solution.get_input();
//vector<int> nums2 = solution.get_input();
//vector<int> nums = solution.intersect(nums1, nums2);
//for (int n : nums)
//cout << n << " ";
//cout << endl;
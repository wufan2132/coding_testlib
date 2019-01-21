#pragma once
#include<vector>
#include <iostream>
#include "My_str_fun.h"
#include<unordered_set>
using namespace std;
class Solution_string
{
public:
	Solution_string();
	~Solution_string();
public:
	int myAtoi(string str) {
		int flag = 0, flag2 = 0;
		int num = 0, count = 0;
		for (char s : str)
		{
			if (flag == 0 && s == '-')
			{
				flag2 = 1;
				flag = 1;
			}
			else if (flag == 0 && s == '+')
				flag = 1;
			else if (s == ' ')
			{
				if (flag == 0)
					continue;
				else
					break;
			}

			else if (s >= '0'&&s <= '9')
			{
				if (flag == 0) flag = 1;
				int n = s - '0';
				if (num > 214748364 || (num == 214748364 && n > 7))
					return INT_MAX;
				if (num < -214748364 || (num == -214748364 && n>8))
					return INT_MIN;
				if (flag2 == 0)
					num = num * 10 + n;
				else
				{
					num = num * 10 - n;
				}
			}
			else
			{
				break;
			}
		}
		return num;
	}

public:
	int reverse(int x) {
		int fuhao = 0;
		int num = 0;
		//if (x<0)
		//{
		//	fuhao = 1;
		//}
		while (x != 0)
		{
			int n = x % 10;
			if (num > 214748364 || (num == 214748364 && n > 7))
				return 0;
			if (num < -214748364 || (num == -214748364 && n<-8))
				return 0;
			//if (fuhao == 0)
				num = num * 10 + n;
			//else
			//	num = num * 10 - n;
			x = (x - n) / 10;
		}
		return num;
	}
public:
	//给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。
	int firstUniqChar(string s) {
		if (s == "") return -1;
		if (s.size() == 1) return 0;
		unordered_set<char> m;
		int i, j;
		for (i = 0; i<s.size(); i++)
		{
			if (m.count(s[i])) continue;
			for (j = i + 1; j<s.size(); j++)
			{
				if (s[i] == s[j])
				{
					m.insert(s[i]);
					break;
				}
			}
			if (j == s.size())
				return i;
		}
		return -1;
	}
public:
	//报数
	string countAndSay(int n) {
		if (n == 1) return "1";
		string out_str = "1";
		for (int i = 0; i<n - 1; i++)
		{
			out_str = convert(out_str);
		}
		return out_str;
	}
private:
	string convert(string str) {
		if (str == "") return "";
		string out_str = "";
		int count = 0;
		for (int i = 0;; i++)
		{
			if (i == str.size())
			{
				out_str += (char)(count + '0');
				out_str += str[i - 1];
				break;
			}
			else if(i == 0)
				count++;
			else if(str[i] != str[i - 1])
			{
				out_str += (char)(count + '0');
				out_str += str[i - 1];
				count = 1;
			}
			else{
				count++;
			}
		}
		return out_str;
	}
public:
	//表示数值的字符串
	bool isNumeric(string str){
		bool ret;
		string::iterator it = str.begin();
		ret = isInt(str, it);
		if (it != str.end()&&*it == '.'){
			it++;
			ret = isUInt(str, it) || ret;
		}
		if (it != str.end() && (*it == 'e' || *it == 'E')){
			it++;
			ret = isInt(str, it)&&ret;
		}
		return ret&&it == str.end();
	}
private:
	bool isUInt(string& str,string::iterator& it){
		string::iterator begin = it;
		while (it != str.end() && *it >= '0'&&*it <= '9')
		{
			it++;
		}
		return it > begin;
	}
	bool isInt(string& str, string::iterator& it){
		if (*it == '-' || *it == '+')
			it++;
			return isUInt(str, it);
	}
};



#pragma once
#include <vector>
#include <string>
using namespace std;

class My_str_fun
{
public:
	My_str_fun();
	~My_str_fun();
 static vector<string> str_spilt(string, vector<char>);
 static bool is_s_in_char(char s, vector<char> s_char);
 void My_str_fun::quick_sort(vector<int>& nums, int low, int high);
};


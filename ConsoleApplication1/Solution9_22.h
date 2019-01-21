#pragma once

#include <iostream>
#include "My_str_fun.h"
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>


class Solution9_22
{
public:
	Solution9_22();
	~Solution9_22();
	//���ǣ�
	//��
	const char letter = '?', word = '*';
	bool isMatch(string s, string p) {
		return step(s, p);
	}

	// ֻ������*��
	bool step(string s, string p){
		int pos_S = 0, pos_P = 0;
		////���ٷ���
		//if (!quick_confirm(s, p))
		//	return 0;
		////

		for (; pos_P < p.size(); pos_P++, pos_S++)
		{
			//
			if (p.at(pos_P) == word)// �����*��ȥ��*�ţ����еݹ�
			{
				while (p.at(pos_P) == word || p.at(pos_P) == letter)//��֤֮���p��һ��Ӧ������ĸ
				{
					if (p.at(pos_P) == letter)
						pos_S++;
					pos_P++;
					if (pos_P >= p.size()) //���*�������һ������ô�����Ѿ�ƥ�����
						if (pos_S <= s.size())
							return 1;
						else
						{
							return 0;
						}
				}
				while (pos_S<s.size())//һֱ�ҵ���p��ͷ��ͬ
				{
					if (p.at(pos_P) == s.at(pos_S) && step(s.substr(pos_S+1), p.substr(pos_P+1))) //warning!!!!!!!!!!!!
						return 1;
					else
						pos_S++;
				}
				return 0;
			}
			else if (p.at(pos_P) == letter || (pos_S<s.size() &&p.at(pos_P) == s.at(pos_S)));
			else
			{
				return 0;
			}
		}
		if (pos_S == s.size() && pos_P == p.size())
			return 1;
		else
		{
			return 0;
		}
	}

	bool quick_confirm(string s, string p){
		int count = 0;
		for each (char var in p)
		{
			if (var == word)
				count++;
		}
		if (p.size() - count > s.size())
			return 0;
		else
			return 1;

	}

};


//for (vector<int> nums : nums_array)
//{
//	for (int n : nums)
//		cout << n << ",";
//	cout << endl;
//}

//Solution9_22 solution;
//string str1 = "abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb", str2 = "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb";
//cout << str1 << "   " << str2 << endl;
//cout << solution.isMatch(str1, str2) << endl;

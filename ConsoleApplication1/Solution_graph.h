#pragma once
#include<iostream>
#include<vector>
#include<queue>
#include"My_str_fun.h"
using namespace std;

class Solution_graph
{
public:
	Solution_graph();
	~Solution_graph();


	/**********���������������***********/
	//������һ��m�к�n�еķ���һ�������˴�����0, 0�ĸ��ӿ�ʼ�ƶ���
	//ÿһ��ֻ�������ң��ϣ����ĸ������ƶ�һ�񣬵��ǲ��ܽ�������������������λ֮�ʹ���k�ĸ��ӡ�
	//���磬��kΪ18ʱ���������ܹ����뷽��35, 37������Ϊ3 + 5 + 3 + 7 = 18��
	//���ǣ������ܽ��뷽��35, 38������Ϊ3 + 5 + 3 + 8 = 19��
	//���ʸû������ܹ��ﵽ���ٸ����ӣ�
	int movingCount(int threshold, int rows, int cols)
	{
		int count = 0;
		if (rows<1 || cols<1 || threshold<0) return 0;

		vector<bool> istest(rows*cols, 0);
		//
		queue<pair<int, int>> que;
	
		que.push(pair<int, int>(0,0));
		istest[0] = 1;
		count++;

		while (que.size()){
			int len = que.size();
			for (int i = 0; i<len; i++){
				//
				pair<int, int> pos = que.front();
				que.pop();
				//
				pair<int, int> tpos;
				tpos = pos;
				tpos.first--;
				if (tpos.first >= 0&& istest[ cols*tpos.first +tpos.second] == 0&& canreach(threshold, tpos.first, tpos.second)){
					count++;
					que.push(tpos);
				}
				if (tpos.first >= 0)
				istest[ cols*tpos.first +tpos.second] = 1;

				tpos = pos;
				tpos.second--;
				if (tpos.second >= 0
					&& istest[ cols*tpos.first +tpos.second] == 0
					&& canreach(threshold, tpos.first, tpos.second)){
					count++;
					que.push(tpos);
				}
				if (tpos.second >= 0)
				istest[ cols*tpos.first +tpos.second] = 1;

				tpos = pos;
				tpos.first++;
				if (tpos.first<rows
					&&istest[ cols*tpos.first +tpos.second] == 0
					&& canreach(threshold, tpos.first, tpos.second)){
					count++;
					que.push(tpos);
				}
				if (tpos.first<rows)
				istest[ cols*tpos.first +tpos.second] = 1;

				tpos = pos;
				tpos.second++;
				if (tpos.second<cols
					&&istest[ cols*tpos.first +tpos.second] == 0
					&& canreach(threshold, tpos.first, tpos.second)){
					count++;
					que.push(tpos);
				}
				if (tpos.second<cols)
				istest[ cols*tpos.first +tpos.second] = 1;
			}
		}
		return count;
	}

	bool canreach(int threshold, int row, int col){
		int sum = 0;
		while (row>0){
			sum += row % 10;
			row /= 10;
		}
		while (col>0){
			sum += col % 10;
			col /= 10;
		}
		if (sum>threshold)
			return 0;
		else
			return 1;
	}

};


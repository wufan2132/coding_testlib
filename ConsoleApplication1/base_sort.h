#pragma once
#include <vector>
#include "base_tree.h"
using namespace std;
class base_sort
{
public:
	base_sort();
	~base_sort();


//八种排序方式
//稳定性：指的是相同value值的元素经过排序后，是否保持原来的顺序
//1.冒泡排序
//2.简单选择
//3.插入排序

//4.归并排序
//5.快速排序
	static void quick_sort(vector<int>& vec, int start=0, int end = -10){
		if (end == -10) end = vec.size() - 1;
		if (vec.size() < 0) return;
		if (start<end)
		{
			int mid = quick_sort_core(vec, start, end);
			quick_sort(vec, start, mid - 1);
			quick_sort(vec, mid+1, end);
		}
	}
	static int quick_sort_core(vector<int>& vec, int start, int end){
		int mid = vec[start];
		while (start < end){
			while (vec[end] >= mid&&start < end) end--;
			if (start < end) {
				vec[start] = vec[end];
				start++;
			}
			while (vec[start] <= mid&&start < end) start++;
			if (start < end) {
				vec[end] = vec[start];
				end--;
			}
		}
		vec[start] = mid;
		return start;
	}

	//6.希尔排序
	//7.（二叉排序树）
	static TreeNode* binary_sort(vector<int>& vec){
		if (!vec.size()) return NULL;
		TreeNode* root = NULL;
		TreeNode** p;
		for (int n : vec){
			if (root == NULL){
				root = new TreeNode(n);
				continue;
			}
			p = &root;
			while (*p){
				if (n > (*p)->val)
					p = &((*p)->right);
				else
					p = &((*p)->left);
			}
			*p = new TreeNode(n);
		}
		return root;
	}

	//堆排序
	static void heap_sort(vector<int>& vec){
		if (vec.empty()) return; 
		int len = vec.size();
		//初建堆，从最后一个非叶子节点开始筛选
		for (int i = len / 2 - 1; i >= 0; i--){
			heap_adjust(vec, i, len - 1);
		}
		//小顶堆，倒序输出
		for (int i = len - 1; i > 0; i--){
			swap(vec[0], vec[i]);
			heap_adjust(vec, 0, i-1);
		}
	}

	static void heap_adjust(vector<int>& vec, int s, int e){
		int top = vec[s];
		for (int j = 2 * s + 1; j <= e; j = 2 * j + 1){
			if (top > vec[j] && top > vec[j + 1])// 改这个<
				break;
			if (j < e && vec[j] < vec[j + 1])// 改这个<
				j++;
			vec[s] = vec[j];
			s = j;
		}
		vec[s] = top;
	}
	//8.基数排序（关键字）
	



};
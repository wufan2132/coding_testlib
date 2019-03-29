#pragma once
#include<stdio.h>
#include<iostream>
#include<stack>
#include<unordered_set>
#include<algorithm>
#include "base_tree.h"
#include "My_str_fun.h"


class Solution_tree
{
public:
	Solution_tree();
	~Solution_tree();
	vector<int> get_input(){ // [1,2,3,4]->vector<num>
		string str;
		vector<int> nums;
		cin >> str;
		str = str.substr(1, str.size() - 2);
		for (string s : My_str_fun::str_spilt(str, { ',' }))
			nums.push_back(stoi(s));
		return nums;
	}

	//��������������
	int maxDepth(TreeNode* root) {
		if (root == NULL)
			return 0;
		return 1 + max(maxDepth(root->left), maxDepth(root->right));
	}

	//��֤�Ƿ�Ϊ����������
	//��������������жϱ��������Ƿ����
	bool Solution_tree::isValidBST(TreeNode* root) {
		if (root == NULL) return 1;
		int flag = 0;
		int min = INT_MIN;
		return isBST(root, min, flag);
	}
	bool Solution_tree::isBST(TreeNode* root, int& n, int& flag)
	{
		if (root->left != NULL)
		{
			if (!isBST(root->left, n, flag))
				return 0;
		}
		if (flag == 0 || root->val>n)
		{
			n = root->val;
			flag = 1;
		}
		else
			return 0;
		if (root->right != NULL)
		{
			if (!isBST(root->right, n, flag))
				return 0;
		}
		return 1;
	}

	//�ֱ�ʹ�����������������ջ����ʹ�����������������ջ
	bool Solution_tree::isSymmetric(TreeNode* root){
		stack<int> sta;
		mid_push(root->left, sta);
		return mid_pop(root->left, sta);
	}

	void Solution_tree::mid_push(TreeNode* root, stack<int> sta)
	{
		if (root->left != NULL)
		{
			mid_push(root->left, sta);
		}
		sta.push(root->val);
		if (root->right != NULL)
		{
			mid_push(root->right, sta);
		}
	}
	bool Solution_tree::mid_pop(TreeNode* root, stack<int> sta)
	{
		if (root->left != NULL)
		{
			if (!mid_pop(root->left, sta))
				return 0;
		}
		if (root->val == sta.top())
			sta.pop();
		else
			return 0;
		if (root->right != NULL)
		{
			if (!mid_pop(root->right, sta))
				return 0;
		}
	}

	/*����������ת��Ϊ����������
		��һ�������������е��������飬ת��Ϊһ�ø߶�ƽ�������������
		�����У�һ���߶�ƽ���������ָһ��������ÿ���ڵ� ���������������ĸ߶Ȳ�ľ���ֵ������ 1��*/

	TreeNode* Solution_tree::sortedArrayToBST(vector<int>& nums) {
		
		if (nums.size() == 0) return NULL;
		
		return buildTree(nums, -1, nums.size());
	}
	TreeNode* Solution_tree::buildTree(vector<int>& nums, int start, int end)
	{
		int pos = (start + end) / 2;
		TreeNode* root = new TreeNode(nums[pos]);
		if (pos - start>1)
			root->left = buildTree(nums, start, pos);
		if (end - pos>1)
			root->right = buildTree(nums, pos, end);
		return root;
	}

	//�õ����㷨������������������ ������� ������
	//˼·1�����ҷֿ������Ȱ�������push��ջ��ȡ����ڵ��ʱ��������ڵ��ٰ������������֧push��ȥ
	vector<int> inorderTraversal(TreeNode* root) {
		stack<TreeNode*> sta;
		vector<int> vec;
		TreeNode* pos;
		push_left(root, sta);
		while (!sta.empty())
		{
			pos = sta.top();
			vec.push_back(pos->val);
			sta.pop();
			if (pos->right != NULL)
				push_left(pos->right, sta);
		}
		return vec;
	}
	void push_left(TreeNode* pos, stack<TreeNode*>& sta)
	{
		while (pos != NULL)
		{
			sta.push(pos);
			pos = pos->left;
		}
	}

	//��ǰ��������������й��������
	//ע��:
	//����Լ�������û���ظ���Ԫ��
	//ǰ�򣺸�����
	//���������
	//˼·��������������������������������
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		TreeNode* root = buildTree(preorder, 0, preorder.size(), inorder, 0, inorder.size());
		return root;
	}
	TreeNode* buildTree(vector<int>& preorder, int begin1, int end1, vector<int>& inorder, int begin2, int end2) {
		TreeNode* root = new TreeNode(preorder[begin1]);
		int root_pos2;
		for (int i = begin2; i < end2; i++)
		{
			if (inorder[i] == preorder[begin1])
			{
				root_pos2 = i;
				break;
			}
		}
		int left_size = root_pos2 - begin2;
		int right_size = end2 - root_pos2-1;
		if (left_size>0)
			root->left = buildTree(preorder, begin1 + 1, begin1 + 1 + left_size, inorder, begin2, root_pos2);
		else
			root->left = NULL;
		if (right_size>0)
			root->right = buildTree(preorder, begin1 + 1 + left_size, end1, inorder, root_pos2 + 1, end2);
		else
			root->right = NULL;
		return root;
	}

	//�������ö�����A��B���ж�B�ǲ���A���ӽṹ����ps������Լ��������������һ�������ӽṹ��
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if (!pRoot1) return 0;
		if (!pRoot2) return 0;

		if (issame(pRoot1, pRoot2))
			return 1;
		else if (HasSubtree(pRoot1->left, pRoot2))
			return 1;
		else if (HasSubtree(pRoot1->right, pRoot2))
			return 1;
		else
			return 0;

	}


	bool issame(TreeNode* pRootA, TreeNode* pRootB){
		if (pRootB == NULL)
			return 1;
		if (pRootA != NULL&&pRootA->val == pRootB->val){
			int ret = 1;
			ret &= issame(pRootA->left, pRootB->left);
			ret &= issame(pRootA->right, pRootB->right);
			return ret;
		}
		else
			return 0;

	}
	
};


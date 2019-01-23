#pragma once
#include<iostream>
#include<queue>
#include"My_str_fun.h"
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class base_tree
{
public:
	base_tree();
	~base_tree();
	vector<string> get_input(){ // [1,null,2,null,3,4]->vector<string>
		string str;
		cin >> str;
		str = str.substr(1, str.size() - 2);
		return My_str_fun::str_spilt(str, { ',' });
	}


	/*�����ַ������鹹��һ��������(��α���)*/
	TreeNode* make_tree(const vector<string>& str_vec)
	{
		queue<TreeNode**> que;
		TreeNode* root = NULL;
		TreeNode* node;
		for (string str : str_vec){
			//�����µĽڵ�
			if (str != "null")
				node = new TreeNode(atoi(str.c_str()));
			else
				node = NULL;
			//���ýڵ��Ҹ��ڵ�
			if (que.size()){
				*que.front() = node;
				que.pop();
			}
			//�ǿսڵ����������push������
			if (node != NULL){
				que.push(&node->left);
				que.push(&node->right);
			}

			if (root == NULL){
				if (node != NULL)
					root = node;
				else
					return NULL;
			}
		}
		return root;
	}

	/*����ʱ��Ҫ���Ĳ���*/
	void TraversaCore(TreeNode* root){
		if (root)
			cout << root->val << ",";
		else
			cout << "null,";
	}
	/*���������������(�� �� ��)*/
	void FirstTraversa(TreeNode* root){
		if (!root) return;
		FirstTraversa(root->left);
		TraversaCore(root);
		FirstTraversa(root->right);
	}
	/*���������������(�� �� ��)*/
	void MidTraversa(TreeNode* root){
		if (!root) return;
		TraversaCore(root);
		MidTraversa(root->left);
		MidTraversa(root->right);
	}
	/*�������ĺ������(�� �� ��)*/
	void BehindTraversa(TreeNode* root){
		if (!root) return;
		MidTraversa(root->left);
		MidTraversa(root->right);
		TraversaCore(root);
	}
	/*�������Ĳ�α���*/
	void ArrTraversa(TreeNode* root){
		if (!root) return;
		queue<TreeNode*> que;
		TreeNode* node;
		que.push(root);
		while (!que.empty()){
			int len = que.size();
			for (int i = 0; i < len; i++){
				node = que.front();
				TraversaCore(node);
				que.pop();
				if (node){
					//if (node->left)
						que.push(node->left);
					//if (node->right)
						que.push(node->right);
				}
			}
		}
	}
	/***********************************************/
};


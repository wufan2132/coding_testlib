#pragma once
#include<stdio.h>
#include<iostream>
#include<stack>
#include<algorithm>
#include "My_str_fun.h"
#include "base_listnode.h"
#include<unordered_set>
using namespace std;


class Solution_listnode
{
public:
	Solution_listnode();
	~Solution_listnode();
	static vector<int> get_input(){ // [1,2,3,4]->vector<num>
		string str;
		vector<int> nums;
		cin >> str;
		str = str.substr(1, str.size() - 2);
		for (string s : My_str_fun::str_spilt(str, { ',' }))
			nums.push_back(stoi(s));
		return nums;
	}

	static ListNode* vector_to_node(vector<int> nums)
	{
		ListNode* head = NULL;
		ListNode* pos = NULL;
		for (int n : nums)
		{
			if (head == NULL)
			{
				head = new ListNode(n);
				pos = head;
			}
			else
			{
				pos->next = new ListNode(n);
				pos = pos->next;
			}
		}
		return head;
	}
	static void printf(ListNode* head)
	{
		while (head != NULL)
		{
			cout << head->val<<" ";
			head = head->next;
		}
		cout << endl;
	}

	//删除链表的倒数第N个节点
	//双指针思路
	ListNode* Solution_listnode::removeNthFromEnd(ListNode* head, int n) {
		if (n == 0) return nullptr;
		ListNode* pos1 = head;
		ListNode* pos2 = head;
		ListNode* pre = NULL;

		for (int i = 0; i < n; i++)
		{
			if (pos2 == NULL)
				return head;
			pos2 = pos2->next;
		}
		while (pos2 != NULL)
		{
			pre = pos1;
			pos1 = pos1->next;
			pos2 = pos2->next;
		}
		if (pre == NULL)
		{
			pre = head->next;
			delete head;
			return pre;
		}
		else{
			pos2 = pre->next;
			pre->next = pre->next->next;
			delete pos2;
			return head;
		}
	}

	//反转链表
	//设置一个前置指针，逐个翻转
	ListNode* Solution_listnode::reverseList(ListNode* head) {
		ListNode* pos = head;
		ListNode* pre = NULL;
		ListNode* newlist = NULL;
		while (pos != NULL)
		{
			newlist = pos;
			pos = pos->next;
			newlist->next = pre;
			pre = newlist;
		}
		return newlist;
	}

	//合并两个有序链表
	//将第二个链表插入到第一个链表中
	ListNode* Solution_listnode::mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == NULL) return l2;
		if (l2 == NULL) return l1;
		ListNode* pos1 = l1;
		ListNode* pos2 = l2;
		ListNode* new_list = l1;
		ListNode* temp = NULL;
		if (l1->val > l2->val)
		{
			pos1 = l2;
			pos2 = l1;
			new_list = l2;
		}
		while (pos2 != NULL)
		{
			if (pos1->next == NULL)
			{
				pos1->next = pos2;
				return new_list;
			}
			if (pos1->next->val > pos2->val)
			{
				temp = pos2;
				pos2 = pos2->next;
				temp->next = pos1->next;
				pos1->next = temp;
			}
			else
				pos1 = pos1->next;
		}
		return new_list;
	}

	//判断是否是回文链表
	//用栈实现
	bool isPalindrome(ListNode* head) {
		stack<int> list_S;
		int len = 0;
		ListNode* pos = head;
		while (pos != NULL)
		{
			len++;
			pos = pos->next;
		}
		pos = head;
		//进栈
		while (list_S.size()<len / 2)
		{
			list_S.push(pos->val);
			pos = pos->next;
		}
		if (len % 2 == 1)
			pos = pos->next;
		//出栈
		while (!list_S.empty())
		{
			if (list_S.top() != pos->val)
				return false;
			else
			{
				list_S.pop();
				pos = pos->next;
			}
		}
		return true;
	}

	//判断是否是环形链表
	//用栈实现
	bool hasCycle(ListNode *head) {
		unordered_set<ListNode *> set;
		while (head != NULL)
		{
			if (set.count(head))
				return 1;
			else
				set.insert(head);
			head = head->next;
		}
		return 0;
	}

	//奇偶链表
	ListNode* oddEvenList(ListNode* head) {
		ListNode* pos = head;
		ListNode* pos1 = head;
		ListNode* pos2 = head->next;
		if (head == NULL) return head;
		ListNode* jiNode = pos;
		if (pos->next == NULL) return head;
		pos = pos->next;
		ListNode* ouNode = pos;
		if (pos->next == NULL) return head;
		pos = pos->next;
		pos1 = jiNode;
		pos2 = ouNode;
		while (pos != NULL)
		{
			if (pos == NULL)
				break;
			pos1->next = pos;
			pos1 = pos1->next;
			pos = pos->next;
			if (pos == NULL)
				break;
			pos2->next = pos;
			pos2 = pos2->next;
			pos = pos->next;
		}
		pos1->next = ouNode;
		return head;
	}

};


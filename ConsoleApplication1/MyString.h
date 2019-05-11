#pragma once
#include <iostream>
using namespace std;
class MyString
{
public:
	MyString(){
	};

	MyString(const char* str){
		len = strlen(str);
		if (len == 0){
			return;
		}
		head = new char[len];
		for (int i = 0; i < len; i++){
			head[i] = *(str++);
		}
	};

	MyString(const MyString& str){
		if (str.size() == 0){
			return;
		}
		head = new char[str.size()];
		for (int i = 0; i < str.size(); i++){
			head[i] = str.head[i];
		}
		len = str.size();
	};

	MyString& operator = (const MyString& str){
		delete[] head;
		if (str.size() == 0){
			head = NULL;
			return  *this;
		}
		head = new char[str.size()];
		for (int i = 0; i < str.size(); i++){
			head[i] = str.head[i];
		}
		len = str.size();
		return *this;
	};

	unsigned size() const{
		return len;
	}

	void printf(){
		for (int i = 0; i < len; i++){
			cout << head[i];
		}
		cout << endl;
	};

	~MyString(){
		if (head != NULL){
			delete[] head;
			head = NULL;
		}
	};
private:
	unsigned len = 0;
	char* head = NULL;
};


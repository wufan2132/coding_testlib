#include"Solution9_10.h"
#include"Solution9_14.h"
#include"Solution9_17.h"
#include"Solution9_22.h"
#include"Solution_arrary.h"
#include"Solution_string.h"
#include"Solution_tree.h"
#include"Solution_listnode.h"
#include"Solution_dp.h"
#include"Solution_graph.h"
#include"base_tree.h"
#include"base_graph.h"
#include"base_sort.h"
#include"misc.h"
#include"meituan.h"
#include"My_str_fun.h"
#include"Design_pattren.h"
#include"MyString.h"
#include <time.h>
#include <vector>
#include <queue>
#include <functional> //优先队列
using namespace std;


//给定一个数字，如果这个数字可以开根号得到一个整数，则开根号
//不然就减一
int GetTimes(int n, int c){
	if (n == 1) return c;
	int m = 2;
	while (m*m<n){
		m++;
	}
	if (m == 2)
		return c + GetTimes(m - 1, n - (m - 1)*(m - 1) );
	else
		return c + GetTimes(m - 1, n - (m - 1)*(m - 1)+1);
}

//手写数字
int HandWriteTimes(int n){
	stack<int> write_num;
	while (n){
		write_num.push(n % 10);
		n /= 10;
	}
	int t_count = 0;
	//
	int k;
	while (!write_num.empty()){
		k = write_num.top();
		write_num.pop();
	}
}
int main(){
	cout << GetTimes(11, 0);

	return 0;
}








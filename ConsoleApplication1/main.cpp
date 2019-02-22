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
#include"misc.h"
#include"meituan.h"
#include"My_str_fun.h"
#include <time.h>
#include <vector>
#include <queue>
#include <functional> //优先队列
using namespace std;





int main(){
	priority_queue<int, vector<int>, greater<int>	> que;
	string str;
	while (cin >> str){
		if (str == "p"){
			cout << que.top() << endl;
			que.pop();
		}
		else
			que.push(stoi(str));
	}
	system("pause");
}








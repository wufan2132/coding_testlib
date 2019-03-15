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
#include"Design_pattren.h"
#include <time.h>
#include <vector>
#include <queue>
#include <functional> //优先队列
using namespace std;





int main(){
	Solution_graph solve;
	char* matrix = "ABCESFCSADEE";
	int rows = 3, cols = 4;
	char* str = "ABCCED";
	int ret = solve.hasPath(matrix, rows, cols, str);
	return 0;
	
}








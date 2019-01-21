#include"Solution9_10.h"
#include"Solution9_14.h"
#include"Solution9_17.h"
#include"Solution9_22.h"
#include"Solution_arrary.h"
#include"Solution_string.h"
#include"Solution_tree.h"
#include"Solution_listnode.h"
#include"Solution_dp.h"
#include"misc.h"
#include"meituan.h"
#include"My_str_fun.h"
#include <time.h>
#include <vector>
using namespace std;





int main(){
	//Solution_listnode solve;
	//vector<int> nums = solve.get_input();
	//ListNode* head = solve.vector_to_node(nums);
	//solve.printf(head);
	////cout <<result<< endl;

	//clock_t start = clock();


	//clock_t ends = clock();
	//cout << "Running Time1 : " << (double)(ends - start) / CLOCKS_PER_SEC << endl;
	Solution_arrary solve;
	vector<int> nums = solve.get_input();
	int num1, num2;
	solve.FindNumsAppearOnce(nums, &num1, &num2);

	cout << num1 <<","<< num2 << endl;


	system("pause");
}








#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_set>
#include <set>
#include <queue>
#include <functional> //优先队列
using namespace std;
/*
6 10
a110000011
0021111110
11101000A0
1001100111
100B000101
11030001b1
*/
class base_graph
{
public:
	base_graph();
	~base_graph();
};

/***********************/
//图的邻接矩阵表示
typedef int valtype;



class nodes{//链表节点
public:
	int id;
	valtype val;
	nodes* next;
	nodes(int x, valtype y) : id(x), val(y), next(NULL) {}
	bool operator<(const nodes& n) const{
		return val < n.val;
	}
	bool operator>(const nodes& n) const{
		return val > n.val;
	}
};

class vertex{//顶点
public:
	int id;
	string name;
	valtype val;
	nodes* next;//可到达的顶点
	vertex(int x, valtype y) : id(x), val(y), next(NULL) {}
	bool operator<(const vertex& n) const{
		return val < n.val;
	}
	bool operator>(const vertex& n) const{
		return val > n.val;
	}
	//
private:
	bool isVisit = 0;
};

/*
1 5
5 6
1 2 1
1 3 3
1 5 15
2 4 5
3 4 2
4 5 8
graph Graph;
int start, end;
cin >> start >> end;
Graph.Getgraph();

vector<int> minPath;
Graph.findmin(Graph, start, end, minPath);
Graph.printMin(start, end, minPath);
*/
class graph{
public:
	graph()
	{};
	int n_nodes;
	int n_roads;
	vector<vertex> vertexSet;
private:
	
	vertex& getVex(int id){
		return vertexSet[id-1];
	}
public:
//algorithm
	/**********************生成图****************************/
	void Getgraph(){
		cin >> n_nodes >> n_roads;
		//生成顶点
		for (int i = 0; i < n_nodes; i++){
			vertexSet.emplace_back(i + 1, INT_MAX);
		}
		vector<nodes*> pGraph(n_nodes);
		//生成邻接矩阵
		int ns, ne, nr;
		for (int i = 0; i < n_roads; i++){
			cin >> ns >> ne >> nr;
			if (pGraph[ns - 1] == NULL){
				getVex(ns).next = new nodes(ne, nr);
				pGraph[ns - 1] = getVex(ns).next;
			}
			else
			{
				pGraph[ns - 1]->next = new nodes(ne, nr);
				pGraph[ns - 1] = pGraph[ns - 1]->next;
			}
		}
	}
	void Getgraph(vector<vector<int> >graph_msg){
		n_nodes = graph_msg[0][0];
		n_roads = graph_msg[0][1];
		//生成顶点
		for (int i = 0; i < n_nodes; i++){
			vertexSet.emplace_back(i + 1, INT_MAX);
		}
		vector<nodes*> pGraph(n_nodes);
		//生成邻接矩阵
		int ns, ne, nr;
		for (int i = 0; i < n_roads; i++){
			ns = graph_msg[i + 1][0];
			ne = graph_msg[i + 1][1];
			nr = graph_msg[i + 1][2];
			if (pGraph[ns - 1] == NULL){
				getVex(ns).next = new nodes(ne, nr);
				pGraph[ns - 1] = getVex(ns).next;
			}
			else
			{
				pGraph[ns - 1]->next = new nodes(ne, nr);
				pGraph[ns - 1] = pGraph[ns - 1]->next;
			}
		}
	}
	
	/*********************最短路径dijkstra**************************/
	int findmin(graph& Graph, int start, int end, vector<int>& minPath = vector<int>()){
		
		//vector<valtype> minCost;//生成权值比较表
		//set<int> openSet;//openset表示当前可以访问到的节点 closeset表示已经确定的节点
		priority_queue<vertex*, vector<vertex*>, greater<vertex*>> openSet;
		unordered_set<int> closeSet;
		openSet.push(&getVex(start));

		int this_node = start;
		//init
		//vector<valtype> minCost(n_nodes, INT_MAX);//生成权值比较表
		minPath.resize(n_nodes, 0); // 记录最短路径

		getVex(start).val = 0; //起点到起点cost给0
		vertexSet[start - 1].val = 0;
		while (!openSet.empty()){
			//在起点可以到达的节点中 找到最小的，没有被确定的节点
			int min_r = INT_MAX, min_id;
			min_r = openSet.top()->val;
			min_id = openSet.top()->id;
	
			openSet.pop();//最小的被确定，从待定openset排除
			closeSet.insert(min_id);//最小的被确定，放入closeset
			if (min_id == end)
				return min_r;
			//确定一个最小的后，看看从这个最小的节点中转能不能有更好的结果
			nodes* pNode = Graph.getVex(min_id).next;
			while (pNode != NULL){
				if (!closeSet.count(pNode->id))//如果是已经确定的顶点就没有必要更新了
				if (min_r + pNode->val < getVex(pNode->id).val){
					getVex(pNode->id).val = min_r + pNode->val;
						openSet.push(&getVex(pNode->id));
						//逆序保存
						minPath[pNode->id - 1] = min_id;
					}
					pNode = pNode->next;
			}
		}
	}
	//打印最短路径
	int printMin(int start, int end ,vector<int>& minPath){
		int id = end;
		stack<int> sta;
		while (true)
		{
			sta.push(id);
			if (id == start)
				break;
			id = minPath[id - 1];
		}
		while (!sta.empty()){
			cout << sta.top();
			sta.pop();
			if (sta.empty())
				cout << endl;
			else
				cout << "->";
		}
		return 0;
	}
	/*************************************************************/
};




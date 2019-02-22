#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <set>
using namespace std;


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
};

class vertex{//顶点
public:
	int id;
	string name;
	valtype val;
	nodes* next;//可到达的顶点
	vertex(int x, valtype y) : id(x), val(y), next(NULL) {}
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
	graph(){};
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
	/*********************最短路径dijkstra**************************/
	int findmin(graph Graph, int start, int end, vector<int>& minPath = vector<int>()){
		set<int> openSet, closeSet;//openset表示当前可以访问到的节点 closeset表示已经确定的节点
		openSet.insert(start);
		int this_node = start;
		//init
		vector<valtype> minCost(n_nodes, INT_MAX);//生成权值比较表
		minPath.resize(n_nodes, 0); // 记录最短路径
		
		minCost[start - 1] = 0; //起点到起点cost给0

		while (!openSet.empty()){
			//在起点可以到达的节点中 找到最小的，没有被确定的节点
			int min_r = INT_MAX, min_id;
			for (int id : openSet){
				if (minCost[id-1]< min_r){
					min_r = minCost[id - 1];
					min_id = id;
				}
			}
			openSet.erase(min_id);//最小的被确定，从待定openset排除
			closeSet.insert(min_id);//最小的被确定，放入closeset
			if (min_id == end)
				return min_r;
			//确定一个最小的后，看看从这个最小的节点中转能不能有更好的结果
			nodes* pNode = Graph.getVex(min_id).next;
			while (pNode != NULL){
				if (!closeSet.count(pNode->id))//如果是已经确定的顶点就没有必要更新了
					if (min_r + pNode->val < minCost[pNode->id - 1]){
						minCost[pNode->id - 1] = min_r + pNode->val;
						openSet.insert(pNode->id);
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


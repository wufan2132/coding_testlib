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
//ͼ���ڽӾ����ʾ
typedef int valtype;

class nodes{//����ڵ�
public:
	int id;
	valtype val;
	nodes* next;
	nodes(int x, valtype y) : id(x), val(y), next(NULL) {}
};

class vertex{//����
public:
	int id;
	string name;
	valtype val;
	nodes* next;//�ɵ���Ķ���
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
	/**********************����ͼ****************************/
	void Getgraph(){
		cin >> n_nodes >> n_roads;
		//���ɶ���
		for (int i = 0; i < n_nodes; i++){
			vertexSet.emplace_back(i + 1, INT_MAX);
		}
		vector<nodes*> pGraph(n_nodes);
		//�����ڽӾ���
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
	/*********************���·��dijkstra**************************/
	int findmin(graph Graph, int start, int end, vector<int>& minPath = vector<int>()){
		set<int> openSet, closeSet;//openset��ʾ��ǰ���Է��ʵ��Ľڵ� closeset��ʾ�Ѿ�ȷ���Ľڵ�
		openSet.insert(start);
		int this_node = start;
		//init
		vector<valtype> minCost(n_nodes, INT_MAX);//����Ȩֵ�Ƚϱ�
		minPath.resize(n_nodes, 0); // ��¼���·��
		
		minCost[start - 1] = 0; //��㵽���cost��0

		while (!openSet.empty()){
			//�������Ե���Ľڵ��� �ҵ���С�ģ�û�б�ȷ���Ľڵ�
			int min_r = INT_MAX, min_id;
			for (int id : openSet){
				if (minCost[id-1]< min_r){
					min_r = minCost[id - 1];
					min_id = id;
				}
			}
			openSet.erase(min_id);//��С�ı�ȷ�����Ӵ���openset�ų�
			closeSet.insert(min_id);//��С�ı�ȷ��������closeset
			if (min_id == end)
				return min_r;
			//ȷ��һ����С�ĺ󣬿����������С�Ľڵ���ת�ܲ����и��õĽ��
			nodes* pNode = Graph.getVex(min_id).next;
			while (pNode != NULL){
				if (!closeSet.count(pNode->id))//������Ѿ�ȷ���Ķ����û�б�Ҫ������
					if (min_r + pNode->val < minCost[pNode->id - 1]){
						minCost[pNode->id - 1] = min_r + pNode->val;
						openSet.insert(pNode->id);
						//���򱣴�
						minPath[pNode->id - 1] = min_id;
					}
					pNode = pNode->next;
			}
		}
	}
	//��ӡ���·��
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


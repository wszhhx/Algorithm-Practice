/*
题目描述：所谓的供应链就是指一张涵盖零售商、经销商、供应商的一张网络，每个成员都参与在将产品由工厂流入顾客手中的过程中。
         从一个源供应商开始，供应链上的每个成员从提供者手里用价格P购买商品，然后以高于P百分之r的价格售给下家。只有零售商是面向顾客的
		 假设供应链上除了源供应商外的每个成员都只面向一个供应商且供应链中没有任何环路。
		 现在给你一个供应链，你需要计算出所有零售商售出所有商品的总额。

输入描述：每次输入包含一个用例，对于每个用例，第一行包括三个正整数：N(<=10^5),N是供应链上所有成员的个数（所有成员的ID从0到N-1编号，根供应商的ID为0）
         P为根供应商给出的价格，r为每次倒卖倒买时价格的涨幅（如买入价格为p则转手价格为p*(1+r)）。
		 接下来跟着N行，每行以如下格式描述了经销商或零售商的信息：Ki ID[1] ID[2] ... ID[Ki]
		 第i行中，Ki指从ID为i的经销商手中进货的零售商和经销商的总数，接下来的ID就是表明有哪些经销商和零售商。
		 Kj为0代表第j个成员为零售商（直接面对顾客，无下家了），然后产品总数会在Kj之后给出.所有数据之间隔着空格

输出描述：对每个用例，在一行内输出所有零售商的总销售额，精确到小数点后一位，我们保证这个数值不会超过10^10

（本人初学者，菜鸟，不会用太高端的算法，只能用易于理解的遍历来解决了。。。。。）
思路：设源供应商为根结点，旗下所有下家结尾其子孙，因为每个经销商或零售商都只面向一个上家且没有环路（题目描述）所以可以用树(图)来解决这个问题
      1.根据输入建立图，并让根结点附带一个单位商品价值，并把根结点及其商品数记录在MAP中
	  2.利用广度优先遍历，把每个结点的单位商品价值设为其前一个结点价值乘以（1+r）。
	  3.遍历MAP，把对应结点单价乘以库存并累加起来得出答案。
PS：其实就是按图思路来计算，不过一定要考虑清楚使用什么存储方式来存储这个数据结构，在此我先试试用邻接表方式（绝壁稀疏图）。。。。试试就试试。。。	  
*/

#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<queue>
#include<vector>
#include<map>
#define MAXSIZE 100000
using namespace std;

map<int, int> Store;
double P, r;

typedef struct arcnode{
	int AdjVertex;
	struct arcnode* nextArc;
}*ArcNode;

typedef struct {
	double Price;
	struct arcnode* firstArc;
}Vertex;

typedef struct graph {
	Vertex vertex[MAXSIZE];
	int V_num;
	int A_num;
}AdjList,*GRAPH;

int FirstAdjNode(GRAPH G, int v) {
	if (G->vertex[v].firstArc == NULL)
		return -1;
	else
		return G->vertex[v].firstArc->AdjVertex;
}

int NextAdjNode(GRAPH G, int v, int w) {
	if (G->vertex[v].firstArc == NULL)
		return -1;
	ArcNode arc;
	for (arc = G->vertex[v].firstArc;arc!=NULL && arc->AdjVertex != w; arc = arc->nextArc);
	if (arc->nextArc == NULL || arc == NULL)
		return -1;
	else
		return arc->nextArc->AdjVertex;
}

double BFS(GRAPH G) {
	queue<int> Q;
	vector<int> Visited(G->V_num, false);
	double price = 0;
	int v, w;
	v = 0;
	Q.push(v);
	Visited[v] = true;
	while (!Q.empty()) {
		v = Q.front();
		Q.pop();
		w = FirstAdjNode(G, v);
		while (w != -1) {
			if (!Visited[w]) {
				G->vertex[w].Price = G->vertex[v].Price * (1 + r);
				Visited[w] = true;
				Q.push(w);
			}
			w = NextAdjNode(G, v, w);
		}
	}
	for (map<int, int>::iterator its = Store.begin(); its != Store.end(); ++its) {
		price += G->vertex[its->first].Price * its->second;
	}
	return price;
}

GRAPH GenerateG(){
	int vnum;
	int anum;
	int cnum;
	int ID;

	ArcNode Arc = NULL;
	GRAPH G = (AdjList*)malloc(sizeof(AdjList));
	cin >> vnum >> P >> r;
	G->A_num = 0;
	G->V_num = vnum;
	r /= 100;
	for (int i = 0; i < vnum; ++i) {
		G->vertex[i].Price = P;
		G->vertex[i].firstArc = NULL;
	}
	for (int i = 0; i < vnum; ++i) {    //开始读取供应链信息
		cin >> cnum;
		if (cnum == 0) {                //若该节点为零售商，无下家
			cin >> ID;
			Store[i] = ID;              //则记录销售商品总数
		}
		for (int j = 0; j < cnum; ++j) {                //记录各下家
			cin >> ID;
			Arc = (arcnode*)malloc(sizeof(arcnode));
			Arc->AdjVertex = ID;
			//if (G->vertex[i].firstArc == NULL)
			//	Arc->nextArc == NULL;
			//else
				Arc->nextArc = G->vertex[i].firstArc;
			G->vertex[i].firstArc = Arc;
		}
	}
	return G;
}

int main() {
	GRAPH G = GenerateG();
	cout << fixed << setprecision(1) << BFS(G) << endl;
	system("pause");
	return 0;
}

/*
��Ŀ��������ν�Ĺ�Ӧ������ָһ�ź��������̡������̡���Ӧ�̵�һ�����磬ÿ����Ա�������ڽ���Ʒ�ɹ�������˿����еĹ����С�
         ��һ��Դ��Ӧ�̿�ʼ����Ӧ���ϵ�ÿ����Ա���ṩ�������ü۸�P������Ʒ��Ȼ���Ը���P�ٷ�֮r�ļ۸��۸��¼ҡ�ֻ��������������˿͵�
		 ���蹩Ӧ���ϳ���Դ��Ӧ�����ÿ����Ա��ֻ����һ����Ӧ���ҹ�Ӧ����û���κλ�·��
		 ���ڸ���һ����Ӧ��������Ҫ����������������۳�������Ʒ���ܶ

����������ÿ���������һ������������ÿ����������һ�а���������������N(<=10^5),N�ǹ�Ӧ�������г�Ա�ĸ��������г�Ա��ID��0��N-1��ţ�����Ӧ�̵�IDΪ0��
         PΪ����Ӧ�̸����ļ۸�rΪÿ�ε�������ʱ�۸���Ƿ���������۸�Ϊp��ת�ּ۸�Ϊp*(1+r)����
		 ����������N�У�ÿ�������¸�ʽ�����˾����̻������̵���Ϣ��Ki ID[1] ID[2] ... ID[Ki]
		 ��i���У�Kiָ��IDΪi�ľ��������н����������̺;����̵���������������ID���Ǳ�������Щ�����̺������̡�
		 KjΪ0�����j����ԱΪ�����̣�ֱ����Թ˿ͣ����¼��ˣ���Ȼ���Ʒ��������Kj֮�����.��������֮����ſո�

�����������ÿ����������һ����������������̵������۶��ȷ��С�����һλ�����Ǳ�֤�����ֵ���ᳬ��10^10

�����˳�ѧ�ߣ����񣬲�����̫�߶˵��㷨��ֻ�����������ı���������ˡ�����������
˼·����Դ��Ӧ��Ϊ����㣬���������¼ҽ�β�������Ϊÿ�������̻������̶�ֻ����һ���ϼ���û�л�·����Ŀ���������Կ�������(ͼ)������������
      1.�������뽨��ͼ�����ø���㸽��һ����λ��Ʒ��ֵ�����Ѹ���㼰����Ʒ����¼��MAP��
	  2.���ù�����ȱ�������ÿ�����ĵ�λ��Ʒ��ֵ��Ϊ��ǰһ������ֵ���ԣ�1+r����
	  3.����MAP���Ѷ�Ӧ��㵥�۳��Կ�沢�ۼ������ó��𰸡�
PS����ʵ���ǰ�ͼ˼·�����㣬����һ��Ҫ�������ʹ��ʲô�洢��ʽ���洢������ݽṹ���ڴ������������ڽӱ�ʽ������ϡ��ͼ�������������Ծ����ԡ�����	  
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
	for (int i = 0; i < vnum; ++i) {    //��ʼ��ȡ��Ӧ����Ϣ
		cin >> cnum;
		if (cnum == 0) {                //���ýڵ�Ϊ�����̣����¼�
			cin >> ID;
			Store[i] = ID;              //���¼������Ʒ����
		}
		for (int j = 0; j < cnum; ++j) {                //��¼���¼�
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

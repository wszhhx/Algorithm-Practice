//There is a public bike service in Hangzhou City which provides great convenience to the tourists from all over the world.  
//One may rent a bike at any station and return it to any other stations in the city.
//The Public Bike Management Center (PBMC) keeps monitoring the real-time capacity of all the stations.  
//A station is said to be in perfect condition if it is exactly half-full.  If a station is full or empty, 
//PBMC will collect or send bikes to adjust the condition of that station to perfect.  And more, all the stations on the way will 
//be adjusted as well. 
//When a problem station is reported, PBMC will always choose the shortest path to reach that station.  
//If there are more than one shortest path, the one that requires the least number of bikes sent from PBMC will be chosen.
//��������
//Each input file contains one test case.  For each case, the first line contains 4 numbers: Cmax (<= 100), always an even number,
// is the maximum capacity of each station; N (<= 500), the total number of stations; Sp, the index of the problem station (the stations 
//are numbered from 1 to N, and PBMC is represented by the vertex 0); and M, the number of roads.  The second line contains N non-negative
// numbers Ci (i=1,...N) where each  Ci is the current number of bikes at Si respectively.  Then M lines follow, each contains 3 numbers: 
//Si, Sj, and Tij which describe the time Tij taken to move betwen stations Si and Sj.  All the numbers in a line are separated by a space
//����һ��ͼ������0��������վPBMC��Cmax����ÿ��վ�����ɵ������������������Cmax/2��ʱ������õģ���Ҳ�Ǵ����������ĺ��ģ���N����
//վ���������N<=500��Sp������վ�Ķ������M��·��������������
//�����ǵ�һ����Ҫ���������
//�ڶ���Ҫ����N����C1,C2....CN��Ci����վSi�ĳ���
//�ٽ�������M���У�ÿ����3�������ֱ���Si,Sj,Tij����ʶ��������iվ��jվ��·��ȨֵΪTij,����һ��ͼ�ͽ��������

//˼·�����ҳ������ɻ�վ������0����Ŀ��վ������Sp�������·����������Щ·����ѡ����Ҫ��վ�������ٵ�·�����Ǵ��ػ�վ���ٵĳ���·����
//����;����ÿ��վ���Ȩֵ�����������һ�����Ȩ�⣬�鿴��󵽴��յ�վ����Ҫ��վ�ɳ���������վ�ɳ������������֣�Ȼ��ѡ�����ֵ��С��
//��Ϊ����·�������ϡ� 

//����˼·����Ϊ�������·�����ܱ�ֻ֤��һ��������Ҫ���޸ĺ��Froid�㷨����װ�ж�ά�����vector����������  

//���Ҫ����һ���������һ��������Ҫ��վ�ɳ��������������Ҫ���������Ϊ0�����ڶ�������·������0->2->3��,����������Ҫ��վ���յĳ���
//          (�������Ҫ��ǲ�������Ϊ0) 
#include<iostream>
#include<vector>
#include<cstdlib>
#define MAX 500
#define INFINITE 1e8
int Cmax;
using namespace std;
typedef struct Matrix{
	int M[MAX][MAX];
}Mrx;
//=================================================================
class Graph{
public:
	void Crt_G();
	Mrx edges;
	int Vertex[MAX];
	int Vnum;
	int Enum;
};


void Graph::Crt_G(){
	for(int i = 0; i<Vnum; i++)
		for(int j = 0; j<Vnum; j++)
			edges.M[i][j] = INFINITE;
	for(int i = 1; i<Vnum; i++)
		cin>>Vertex[i];
	int v1,v2,T;
	for(int i = 0; i<Enum; i++){
		cin>>v1>>v2>>T;
		edges.M[v1][v2] = edges.M[v2][v1] = T;
	}
	for(int i = 0; i<Vnum; i++)
		edges.M[i][i] = 0;
}
//=================================================================
void Process(Graph &G,int aim_station);
void Froid(Graph &G,int D[][MAX], vector< vector<int> > &P); 
bool SelectPath(Graph &G,vector< vector<int> > &P, int i ,int j, int k);
int GetWeight(Graph &G,int j,int i,vector< vector<int> > &P);
//=================================================================
int main(){
	Graph G;
	int aim_station;
	cin>>Cmax;
	cin>>G.Vnum;
	G.Vnum++;
	cin>>aim_station;
	cin>>G.Enum;
	G.Crt_G();
	Process(G,aim_station);
	return 0;
	
}
//=================================================================
int GetWeight(Graph &G,int j,int i,vector< vector<int> > &P){
	int index = P[i][j];
	int weight = 0;
	while(index != j){
		weight += (Cmax/2 - G.Vertex[index]);
		index = P[index][j];
	}
	weight += (Cmax/2 - G.Vertex[j]);
	return weight;
}

bool SelectPath(Graph &G,vector< vector<int> > &P, int i ,int j, int k){
	vector< vector<int> > _P(P);
	_P[i][j] = k;
	int Weight1,Weight2;
	Weight1 = GetWeight(G,j,i,_P);
	Weight2 = GetWeight(G,j,i,P);
	return (abs(Weight1) <= abs(Weight2) ? true : false) ;
}

void Froid(Graph &G,int D[][MAX], vector< vector<int> > &P){
	for(int k = 0; k < G.Vnum ; k++)
		for(int i = 0; i<G.Vnum; i++)
			for(int j = 0; j<G.Vnum; j++){
				if(D[i][k] + D[k][j] < D[i][j]){
					D[i][j] = D[i][k] + D[k][j];
					P[i][j] = k;
				}
				else if(D[i][k] + D[k][j] == D[i][j] && k!=i && k!=j && SelectPath(G,P,i,j,k)){
						P[i][j] = k;
				}
			}
}

void Process(Graph &G,int aim_station){
	int weight = 0;
	int D[MAX][MAX];
	vector<int> Path;
	vector< vector<int> > P;
	P.assign(G.Vnum,vector<int> (G.Vnum,-1));
	for(int i = 0; i < G.Vnum; i++){
		for(int j = 0; j< G.Vnum; j++){
			D[i][j] = G.edges.M[i][j];
			P[i][j] = j;
		}
	}
	Froid(G,D,P);
	weight = GetWeight(G,aim_station,0,P);
	if(weight < 0)
		cout<<0<<' '<<"0->";
	else
		cout<<weight<<' '<<"0->";
	for(int i = P[0][aim_station];i!=aim_station; i = P[i][aim_station])
		cout<<i<<"->";
	cout<<aim_station<<' ';
	if(weight >0)
		cout<<0<<endl;
	else
		cout<<-weight<<endl;
		
}
//Process���𴴽�Froid�㷨��Ҫ��D���飬P�����Ǽ�¼���дӻ�վ��aim_stationվ�����·���ģ�Ȼ����Process�д���Froid������ 
//Ȼ�����P�����ó���ѵ�һ�׷����������
//����Ϊ�����Ż��Ĵ���
#include<iostream>  
#include<vector>  
#include<queue>  
#include<stack>  
using namespace std;  
  
#define INF 0x6FFFFFFF  
int Cmax, n, Sp, m;  
typedef struct Edge  //�߽ṹ 
{  
    int v, dis;      //v������һ�˵Ķ���			dis������������Ȩֵ 
    Edge(int _v, int _dis):v(_v),dis(_dis){}  
}Edge;  
  
typedef struct Node  //����ṹ 
{  
    int c, dis;  //c������ѳ�����Cmax/2    				dis����ö����Ȩֵ��ӵ�еĳ���������
}Node;  
vector<vector<Edge>> edge;          //������ά��������edge[i][].v������i������v�ı�
vector<Node> city;                  //������Ϊ������������ʵ������ʹ����ͼ���ڽӱ�������ʽ���� 
vector<vector<int>> allPath;  
vector<bool> visited;  
  
vector<int> bestPath;  
int minSend = INF;  
int minCollect = INF;  
vector<int> possiblePath;  
void FindBestPath(int u)  
{  
    possiblePath.push_back(u);  
    if(u == 0)  
    {//find the end  
        int send = 0;  
        int collect = 0;  
        for(int i = possiblePath.size()-1; i >= 0; --i)  
        {  
            int t = possiblePath[i];  
            if(city[t].c > Cmax/2)  
                collect += city[t].c - Cmax/2;  
            else if(city[t].c < Cmax/2)  
            {  
                collect -= (Cmax/2-city[t].c);  
                if(collect < 0) send -=collect, collect=0;  
            }  
        }  
        if(send < minSend) minSend=send, minCollect=collect, bestPath=possiblePath;  
        else if(send == minSend && collect < minCollect) minCollect=collect, bestPath=possiblePath;  
        return;  
    }  
    for(int i = 0; i < allPath[u].size(); ++i)  
    {  
        FindBestPath(allPath[u][i]);  
        possiblePath.pop_back();  
    }  
}  
int FindMin()  
{  
    int mmin = INF;  
    int index = -1;  
    for(int i = 0; i <= n; ++i)  
    {  
        if(city[i].dis < mmin && !visited[i])  
        {  
            mmin = city[i].dis;  
            index = i;  
        }  
    }  
    return index;  
}  
void Dijkstra(int s, int t)  
{  
    allPath.clear();  
    allPath.resize(n+1);  
    /*for(int i = 0; i <= n; ++i) 
        allPath[i].push_back(-1);*/  
    visited.assign(n+1, false);  
    for(int i = 0; i <= n; ++i)  
        city[i].dis = INF;  
    city[0].dis = 0;  
    while(true)  
    {  
        int u = FindMin();  
        if(u==-1) return;  
        visited[u] = true;  
        for(int i = 0; i < edge[u].size(); ++i)  
        {  
            int v = edge[u][i].v;  
            if(!visited[v])  
            {  
                int dis = edge[u][i].dis;  
                if(city[v].dis > city[u].dis+dis)  
                {  
                    allPath[v].clear();  
                    city[v].dis = city[u].dis+dis;  
                    allPath[v].push_back(u);  
                }  
                else if(city[v].dis == city[u].dis+dis)  
                {  
                    allPath[v].push_back(u);  
                }  
            }  
        }  
    }  
  
}  
int main()  
{  
    scanf("%d%d%d%d",&Cmax,&n,&Sp,&m);  
    city.clear();  
    city.resize(n+1);  
    for(int i = 1; i <= n; ++i)  
    {  
        scanf("%d",&city[i].c);  
        city[0].c = Cmax/2;  
    }  
    edge.clear();  
    edge.resize(n+1);  
    for(int i = 0; i < m; ++i)  
    {  
        int a, b, c;  
        scanf("%d%d%d",&a,&b,&c);  
        edge[a].push_back(Edge(b,c));  
        edge[b].push_back(Edge(a,c));  
    }  
      
    //end of input  
    //1. using dijkstra find all the possible solution  
    Dijkstra(0, Sp);  
    //2. enumerate all possible path and record the best one  
    FindBestPath(Sp);  
    //output the best solution  
    printf("%d 0",minSend);  
    for(int i = bestPath.size()-2; i >= 0; --i)  
        printf("->%d",bestPath[i]);  
    printf(" %d\n", minCollect);  
    return 0;  
}  

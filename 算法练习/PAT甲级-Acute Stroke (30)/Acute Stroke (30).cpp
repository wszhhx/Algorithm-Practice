/*
�������������ģ� ��
  �з���������ж��з����Ҫָ�꣬���ڸ�һЩ�������з����MRI��Ƭ������Ҫ�����з���������

����������
  ÿ���������һ������������ÿ����������һ�а���4����������   M��N��L��T��M��N��ÿ��MRI��Ƭ�ĳߴ磨�ߺͿ���ÿ����Ƭ��������128~1286֮��
(L<=60)�Ƕ�һ�����Ե�MRI��Ƭ��������T���ж��з����������ֵ�����ڵ���T����Ϊ�з硣
������������L����Ƭ���ݣ�ÿ����Ƭ�ã��ͣ���ɵľ����ʾ���������������򣬣������з�����������Ƭ�ĺ����һ������������ֻ��Ҫ����1������
������������Ȼ��һ�������п��ܴ��ںü����ֿ����з�����ֻ����Щ�����������ֵT�������������з�����
���������������ͬһ�������ڣ���ô���������ػ����ڽӣ���ͼ��ʾ�����к�ɫ���غ���ɫ�������ڡ�

���������
������ÿ�����ӣ�����з������������
��˼·����ÿ��û��visit�Ķ��㶼��ΪԴ���㿪ʼDFS�������DFS�е�����һ��������ָ��ֵΪ1�Ķ��㣬Ȼ�󷵻ر������ĵ�ĸ���
        ��1�ĸ��������ڱ��������аѱ������Ķ�������ǣ���������������ѱ������ĵ���ΪԴ�㿪ʼ������ÿ��������x,y,z��������
		�������ڶ��������x������y������z�����Ķ����Ƿ���1���ɣ�������ջ���ѷ���λ��true���Դ����ƣ�����ĳԴ������ı���
		����ֵ���ڵ���Tʱ������������������ֵ������ 
*/

#include<iostream>
#include<vector>
#include<stack>
#define MAX 1286
using namespace std;

typedef struct{
	bool is_stroke;
	bool is_visited;
	int num;
}pixel,*Pixel;

typedef struct{
	int x;
	int y;
	int z;
}point;

typedef vector<vector<vector<pixel> > > MSI;

int Calculate_Region(MSI &M,int x,int y,int z,int aL, int Q, int N){
	stack<point> S;
	int volume = 0;
	point p;
	point temp;
	p.x = x;
	p.y = y;
	p.z = z;
	S.push(p);
	int H,W,L;
	L = aL;			//��Ƭ���� 
	W = N;		//��Ƭ��� 
	H = Q;		//��Ƭ�߶� 
	while(!S.empty()){
		p = S.top();
		S.pop();
		if(!M[p.z][p.y][p.x].is_visited){
			M[p.z][p.y][p.x].is_visited = true;
			volume++;
			if(p.z+1<L && M[p.z+1][p.y][p.x].is_stroke && !M[p.z+1][p.y][p.x].is_visited){
				temp.x = p.x;
				temp.y = p.y;
				temp.z = p.z + 1;
				S.push(temp);
			}
			if(p.z-1 >= 0 &&  M[p.z-1][p.y][p.x].is_stroke && !M[p.z-1][p.y][p.x].is_visited){
				temp.x = p.x;
				temp.y = p.y;
				temp.z = p.z - 1;
				S.push(temp);
			}
			if(p.x-1 >= 0 &&  M[p.z][p.y][p.x-1].is_stroke && !M[p.z][p.y][p.x-1].is_visited){
				temp.x = p.x - 1;
				temp.y = p.y;
				temp.z = p.z;
				S.push(temp);
			}
			if(p.x+1 < W &&  M[p.z][p.y][p.x+1].is_stroke && !M[p.z][p.y][p.x+1].is_visited){
				temp.x = p.x + 1;
				temp.y = p.y;
				temp.z = p.z;
				S.push(temp);
			}
			if(p.y-1 >= 0 &&  M[p.z][p.y-1][p.x].is_stroke && !M[p.z][p.y-1][p.x].is_visited){
				temp.x = p.x;
				temp.y = p.y - 1;
				temp.z = p.z;
				S.push(temp);
			}
			if(p.y+1 < H &&  M[p.z][p.y+1][p.x].is_stroke && !M[p.z][p.y+1][p.x].is_visited){
				temp.x = p.x;
				temp.y = p.y + 1;
				temp.z = p.z;
				S.push(temp);
			}
		}
	}
	return volume;
}

int Calculate_Volume(MSI &msi,int T,int M, int N, int L){
	int volume = 0;
	int temp = 0;
	for(int i=0; i<L; i++){
		for(int j=0; j<M; j++){
			for(int k=0; k<N; k++){
				if(!msi[i][j][k].is_visited && msi[i][j][k].is_stroke == true){
					temp = Calculate_Region(msi,k,j,i,L,M,N);
					if(temp >= T)
						volume += temp;
				}
				
			}
		}
	}
	return volume;
}

int main(){
	int M,N,L,T;
	scanf("%d %d %d %d",&M,&N,&L,&T);
//	pixel msi[L*M*N];                   msi[i][j][k] = msi[i*N*M + j*N + N];
	vector<pixel> pn(N);
	vector<vector<pixel> > pm(M,pn);
	pn.clear();
	MSI msi(L,pm);
	pm.clear();
	int num = 1;
	for(int i=0; i<L; i++){
		for(int j=0; j<M; j++){
			for(int k=0; k<N; k++){
				scanf("%d",&(msi[i][j][k].is_stroke));        //msi[i][j][k] = msi + i*(M*N) + j*N + k;
				msi[i][j][k].is_visited = false;
				msi[i][j][k].num = num++;
			}
		}
	}
	
	int volume = Calculate_Volume(msi,T,M,N,L);
	printf("%d",volume);
	exit(0);
}



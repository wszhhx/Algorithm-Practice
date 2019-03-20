/*
问题描述（译文） ：
  中风域体积是判断中风的重要指标，现在给一些分析了中风域的MRI切片，你需要计算中风域的体积。

输入描述：
  每次输入包含一个用例，对于每个用例，第一行包含4个正整数：   M、N、L和T，M和N是每个MRI切片的尺寸（高和宽）且每个切片的像素在128~1286之间
(L<=60)是对一个大脑的MRI切片的数量；T是判断中风与否的体积阈值，高于等于T即判为中风。
　接下来给你L个切片数据，每个切片用０和１组成的矩阵表示，０代表正常区域，１代表中风区域。由于切片的厚度是一个常数，我们只需要计算1的数量
来获得体积，当然，一个大脑中可能存在好几个分开的中风区域，只有那些体积不低于阈值T的区域能算作中风区域。
　如果两像素属于同一面且相邻，那么这两个两素互相邻接，如图所示，所有红色像素和蓝色像素相邻。

输出描述：
　对于每个例子，输出中风区域总体积。
主思路：把每个没有visit的顶点都作为源顶点开始DFS，这里的DFS中的求下一个顶点是指求值为1的顶点，然后返回遍历到的点的个数
        （1的个数）并在遍历过程中把遍历过的顶点做标记，免得主遍历函数把遍历过的点作为源点开始遍历，每个顶点有x,y,z三个坐标
		，求相邻顶点就是求x相连，y相连，z相连的顶点是否是1即可，是则入栈，把访问位设true，以此类推，当从某源点出发的遍历
		返回值大于等于T时，总体积增加这个返回值的量； 
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
	L = aL;			//切片数量 
	W = N;		//切片宽度 
	H = Q;		//切片高度 
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



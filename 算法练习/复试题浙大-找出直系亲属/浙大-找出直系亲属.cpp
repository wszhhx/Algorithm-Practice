#include<iostream>
#include<vector>
#include<cstdlib>
#include<queue>
#define MAXSIZE 100000
using namespace std;

void reset(char T[]){
	for(int i=1; i<MAXSIZE; ++i)
		T[i] = '0';
}

int Find(char T[],char key){
	for(int i=1; i<MAXSIZE; ++i)
		if(T[i] == key)
			return i;
	return -1;
}

void Crt_Tree(char T[],int n){
	char child,father,mother;
	int index;
	for(int i=0; i<n; ++i){
		while(getchar()!='\n');
		scanf("%c%c%c",&child,&father,&mother);
		index = Find(T,child);
		if(index == -1){
			T[1] = child;
			index = 1;
		}
		if(father != '-'){
			T[index*2] = father;
		}
		if(mother != '-'){
			T[index*2+1] = mother;
		}
	}
}

void Process(char T[],char star,char end){
	int star_i = Find(T,star);
	int end_i = Find(T,end);
	int Star;
	char End;
	bool child;
	if(star_i < end_i){
		Star = star_i;
		End = end;
		child = false;
	}
	else{
		Star = end_i;
		End = star;
		child = true;
	}
	queue<int> Q;
	int p = Star;
	Q.push(p);
	int pre_num = 1;
	int b_num = 0;
	bool flag = false;
	int count = 0; 
	while(!Q.empty() && !flag){
		b_num = pre_num;
		pre_num = 0;
		count++;
		for(int i=0; i<b_num; ++i){
			p = Q.front();
			Q.pop();
			if(T[p*2]!='0'){
				if(T[p*2] == End){
					flag = true;
				}
				Q.push(p*2);
				pre_num++;
			}
			if(T[p*2+1] != '0'){
				if(T[p*2+1] == End){
					flag = true;
				}
				Q.push(p*2+1);
				pre_num++;
			}
		}
	}
	if(!flag){
		printf("-\n");
		return;
	}
	if(count == 1){
		if(!child)
			printf("child\n");
		else
			printf("parent\n");
		return;
	}
	for(int i=0; i<count-2; ++i){
		printf("great-");
	}
	if(!child)
		printf("grandchild\n");
	else
		printf("grandparent\n");
}

int main(){
	int n,m;
	char star,end;
	char T[MAXSIZE];
	while(scanf("%d %d",&n,&m)!=EOF){
		reset(T);
		if(n == 0 && m == 0)
			break;
		Crt_Tree(T,n);
		for(int i=0; i<m; ++i){
			while(getchar()!='\n');
			scanf("%c%c",&star,&end);
			Process(T,star,end);
		}
	}
	return 0;
}

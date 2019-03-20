#include<iostream>

typedef struct{
	char ID[16];
	int in_time;
	int out_time;
}Stu;

int main(){
	int h,m,s;
	int N;
	scanf("%d",&N);
	Stu stus[N];
	for(int i=0; i<N; ++i){
		scanf("%s",stus[i].ID);
		scanf("%d:%d:%d",&h,&m,&s);
		stus[i].in_time = h*3600 + m*60 + s;
		scanf("%d:%d:%d",&h,&m,&s);
		stus[i].out_time = h*3600 + m*60 + s;
	}
	int l_index = 0;
	int r_index = 0;
	for(int i=1; i<N; ++i){
		if(stus[i].in_time < stus[l_index].in_time)
			l_index = i;
		if(stus[i].out_time > stus[r_index].out_time)
			r_index = i;
	}
	printf("%s %s\n",stus[l_index].ID,stus[r_index].ID);
	return 0;
}

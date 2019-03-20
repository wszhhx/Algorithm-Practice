#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
typedef struct node{
	int left;
	int right;
}Node;
void Post_Order(Node Tree[],int N){
	stack<int> S;
	int ans[N];
	int index = 0;
	int p = 1;
	int pre = -1;
	while(p!=-1 || !S.empty()){
		while(p!=-1){
			S.push(p);
			p = Tree[p].left;
		}
		if(!S.empty()){
			p = S.top();
			if(Tree[p].right == -1 || Tree[p].right == pre){
				ans[index] = p;
				pre = p;
				p = -1;
				++index;
				S.pop();
			}
			else{
				p = Tree[p].right;
			}
		}
	}
	for(int i=0; i<N; i++){
		if(i == N-1)
			printf("%d\n",ans[i]);
		else
			printf("%d ",ans[i]);
	}
}
int main(){
	stack<int> S;
	char state[5];
	char pre_state[5];
	sprintf(pre_state,"none");
	int N;
	int index = 0;
	int pre_popindex;
	int id;
	scanf("%d",&N);
	Node Tree[N+1];
	for(int i=1; i<=N; ++i){
		Tree[i].left = -1;
		Tree[i].right = -1;
	}
	for(int i=0; i<2*N; ++i){
		scanf("%s",state);
		if(strcmp(state,"Push") == 0){
			scanf("%d",&index);
			if(i){
				if(strcmp(pre_state,"Push") == 0){
					Tree[S.top()].left = index;
				}
				else{
					Tree[pre_popindex].right = index;
				}
			}
			S.push(index);
			strcpy(pre_state,state);
		}
		else{
			pre_popindex = S.top();
			S.pop();
			strcpy(pre_state,"Pop");
		}
	}
	Post_Order(Tree,N);
	return 0;
}

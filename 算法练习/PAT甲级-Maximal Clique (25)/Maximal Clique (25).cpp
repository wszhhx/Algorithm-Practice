/*
若给出的序列组成的图不是完全图则输出Not a Clique
	否则，若给出的序列加上某个顶点形成了一个完全图，则输出    Not Maximal	
		否则输出 Yes
*/

#include<iostream>
#include<string.h>
using namespace std;

int Matrix[301][301];
int v_num,e_num,K,M;
int arrang[301];

bool Judge(int flag,int v,int k){
	int is_NP = true;
	if(flag)
		arrang[k++] = v;
	for(int i=0; i<k; ++i){
		for(int j=i+1; j<k; ++j){
			if(!Matrix[arrang[i]][arrang[j]]){
				is_NP = false;
				break;
			}
		}
		if(!is_NP)
			break;
	}
	return is_NP;
}

int main(){
	int v1,v2,k;
	bool flag;
	cin>>v_num>>e_num;
	for(int i=0; i<e_num; ++i){
		cin>>v1>>v2;
		Matrix[v1][v2] = Matrix[v2][v1] = 1;
	}
	cin>>M;
	while(M--){
		flag = false;
		cin>>K;
		for(int i=0; i<K; ++i){
			cin>>arrang[i];
		}
		if(!Judge(false,0,K)){
			cout<<"Not a Clique"<<endl;
			continue;
		}
		/*for(int i=1; i<=v_num; ++i){
			for(int j=0; j<K; ++j){
				if(Matrix[i][arrang[j]]){
					if(Judge(true,i,K)){
						cout<<"Not a Maximal"<<endl;
						flag = true;
						break;
					}
				}
			}
			if(flag)
				break;
		}*/
		for(int i=1; i<=v_num; ++i){
			if(Judge(true,i,K)){
				cout<<"Not a Maximal"<<endl;
				flag = true;
				break;
			}
		}
		if(flag == false){
			cout<<"Yes"<<endl;
		}
	}
	return 0;
}

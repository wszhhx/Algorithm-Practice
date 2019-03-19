#include<iostream>
#include<vector>
using namespace std;
typedef vector<vector<int> > Mrx;

int main(){
	bool charge = true;
	int N;
	Mrx M;
	while(cin>>N){
		M.clear();
		M.resize(N);
		for(int i=0; i<N; i++){
			M[i].resize(N);
			scanf("%d.%d.%d.%d",&M[i][0],&M[i][1],&M[i][2],&M[i][3]);
		}
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				if(M[i][j] >= 0 && M[i][j] <=255)
					continue;
				else
					charge = false;
			}
			if(charge)
				cout<<"Yes!"<<endl;
			else
				cout<<"No!"<<endl;
			charge = true;
		}
	}
	return 0;
}

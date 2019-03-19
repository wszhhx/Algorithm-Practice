#include<iostream>
#include<vector>
using namespace std;
typedef vector<vector<int> > Matrix;
void Proccess(Matrix & Mrx){
	int sum = 0;
	int k;
	for(int i = 0; i<Mrx.size(); i++){
		k = Mrx[i].size()-1;
		for(int j = Mrx[i].size()-1; j>=0; j--){
			if(Mrx[i][j] >= Mrx[i][k])
				k = j;
			sum += Mrx[i][j];
		}
		Mrx[i][k] = sum;
		sum = 0;
	}
}

int main(){
	Matrix Mrx;
	int M,N;
	while(cin>>M>>N){
		Mrx.clear();
		Mrx.resize(M);
		for(int i = 0; i<M; i++){
			Mrx[i].resize(N);
			for(int j = 0; j<N; j++){
				cin>>Mrx[i][j];
			}
		}
		Proccess(Mrx);
		for(int i = 0; i<M; i++){
			for(int j = 0; j<N; j++){
				if(j == N-1){
					cout<<Mrx[i][j];
					break;
				}
				else
					cout<<Mrx[i][j]<<' ';
			}
			cout<<endl;
		}
	}
	return 0;
}

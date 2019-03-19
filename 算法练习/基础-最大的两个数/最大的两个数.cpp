#include<iostream>
using namespace std;
int main(){
	int array[4][5];
	int N;
	int m1,m2,m;
	int temp;
	while(cin>>N){
		for(int i=0; i<N; i++){
			for(int j=0; j<4; j++)
				for(int k=0; k<5; k++)
					cin>>array[j][k];
			for(int j=0; j<5; j++){
				m1 = m2 = 0;
				for(int k=1; k<4; k++){
					if(array[k][j] > array[m1][j])
						m1 = k;
				}
				if(m1 == 0)
					m2 = 1;
				for(int k=1; k<4; k++){
					if(array[k][j] > array[m2][j] && m1 != k)
						m2 = k;
				}
				m = m1 < m2 ? m1:m2;
				temp = array[0][j];
				array[0][j]	= array[m][j];
				array[m][j] = temp;
				m = m1 > m2 ? m1:m2;
				temp = array[1][j];
				array[1][j] = array[m][j];
				array[m][j] = temp;
			}
			for(int j=0; j<2; j++){
				for(int k=0; k<5; k++)
					cout<<array[j][k]<<' ';
				cout<<endl;
			}
		}
	}
	return 0;
}

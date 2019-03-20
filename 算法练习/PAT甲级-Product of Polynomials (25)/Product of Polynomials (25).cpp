#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
typedef struct{
	double C;
	int E;
}Poly;

bool my_sort(Poly p1, Poly p2){
	return p1.E > p2.E;
}

void Process(Poly P1[],int k1,Poly P2[],int k2){
	Poly P3[k1+k2];
	int E;
	double C;
	map<int, int> Shrink;
	int k3 = 0;
	for(int i=0; i<k1; i++){
		for(int j=0; j<k2; j++){
			E = P1[i].E + P2[j].E;
			C = P1[i].C * P2[j].C;
			while(C >= 10){
				C/=10;
				++E;
			}
			if(Shrink.find(E) == Shrink.end()){ //若没有该指数的项 
				P3[k3].E = E;
				P3[k3].C = C;
				Shrink[E] = k3;
				++k3; 
			}
			else{
				P3[ Shrink[E] ].C += C;
			}
		}
	}
	sort(P3,P3+k3,my_sort);
	printf("%d ",k3);
	for(int i=0; i<k3; ++i){
		if(i == k3-1){
			printf("%d %.1lf\n",P3[i].E,P3[i].C);
		}
		else{
			printf("%d %.1lf ",P3[i].E,P3[i].C);
		}
	}
	
}

int main(){
	int k1,k2;
	scanf("%d",&k1);
	Poly P1[k1];
	for(int i=0; i<k1; i++){
		scanf("%d",&P1[i].E);
		scanf("%lf",&P1[i].C);
	}
	scanf("%d",&k2);
	Poly P2[k2];
	for(int i=0; i<k2; i++){
		scanf("%d",&P2[i].E);
		scanf("%lf",&P2[i].C);
	}
	Process(P1,k1,P2,k2);
	return 0;
}

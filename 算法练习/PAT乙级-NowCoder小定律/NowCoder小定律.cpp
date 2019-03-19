#include<iostream>
#include<cmath>
#define MAX 20000
using namespace std;
bool PrimeCharge(int x){
	int i, j;  
	if (x == 2)
        return false;
    else
        if (x < 2 || x % 2 ==0)
            return true;
    else
    {
        j = (int)sqrt(x + 1);
        for (i = 3; i <= j; i = i + 2)
            if (x % i == 0)
                return false;
    }
	return true;
}

int main(){
	int x[MAX],y[MAX];
	int temp1,temp2;
	int i,j,A;
	bool flag = true;
	i = j = 0;
	while(scanf("%d %d",&temp1,&temp2)!=EOF){
		if(temp1==0 && temp2==0){
			for(int k = 0; k<i ; k++){
				for(int l = x[k]; l<=y[k]; l++){
					A = l*l+l+41;
					if(!PrimeCharge(A)){
						flag = false;
					}
				}
				if(flag)
					cout<<"OK"<<endl;
				else
					cout<<"Sorry"<<endl;
				flag = true;
			}
			
			i = 0;
			j = 0;
		}
		else{
			x[i++] = temp1;
			y[j++] = temp2;
		}
	}
	return 0;
}

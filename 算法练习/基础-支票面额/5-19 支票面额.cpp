#include<iostream>
int main(){
	int n;
	bool flag=false;
	scanf("%d",&n);
	int f,y;
	for(y=0; y<100; y++){
		for(f=0; f<100; f++){
			if(n == (98*f-199*y))
			printf("%d.%d\n",y,f);
			flag = true;
		}
	}
	if(!flag)
		printf("No Solution\n");
	return 0;
}

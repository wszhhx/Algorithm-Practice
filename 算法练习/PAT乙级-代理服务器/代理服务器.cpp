#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

int main(){
	int m,n;
	int result;
	int count;
	vector<string> DLS;
	vector<string> SER;
	while(scanf("%d",&n) != EOF){
		DLS.clear();
		SER.clear();
		count = 0;
		result = 0;
		DLS.resize(n);
		for(int i=0; i<n; ++i)
			cin>>DLS[i];
		scanf("%d",&m);
		SER.resize(m);
		for(int i=0; i<m; ++i)
			cin>>SER[i];
		if(n == 1){
			for(int i=0; i<m; ++i){
				if(DLS[0] == SER[i]){
					printf("-1");
					break;
				}
			}
		}
		else{
			int max = 0;
			int i = 0;
			int distance;
			while(count != m){
				max = 0;
				for(int j=0; j<n && i<m; ++j){   //iΪ��ʵ������ָ�룬jΪ���������ָ�� 
					i = count;
					distance = 0;
					while(i < m && DLS[j] != SER[i]){      //����ÿһ������������ľֲ�·�����ߵ����ֵ 
						i++;
						distance++;
					}
					if(max < distance)
						max = distance;
				}
				count += max;
				if(count < m)
					result++;
				count++;
			}
			printf("%d",result);
		}
	}
	return 0;
}




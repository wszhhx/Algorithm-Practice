//������A��B��C����С��״��ͬ��������һ������������������ͬ��Ҫ���ҳ������һ������

//�����ʽ��
//������һ���и���3����������˳���Ӧ��A��B��C��������

//�����ʽ��
//��һ�������Ψһ���Ǹ���һ������
#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	char C[3]={'A','B','C'};
	int A[3];
	for(int i=0;i<3;i++)	cin>>A[i];
	int i=1;
	while(A[0]!=A[i] && i<3)
		i++;
	if(i==3)
		cout<<C[0];
	else if(i==1)
		cout<<C[2];
	else
		cout<<C[1];
	cout<<endl;
	system("pause");
	return 0;
}

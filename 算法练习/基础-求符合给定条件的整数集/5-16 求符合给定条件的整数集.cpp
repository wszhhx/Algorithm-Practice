//����������6��������A�����Ǵ�A��ʼ������4�����֡������������������ɵ����ظ����ֵ�3λ����

//�����ʽ��
//������һ���и���A��

//�����ʽ��
//������������ĵ�3λ����Ҫ���С����ÿ��6���������������Կո�ָ�������ĩ�����ж���ո�

#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int m=n+3;
	int flag=0;
	for(int i=n;i<=m;i++){
		for(int j=n;j<=m;j++){
			if(j==i)
				continue;
			for(int k=n;k<=m;k++){
				if(k==j || k==i)
					continue;
				flag++;
				if(flag%6==0)
					cout<<i*100+j*10+k<<endl;
				else{
					cout<<i*100+j*10+k<<' ';
				}
			}
		}
	}
	return 0;
}

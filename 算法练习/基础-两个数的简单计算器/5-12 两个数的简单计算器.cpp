//����Ҫ���дһ���򵥼��������򣬿ɸ�����������������2���������мӡ������ˡ������������㡣
//��Ŀ��֤�������������������ͷ�Χ��

//�����ʽ��
//������һ�����������������1���������������2�������1���ո�ָ�������������������Ϊ���ͣ�
//�ұ�֤����������ķ�ĸ���㡣

//�����ʽ��
//�������Ϊ+��-��*��/��%ʱ����һ�������Ӧ�����������������ǷǷ����ţ������˼ӡ������ˡ�
//�����������������������������ţ������ERROR��
#include<iostream>
using namespace std;
int main(){
	int a,b,answer;
	char operation;
	cin>>a>>operation>>b;
	if(operation=='+' || operation=='-' || operation=='*' || operation=='/' || operation=='%'){
		switch(operation){
			case '+':
				cout<<a+b<<endl;
				break;
			case '-':
				cout<<a-b<<endl;
				break;
			case '*':
				cout<<a*b<<endl;
				break;
			case '/':
				cout<<a/b<<endl;
				break;
			case '%':
				cout<<a%b<<endl;
				break;
		}
	}
	else{
		cout<<"ERROR"<<endl;
		return 0;
	}
	return 0;
}

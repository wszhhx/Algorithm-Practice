//��Ʊ�۸��ǵ����ƣ���������ͼ�����е�K��ͼ����ʾ����Ϊ���յ���K�ߡ����ܵ���K�ߡ����µ���K�ߵȡ�
//����K��Ϊ����ÿ���Ʊ�۸�ӿ��̵���������һ�죬��Ӧһ������Сͼ��Ҫ��ʾ�ĸ��۸񣺿��̼۸�Open
//�����ϸոտ�ʼ���������ɽ��ĵ�1�ʼ۸񣩡����̼۸�Close����������ʱ���һ�ʳɽ��ļ۸񣩡�
//�м����߼�High����ͼ�Low��
//���Close<<Open����ʾΪ��BW-Solid��������ʵ���������򡱣������Close>>Open����ʾΪ��R-Hollow��
//���������ĺ����򡱣������Open����Close����Ϊ��R-Cross��������ʮ�ֺ����򡱣���
//���Low��Open��Close�ͣ���Ϊ��Lower Shadow������������Ӱ�ߡ��������High��Open��Close�ߣ�
//��Ϊ��Upper Shadow������������Ӱ�ߡ����������򣬸��ݸ������ĸ��۸���ϣ��жϵ��յ�������һ��
//ʲô��������

//�����ʽ��
//������һ���и���4����ʵ�����ֱ��ӦOpen��High��Low��Close������Կո�ָ���

//�����ʽ��
//��һ���������K��������͡�������ϡ���Ӱ�ߣ��������ͺ����with Ӱ�����͡�
//�������Ӱ�߶��У������with Lower Shadow and Upper Shadow��
#include<iostream>
using namespace std;
int main(){
	double Open,High,Low,Close;
	cin>>Open>>High>>Low>>Close;
	if(Close<Open){
		cout<<"BW-Solid";
	}
	else if(Close>Open){
		cout<<"R-Hollow";
	}
	else{
		cout<<"R-Cross";
	}
	if(Low<Close && Low<Open){
		if(High>Close && High>Open){
			cout<<" with Lower Shadow and Upper Shadow";
		}
		else{
			cout<<" with Lower Shadow";
		}
	}
	else if(High>Close && High>Open){
		cout<<" with Upper Shadow";
	}
	else{
		return 0;
	}
}

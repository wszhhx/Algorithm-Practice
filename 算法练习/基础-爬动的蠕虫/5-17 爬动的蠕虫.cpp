//һ����泤1�磬��һ����ΪN��ľ��ĵײ�����֪���ÿ1���ӿ���������U�磬��������Ϣ1���Ӳ��ܽ���������������Ϣ�Ĺ����У�������»���D�硣
//���������������»��ظ����С����ʣ������Ҫ�೤ʱ�������������

//����Ҫ����1���Ӱ�1���Ӽƣ����Ҽٶ�ֻҪ��ĳ����������������ͷ�������˾��Ķ�������ô������������ˡ���ʼʱ�������ſ�ھ��׵ģ����߶�Ϊ0����

//�����ʽ��
//������һ����˳�����3��������N��U��D������D<<U��N������100��

//�����ʽ��
//��һ������������������ʱ�䣬�Է���Ϊ��λ��
#include<iostream>
using namespace std;
class worm{
	public:
		worm():height(0),time(0){
		}
		void up(int U,int D,int N){
			height += U;
			if(charge(N)){
				time++;
				return;
			}
			else{
				height -= D;
				time+=2;
			}
		}
		bool charge(int N){
			if(height >=N )
				return true;
			else
				return false;
		} 
		int gettime(){
			return time;
		}
	private:
		int height;
		int time;
};

int main(){
	worm Worm;
	int N,U,D;
	cin>>N>>U>>D;
	while(!Worm.charge(N)){
		Worm.up(U,D,N);
	}
	cout<<Worm.gettime()<<endl;
	return 0;
}

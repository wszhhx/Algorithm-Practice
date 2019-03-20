/*
题目描述（译）
  老鼠与米饭是某个程序竞赛的名字，在此竞赛中，每个程序员需要编写一段自己的代码来在一个给定的地图中控制老鼠的行动
，每只老鼠的目标是为了成为一只硕鼠而尽可能多吃米饭。
  第一，这个玩家顺序是由Np个程序员随机决定，这些程序员以 Ng个人为一个小组，每个小组中最肥的老鼠胜利并进入下一回合
每个回合中输掉的人排名是相同的，在最后的唯一胜者胜出前，每Ng个胜利者再组成一个小组进行比赛。
  为了简要，假设每只老鼠的体重在对应程序员提交代码的那一刻就已经决定。
  现在给你所有老鼠的重量以及初始比赛顺序，你需要输出这些程序员的排行。
  
输入描述：
  每个输入包含一个用例，在每个用例中，第一行包含2个正整数Np和Ng（<=1000）,分别是程序员的总数和每组老鼠的最大数目。
  若在玩家列表的最后，老鼠不足Ng个，则这些老鼠组个队。
  第二行包含Np个确定的非负数Wi（i=0,1,2,,,Np-1）Wi分别是编号为i的老鼠的重量
  第三行给出初始顺序，这个顺序是0~Np-1的序列，（假设每个程序员有0~Np-1的编号），每个数据用空格隔开
  
输出描述：
  对于每个用例，在一行中打印排名第i个数字代表第i个程序员的排名，每个数字用空格隔开，末尾不能有空格。
  
   （排名 = 晋级人数+1） 
如：输入：11 3
		  25 18 0 46 37 3 19 22 57 56 10
		  6  0  8 7  10 5 9  1  4  2  3
	输出：5 5 5 2 5 5 5 3 1 3 5 

*/
#include<iostream>
#include<cstdlib>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct node{
	int _id;
	int _weight;
	int _order;
	bool _win;
	int _rank;
}Programmers;

bool Sort_id(Programmers p1,Programmers p2){
	return p1._id < p2._id;
}

bool Sort_order(Programmers p1,Programmers p2){
	return p1._order < p2._order;
}

void Test(vector<Programmers> &Ps){
	for(int i=0; i<Ps.size(); i++){
		cout<<Ps[i]._weight<<' ';
	}
	cout<<endl;
}

void Crt(vector<Programmers> &Ps,int Np){
	for(int i=0; i<Np; i++){
		cin>>Ps[i]._weight;
		Ps[i]._id = i;
		Ps[i]._win = false;
		Ps[i]._rank = -1;
	}
	for(int i=0; i<Np; i++)
		cin>>Ps[i]._order;
	return;
}

void Group_Rank( vector<Programmers> &Ps, int Begin, int End ){       //只负责某个小组内部的排序 
	
}   

int F_Rank( vector<Programmers> &Ps, int Ng, int Np ){               //
	
}

void Rank( vector<Programmers> &Ps, int Ng, int Person ){
	
}

void Main_Rank( vector<Programmers> &Ps , int Ng, int Person){           //负责控制总体排序流程 
	int F_win = F_Rank(Ps,Ng,Np);
	Rank(Ps,Ng,F_win);
}

int main(){
	vector<Programmers> Ps;
	int Np,Ng;
	cin>>Np>>Ng;
	Ps.resize(Np); 
	Crt(Ps,Np);
	sort(Ps.begin(),Ps.end(),Sort_order);
	Test(Ps);
	return 0;
}

/*
题目描述（译文）：
  浙江大学有6个学院以及非常多的大门。我们可以收集通过某个大门的车的进出时间以及其车牌号。现在，所有信息都已给你，要求你给出
在任何时间点停靠在大学内的车的数量以及在一天结束时找出停在校内最久的车辆。

输入描述：
  每次输入包含一个用例，每个用例开始的时候给出两个正整数N       （N<=1000）代表记录数量，和K(K<=80000),代表查询数。
  接下来N行每行输入一个记录，格式如下：
  plate_number hh:mm:ss in/out
  车牌号(plate_number)是一个长度为7的字符串，由大写字母和数字组成，hh:mm:ss为 时：分：秒，in/out为说明这车是进还是出
  所有时间都是在同一天内，若有一车有多个in记录，则取时间往后的那个记录生效，所有没有out记录的车的in记录不生效，我们保证
至少有一辆车是停好了的且没有车的in记录与out记录时间是一样的，使用24小时制；
  接下来的K行输入询问信息，每次以hh:mm:ss的形式给出询问时间（询问时间按升序输入）
  
输出描述：
  对于每次询问，在一行输出此询问要求时间点校内停靠的车数，最后以后输出一天内停靠时间最久的汽车的车牌号与停车时间。若不止一辆车
停靠时间最长，则按字母表顺序输出所有这样的车最后再输出停靠时长，所有数据以空格隔开。

例：输入：	6 7
			JH007BD 18:00:01 in
			ZD00001 11:30:08 out
			DB8888A 13:00:00 out
			ZA3Q625 23:59:50 out
			ZA133CH 10:23:00 in
			ZD00001 04:09:59 in
			JH007BD 05:09:59 in
			ZA3Q625 11:42:01 out
			JH007BD 05:10:33 in
			ZA3Q625 06:30:50 in
			JH007BD 12:23:42 out
			ZA3Q625 23:55:00 in
			JH007BD 12:24:23 out
			ZA133CH 17:11:22 out
			JH007BD 18:07:01 out
			DB8888A 06:30:50 in  
			05:10:00
			06:30:50
			11:00:00
			12:23:42
			14:00:00
			18:00:00
			23:59:00
	输出：	1
			4
			5
			2
			1
			0
			1
			JH007BD ZD00001 07:20:09 
*/
//思路：设计一个时间结构，一个车结构，用向量装之，还有一个MAP用来装车牌号与之停靠时间。
//#include<iostream>
//#include<vector>
//#include<map>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//typedef enum STATE{in,out} state;
//
//typedef struct{
//	int h;
//	int m;
//	int s;
//}MyTime;
//
//typedef struct{
//	char plate_num[8];
//	MyTime in_time;
//	state State;
//	bool del;
//}car; 
//
//MyTime Time_D(MyTime &T1,MyTime &T2){
//	int sum1 = T1.h*60*60 + T1.m*60 + T1.s;
//	int sum2 = T2.h*60*60 + T2.m*60 + T2.s;
//	int sum3 = sum1 - sum2;
//	MyTime T3;
//	T3.h = sum3/3600;
//	sum3 %= 3600;
//	T3.m = sum3/60;
//	sum3 %= 60;
//	T3.s = sum3;
//	return T3;
//}
//
//MyTime Time_I(MyTime &T1,MyTime &T2){
//	int sum1 = T1.h*60*60 + T1.m*60 + T1.s;
//	int sum2 = T2.h*60*60 + T2.m*60 + T2.s;
//	int sum3 = sum1 + sum2;
//	MyTime T3;
//	T3.h = sum3/3600;
//	sum3 %= 3600;
//	T3.m = sum3/60;
//	sum3 %= 60;
//	T3.s = sum3;
//	return T3;
//}
//
//bool time_Compare(MyTime &t1, MyTime &t2){  //t1<t2返回true 
//	if(t1.h < t2.h)
//		return true;
//	else if(t1.h > t2.h)
//		return false;
//	else{
//		if(t1.m < t2.m)
//			return true;
//		else if(t1.m > t2.m)
//			return false;
//		else{
//			if(t1.s <= t2.s)
//				return true;
//			else
//				return false;
//		}
//	}
//}
//
//bool my_Compare(car c1, car c2){
//	return time_Compare(c1.in_time,c2.in_time);
//}
//
//inline bool is_equal(MyTime &t1,MyTime &t2){
//	if(t1.h == t2.h && t1.m==t2.m && t1.s == t2.s)
//		return true;
//	else
//		return false;
//}
//
//int Find(car Campus[],int &length,car &c){
//	bool flag = false;
//	int ans = 0;
//	for(int i=0; i<length; ++i){
//		if(strcmp(Campus[i].plate_num,c.plate_num) == 0 && Campus[i].del == false){
//			ans = i;
//			flag = true;
//		}
//	}
//	if(flag)
//		return ans;
//	else
//		return -1;
//}
//
//void Process(car Records[],int R_num,int Q_num){
//	map<string, MyTime> Period;
//	car Campus[R_num];          //记录停车实时情况 
//	car Mid_Records[R_num];     //过滤掉没用的记录后的记录集合 
//	int C = 0;  //Campus指示 
//	int M = 0;  //Mid_Records指示 
//	int index; 
//	MyTime Q_time,T_time;
//	int car_num = 0;
//	int j = 0;
//	for(int i=0; i<R_num; ++i){
//		if(Find(Mid_Records,M,Records[i]) == -1){ 
//			if(Records[i].State == in){
//				Mid_Records[M] = Records[i];
//				++M;
//			}
//		}
//		else{ 
//			index = Find(Mid_Records,M,Records[i]);
//			if(Records[i].State == in && Mid_Records[index].State == in){
//				Mid_Records[index] = Records[i];
//			}
//			if((Records[i].State == in && Mid_Records[index].State == out) || (Records[i].State == out && Mid_Records[index].State == in)){
//				Mid_Records[M] = Records[i];
//				++M;
//			}
//		}	
//	}
//	for(int i=0; i<Q_num; ++i){
//		scanf("%d:%d:%d",&Q_time.h,&Q_time.m,&Q_time.s);
//		while(time_Compare(Mid_Records[j].in_time,Q_time)){
//			index = Find(Campus,C,Mid_Records[j]);
//			if(index == -1){
//				Campus[C] = Mid_Records[j];
//				++car_num;
//				++C;
//			}
//			else{
//				--car_num;
//				string temp(Mid_Records[j].plate_num);
//				if(Period.find(temp) == Period.end()){
//					Period[temp] = Time_D(Mid_Records[j].in_time,Campus[index].in_time);
//					Campus[index].del = true;
//				}
//				else{
//					T_time = Time_D(Mid_Records[j].in_time,Campus[index].in_time);
//					Period[temp] = Time_I(Period[ Mid_Records[j].plate_num ],T_time);
//					Campus[index].del = true;
//				}
//			}
//			++j;
//		}
//		printf("%d\n",car_num);
//	}
//	
//	while(j < M){
//		index = Find(Campus,C,Mid_Records[j]);
//		if(index == -1){
//				Campus[C] = Mid_Records[j];
//				++C;
//			}
//		else{
//			string temp(Mid_Records[j].plate_num);
//			if(Period.find(temp) == Period.end()){
//				Period[temp] = Time_D(Mid_Records[j].in_time,Campus[index].in_time);
//				Campus[index].del = true;
//			}
//			else{
//				T_time = Time_D(Mid_Records[j].in_time,Campus[index].in_time);
//				Period[temp] = Time_I(Period[ Mid_Records[j].plate_num ],T_time);
//				Campus[index].del = true;
//			}
//		}
//		++j;
//	}
//	map<string, MyTime>::iterator it = Period.begin();
//	MyTime temp1 = it->second;
//	while(it != Period.end()){
//		if(time_Compare(temp1,it->second)){
//			temp1 = it->second;
//		}
//		++it;
//	}
//	for(it = Period.begin(); it != Period.end(); ++it){
//		if(is_equal(temp1,it->second)){
//			cout<<it->first<<' ';
//		}
//	}
//	printf("%02d:%02d:%02d",temp1.h,temp1.m,temp1.s);
//	
//}
//
//int main(){
//	int R_num;
//	int Q_num;
//	scanf("%d %d",&R_num,&Q_num);
//	char state[4];
//	car Records[10000];
//	for(int i=0; i<R_num; i++){
//		scanf("%s",Records[i].plate_num);
//		scanf("%d:%d:%d",&Records[i].in_time.h,&Records[i].in_time.m,&Records[i].in_time.s);
//		scanf("%s",state);
//		if(strcmp(state,"out") == 0)
//			Records[i].State = out;
//		else
//			Records[i].State = in;
//		Records[i].del = false;
//	}
//	sort(Records,Records+R_num,my_Compare);
//	Process(Records,R_num,Q_num);
//	exit(0);
//}

#include<iostream>
#include<map>
#include<algorithm>
#define MAX 10000
#define INFINITE 20000
using namespace std;
typedef struct{
	string plate_num;
	int time;
	int state;        //0为进1为出 
	int pre;     //上一个in的位置 
	int next;
	bool del;
}Car;


bool Time_Compare(Car c1, Car c2){
	return c1.time < c2.time;
}

void Process(Car Records[],int R_num,int Q_num){
	map<string ,int> Thread;
	map<string ,int>::iterator its;
	int h,m,s,j = 0;
	int time;
	int car_num = 0;
	for(int i=1; i<=R_num; ++i){ //把每辆车各自的记录单独串联成一个线索，由Thread辅助完成。之后Thread用来存每辆车停放的时间 
		Records[i].pre = Thread[ Records[i].plate_num ];       //上一个指向 
		Records[ Thread[ Records[i].plate_num ] ].next = i;
		Thread[ Records[i].plate_num ] = i;
	}
	Thread.clear();
	for(int i=0; i<Q_num; ++i){
		scanf("%d:%d:%d",&h,&m,&s);
		time = h*3600 + m*60 + s;
		while(Records[j].time <= time){
			if(Records[j].state == 0 && Records[j].next != INFINITE && Records[ Records[j].next ].state != 0){    //若此记录的车下一条记录不是in则判为成功泊车 
				car_num++;
			}
			if(Records[j].state == 1 && Records[j].pre != 0 && Records[ Records[j].pre ].state != 1){             //若此记录的车上一条记录不是out则判为成功出车 
				car_num--;
				Thread[ Records[j].plate_num ] += (Records[j].time - Records[ Records[j].pre ].time);
			}
			++j;
		}
		printf("%d\n",car_num);
	}
	while(j<=R_num){
		if(Records[j].state == 1 && Records[j].pre != 0 && Records[ Records[j].pre ].state == 0){  //若此记录的车上一条记录不是out则判为成功出车 
			Thread[ Records[j].plate_num ] += (Records[j].time - Records[ Records[j].pre ].time);
		}
		++j;
	}
	time = 0;
	for(its = Thread.begin(); its != Thread.end(); ++its){
		if(its->second > time){
			time = its->second;
		}
	}
	for(its = Thread.begin(); its!=Thread.end(); ++its){
		if(time == its->second){
			cout<<its->first<<' ';
		}
	}
	printf("%02d:%02d:%02d\n",time/3600,time%3600/60,time%60);
}

int main(){
	Car Records[MAX+1];
	string state;
	int R_num;
	int Q_num;
	int h,m,s;
	scanf("%d %d",&R_num,&Q_num);
	for(int i=1; i<=R_num; ++i){
		cin>>Records[i].plate_num;
		scanf("%d:%d:%d",&h,&m,&s);
		Records[i].time = h*3600 + m*60 + s;
		Records[i].pre = 0;
		Records[i].next = INFINITE;
		Records[i].del = false;
		cin>>state;
		if(state == "in")
			Records[i].state = 0;
		else
			Records[i].state = 1;
	}
	sort(Records+1,Records+R_num+1,Time_Compare);
	Process(Records,R_num,Q_num);
	exit(0);
}

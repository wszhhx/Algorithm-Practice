//要求严格按照给出的格式输出下列表格：

//------------------------------------
//Province      Area(km2)   Pop.(10K)
//------------------------------------
//Anhui         139600.00   6461.00
//Beijing        16410.54   1180.70
//Chongqing      82400.00   3144.23
//Shanghai        6340.50   1360.26
//Zhejiang      101800.00   4894.00
//------------------------------------
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
void line(){
	for(int i=0;i<36;i++){
		cout<<'-';
	}
	return;
}
/*int main(){
	line();
	cout<<endl;
	string str[5]={"Anhui","Beijing","Chongqing","Shanghai","Zhejiang"};
	double a[5]={139600,16410.54,82400,6340.5,101800};
	double b[5]={6461,1180.7,3144.23,1360.26,4894};
	cout<<setw(10)<<setfill(' ')<<left<<"Province"<<setw(13)<<right<<"Area(km2)"<<"   "<<setw(13)<<left<<"Pop.(10K)"<<endl;
	line(); cout<<endl;
	for(int i=0;i<5;i++){
		cout<<setprecision(2)<<fixed<<setw(14)<<setfill(' ')<<left<<str[i]<<setw(9)<<right<<a[i]<<"   "<<setw(10)<<left<<b[i]<<endl;
	}
	line();
	return 0;
}*/

int main(){
	line(); cout<<endl;
	cout<<"Province      Area(km2)   Pop.(10K)"<<endl;
	line(); cout<<endl;
	cout<<"Anhui         139600.00   6461.00"<<endl;
	cout<<"Beijing        16410.54   1180.70"<<endl;
	cout<<"Chongqing      82400.00   3144.23"<<endl;
	cout<<"Shanghai        6340.50   1360.26"<<endl;
	cout<<"Zhejiang      101800.00   4894.00"<<endl;
	line();
	return 0;
}

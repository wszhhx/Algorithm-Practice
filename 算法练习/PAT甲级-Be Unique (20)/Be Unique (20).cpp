#include<iostream>
#include<map>
#include<vector>
using namespace std;
int main(){
	map< int, int> my_Map;
	vector<int> Seq;
	int temp;
	int N;
	cin>>N;
	for(int i=0; i<N; i++){   // 
		cin>>temp;
		if(my_Map[temp] == 0){
			my_Map[temp] = 1;
			Seq.push_back(temp);
		}
		else{
			my_Map[temp] += 1;
		}
	}
	for(vector<int>::iterator its = Seq.begin(); its != Seq.end(); its++){
		if(my_Map[*its] == 1){
			cout<<*its<<endl;
			return 0;
		}
	}
	cout<<"None"<<endl;
	return 0;
}

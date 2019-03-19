#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef struct people{
	int age;
	string name;
	int mun;
}Worker;

bool Compare(Worker worker1, Worker worker2){
	if(worker1.age >= worker2.age){
		if(worker1.age == worker2.age){
			if(worker1.mun >= worker2.mun){
				if(worker1.mun == worker2.mun){
					if(worker1.name > worker2.name)
						return true;
					else
						return false;
				}
				else
					return true;
			}
			else
				return false;
		}
		else
			return true;
	}
	else
		return false;
} 

void Find_Min3(vector<Worker> &worker){
	Worker temp;
	bool change = true;
	for(int i = 1; i < (worker.size() < 4 ? worker.size() :4 ) && change; i++){
		change = false;
		for(int j = 1; j <= worker.size() - i - 1; j++){
			if(Compare(worker[j+1],worker[j])){
				temp = worker[j];
				worker[j] = worker[j+1];
				worker[j+1] = temp;
				change = true;
			}
		}
	}
	return;
}

int main(){
	vector<Worker> worker;
	int N;
	while(cin>>N){
		worker.clear();
		worker.resize(N+1);
		for(int i = 1; i<=N; i++){
			cin>>worker[i].mun>>worker[i].name>>worker[i].age;
		}
		Find_Min3(worker);
		for(int i = 1; i<= (worker.size() < 3 ? worker.size() : 3); i++){
			cout<<worker[N-i+1].mun<<' '<<worker[N-i+1].name<<' '<<worker[N-i+1].age<<endl;
		}
	}
	return 0;
}

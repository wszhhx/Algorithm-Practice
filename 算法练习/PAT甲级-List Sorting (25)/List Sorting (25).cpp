#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef struct{
	int ID;
	char name[9];
	int grade;
}STU;

bool sort_id(STU stu1, STU stu2){
	return stu1.ID < stu2.ID;
}

bool sort_name(STU stu1, STU stu2){
	if(strcmp(stu1.name,stu2.name) == 0)
		return stu1.ID < stu2.ID;
	else{
		if(strcmp(stu1.name,stu2.name) < 0)
			return true;
		else
			return false;
	}
}

bool sort_grade(STU stu1, STU stu2){
	if(stu1.grade == stu2.grade)
		return stu1.ID < stu2.ID;
	else
		return stu1.grade < stu2.grade;
}

int main(){
	int N,C;
	scanf("%d %d",&N,&C);
	STU stus[N];
	for(int i=0; i<N; ++i){
		scanf("%d %s %d",&stus[i].ID,stus[i].name,&stus[i].grade);
	}
	switch(C){
		case 1:
			sort(stus,stus+N,sort_id);
			break;
		case 2:
			sort(stus,stus+N,sort_name);
			break;
		case 3:
			sort(stus,stus+N,sort_grade);
			break;
	}
	for(int i=0; i<N; ++i){
		printf("%06d %s %d\n",stus[i].ID,stus[i].name,stus[i].grade);
	}
	return 0;
}

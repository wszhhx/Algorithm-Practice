#include<iostream>
using namespace std;
class Student
{
	public:
		Student(int id=0,int de=0,int cai=0,int Class=0):ID(id),DE(de),CAI(cai),CLASS(Class){};
		Student(const Student &stu){};
		~Student(){};
		int ID;
		int DE;
		int CAI;
		int CLASS;
};
void Sort(Student Stu[],Student Class1[],Student Class2[],Student Class3[],Student Class4[],int &sum1,int &sum2,int &sum3,int &sum4,int n,int L,int H);
void Paixu(Student Stu[],int n);
void Output(Student Stu[],int n);
int main()
{
	int N,L,H;
	int n1=0,n2=0,n3=0,n4=0,np=0;
	int &sum1=n1;
	int &sum2=n2;
	int &sum3=n3;
	int &sum4=n4;
	cin>>N>>L>>H;
	Student *Stu=new Student[N];
    Student *Class1=new Student[N];
    Student *Class2=new Student[N];
    Student *Class3=new Student[N];
    Student *Class4=new Student[N];
    Student *Pass=new Student[N];
	for(int i=0;i<N;i++)
	{
		cin>>Stu[i].ID>>Stu[i].DE>>Stu[i].CAI;
	}
	Sort(Stu,Class1,Class2,Class3,Class4,sum1,sum2,sum3,sum4,N,L,H);
	Paixu(Class1,n1);
	Paixu(Class2,n2);
	Paixu(Class3,n3);
	Paixu(Class4,n4);
	cout<<n1+n2+n3+n4<<endl;
	Output(Class1,n1);
	Output(Class2,n2);
	Output(Class3,n3);
	Output(Class4,n4);
    delete []Stu;
    delete []Class1;
    delete []Class2;
    delete []Class3;
    delete []Class4;
    delete []Pass;
	return 0;
}
void Sort(Student Stu[],Student Class1[],Student Class2[],Student Class3[],Student Class4[],int &sum1,int &sum2,int &sum3,int &sum4,int n,int L,int H)
{
	for(int i=0;i<n;i++)
	{
		if(Stu[i].DE<L || Stu[i].CAI<L)
		{
			Stu[i].CLASS=5;
			continue;
		}
		else if(Stu[i].DE>=H && Stu[i].CAI>=H)
		{
			Stu[i].CLASS=1;
			Class1[sum1]=Stu[i];
			sum1++;
			continue;
		}
		else if(Stu[i].DE>=H && Stu[i].CAI<H)
		{
			Stu[i].CLASS=2;
			Class2[sum2]=Stu[i];
			sum2++;
			continue;
		}
		else if(Stu[i].DE<H && Stu[i].CAI<H && Stu[i].DE>Stu[i].CAI)
		{
			Stu[i].CLASS=3;
			Class3[sum3]=Stu[i];
			sum3++;
			continue;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(Stu[i].CLASS==0 && Stu[i].DE>=L && Stu[i].CAI>=60)
		{
			Stu[i].CLASS=4;
			Class4[sum4]=Stu[i];
			sum4++;
		}
	}
	return;
	
}

void Paixu(Student Stu[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-1-i;j++)
		{
			if(Stu[j].DE+Stu[j].CAI<Stu[j+1].DE+Stu[j+1].CAI || Stu[j].DE+Stu[j].CAI==Stu[j+1].DE+Stu[j+1].CAI && Stu[j].DE<Stu[j+1].DE || Stu[j].DE+Stu[j].CAI==Stu[j+1].DE+Stu[j+1].CAI && Stu[j].DE==Stu[j+1].DE && Stu[j].ID>Stu[j+1].ID)
			{
				Student *p=new Student;
				*p=Stu[j];
				Stu[j]=Stu[j+1];
				Stu[j+1]=*p;
				delete p;
			}
		}
	}
	return;
}
void Output(Student Stu[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<Stu[i].ID<<' '<<Stu[i].DE<<' '<<Stu[i].CAI<<endl;
	}
}

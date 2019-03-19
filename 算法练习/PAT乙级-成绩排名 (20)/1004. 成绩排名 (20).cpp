/*读入n名学生的姓名、学号、成绩，分别输出成绩最高和成绩最低学生的姓名和学号。*/
#include<iostream>
#include<string>
using namespace std;
class Student
{

	public:
		Student(string m_name="未定义",string m_number="0000000000",int m_score=0):Name(m_name),Number(m_number),Score(m_score){}
		Student(const Student& stu){}
		~Student(){}
		void getname(string name)
		{
			Name=name;
		}
		string putname()
		{
			return Name;
		}
		void getnumber(string number)
		{
			Number=number;
		}
		string putnumber()
		{
			return Number;
		}
		void getscore(int score)
		{
			Score=score;
		}
		int putscore()
		{
			return Score;
		}
	//=====================================
	private:
		string Name;
		string Number;
		int Score;
};

void swap(Student *a,Student *b)
{
	Student temp;
	temp.getname(a->putname());
	temp.getnumber(a->putnumber());
	temp.getscore(a->putscore());
	a->getname(b->putname());
	a->getnumber(b->putnumber());
	a->getscore(b->putscore());
	b->getname(temp.putname());
	b->getnumber(temp.putnumber());
	b->getscore(temp.putscore());
	return;
}

void paixu(Student Stu[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(Stu[j].putscore()<Stu[j+1].putscore())
			{
				Student *a=&Stu[j];
				Student *b=&Stu[j+1];
				swap(a,b);
				a=NULL;
				b=NULL;
			}
		}
	}
}

int main()
{
	int n;
	cin>>n;
	Student Stu[n];
	for(int i=0;i<n;i++)
	{
		string name;
		cin>>name;
		Stu[i].getname(name);
		string number;
		cin>>number;
		Stu[i].getnumber(number);
		int score;
		cin>>score;
		Stu[i].getscore(score);
	}
	paixu(Stu,n);

	cout<<Stu[0].putname()<<" "<<Stu[0].putnumber()<<endl;
	cout<<Stu[n-1].putname()<<" "<<Stu[n-1].putnumber()<<endl;
	
	return 0;
}

/*卡拉兹(Callatz)猜想已经在1001中给出了描述。在这个题目里，情况稍微有些复杂。
当我们验证卡拉兹猜想的时候，为了避免重复计算，可以记录下递推过程中遇到的每一
个数。例如对n=3进行验证的时候，我们需要计算3、5、8、4、2、1，则当我们对n=5、8、
4、2进行验证的时候，就可以直接判定卡拉兹猜想的真伪，而不需要重复计算，因为这4个
数已经在验证3的时候遇到过了，我们称5、8、4、2是被3“覆盖”的数。我们称一个数列
中的某个数n为“关键数”，如果n不能被数列中的其他数字所覆盖。现在给定一系列待验
证的数字，我们只需要验证其中的几个关键数，就可以不必再重复验证余下的数字。你的
任务就是找出这些关键数字，并按从大到小的顺序输出它们。*/
/*#include<iostream>
using namespace std;
void paixu(int a[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-1-i;j++)
		{
			if(a[j]<a[j+1])
			{
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
		
	}
	return;
}

int main()
{
	int hero;
	int character[100];
	int member[100];
	cin>>hero;
	for(int i=0;i<hero;i++)
	{
		cin>>member[i];
	}
	int n=0;
	int temp1=hero;
	while(temp1!=1)
	{
		if(temp1%2==0)
		{
			temp1/=2;
			character[n]=temp1;
			n++;
		}
		else if(temp1%2!=0)
		{
			temp1=(3*temp1+1)/2;
			character[n]=temp1;
			n++;
		}
	}
	int m=0;
	int answer[100];
	for(int i=0;i<hero;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(character[j]==member[i])
			{
				break;
			}
			else if(j==hero-1)
			{
				answer[m]=member[i];
				m++;
			}
		}
	}
	paixu(answer,m);
	for(int i=0;i<m;i++)
	{
		if(i==m-1)
		{ 
			cout<<answer[i];
			break;
		}
		cout<<answer[i]<<" ";
	}
}
*/
//================================================================================
#include<iostream>
using namespace std;
class Member
{
	public:
		Member(int index=0,bool charge=true):m_index(index),m_charge(charge){}
		Member(const Member& Mem){}
		~Member(){}
		void getIndex(int a)
		{
			m_index=a;
		}
		int putIndex()
		{
			return m_index;
		}
		void pass()
		{
			m_charge=false;
		}
		bool charge()
		{
			return m_charge;
		}
	private:
		int m_index;
		bool m_charge;
};

void Select(Member character[],int n);
void output(int array[],int n);
void paixu(int array[],int n);

int main()
{
	int n;
	int m=0;
	int array[100];
	cin>>n;
	Member character[n];
	for(int i=0;i<n;i++)
	{
		int temp;
		cin>>temp;
		character[i].getIndex(temp);
	}
	Select(character,n);
	for(int i=0;i<n;i++)
	{
		if(character[i].charge())
		{
			array[m]=character[i].putIndex();
			m++;
		}
	}
	paixu(array,m);
	output(array,m);
	return 0;
}

void Select(Member character[],int n)
{
	for(int i=0;i<n;i++)
	{
		if(character[i].charge())
		{
			for(int j=0;j<n;j++)
			{	
				int temp=character[i].putIndex();
				while(temp!=1)
				{
					if(temp%2==0)
					{
						temp/=2;
						if(character[j].putIndex()==temp)
						{
							character[j].pass();
							break;
						}
					}
					else if(temp%2!=0)
					{
						temp=(temp*3+1)/2;
						if(character[j].putIndex()==temp)
						{
							character[j].pass();
							break;
						}
					}
				}
			}
		}
	}
}

void paixu(int array[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-1-i;j++)
		{
			if(array[j]<array[j+1])
			{
				int temp=array[j];
				array[j]=array[j+1];
				array[j+1]=temp;
			}
		}
	}
}

void output(int array[],int n)
{
	for(int i=0;i<n;i++)
	{
		if(i==n-1)
		{
			cout<<array[i];
			break;
		}
		cout<<array[i]<<" ";
	}
}
//===============================================================
/*
#include<iostream>  
#include<algorithm>  
using namespace std;  
int num[101];  
int mark[101]={0};  
int num2[101];  
bool cmp(int a,int b){  
     return a>b;  
     }  
void check(int number,int data){  
      int c[101];  
      int j=0;  
      while(data!=1){  
        if(data%2==0){  
           data=data/2;  
           c[j]=data;  
          }               
        else{  
             data=(data*3+1)/2;  
             c[j]=data;  
             }            
         j++;            }  
         for(int k=0;k<j;k++){  
              for(int d=0;d<number;d++){  
                      if(c[k]==num[d]){  
                         mark[d]=1;    
                         break;                 
                      }  
                    }     
                   
                 }   
        
      
    }  
  
int main(){  
    int n;  
    while(scanf("%d",&n)!=EOF){  
           for(int i=0;i<n;i++){  
                   scanf("%d",&num[i]);            
                   }   
          for(int i=0;i<n;i++){  
                  if(mark[i]!=1){  
                  check(n,num[i]);                                   
                  }  
              }   
          int cnt=0;  
          for(int i=0;i<n;i++){   
            if(mark[i]!=1){  
                num2[cnt++]=num[i];             
                           }  
          }  
          sort(num2,num2+cnt,cmp);  
            
          for(int i=0;i<cnt-1;i++)  
            printf("%d ",num2[i]);  
            printf("%d\n",num2[cnt-1]);    
              
              
              
              
            }  
      
  
    return 0;  
    }  */


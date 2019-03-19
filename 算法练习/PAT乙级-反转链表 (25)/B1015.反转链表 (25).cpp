#include<iostream>
#include<string>
#include<vector>
using namespace std;

int searchaddress(string address,vector<string> &a)
{
	for(int i=0;i<a.size();i++)
	{
		if(a[i]==address)
		{
			return i;
		}
	}
	cout<<endl<<"没有搜索到:"<<address<<endl;
}


int main()
{
	string FirstAddress;
	int sum;
	int Reverse;
	cin>>FirstAddress>>sum>>Reverse;
	cout<<"第一行输入完了"<<endl; 
	vector<string> Address;
	vector<int> Data;
	vector<string> NextNode;
	for(int i=0;i<sum;i++)
	{
		string *str=new string;
		int *data =new int;
		string *str2=new string;
		cin>>*str>>*data>>*str2;
		Address.push_back(*str);
		Data.push_back(*data);
		NextNode.push_back(*str2);
		delete str;
		delete data;
		delete str2;
		str=NULL;
		data=NULL;
		str2=NULL; 
	}

	string tempaddress=FirstAddress;
	int y=0;
	while(y<sum-1)
	{
		if(tempaddress==FirstAddress)
		{
			int *tempdata=new int;
			string *tempnext=new string;
			string *tempAddress=new string;
			*tempdata=Data[y];
			Data[y]=Data[searchaddress(tempaddress,Address)];
			Data[searchaddress(tempaddress,Address)]=*tempdata;
			delete tempdata;
			tempdata=NULL;
			*tempnext=NextNode[searchaddress(tempaddress,Address)];
			NextNode[searchaddress(tempaddress,Address)]=NextNode[y];
			NextNode[y]=*tempnext;
			delete tempnext;
			tempnext=NULL;
			*tempAddress=Address[searchaddress(FirstAddress,Address)];
			Address[searchaddress(FirstAddress,Address)]=Address[0];
			Address[0]=FirstAddress;
			delete tempAddress;
			tempAddress=NULL;
			tempaddress="WTF";
			for(int i=0;i<Address.size();i++)
			{
				cout<<endl<<Address[i]<<' '<<Data[i]<<' '<<NextNode[i]<<endl;
			}
		}
		else
		{
			cout<<"开始梳理"<<endl<<"下一个节点的索引值为"<<searchaddress(NextNode[y],Address)<<endl; 
			string *tempnext=new string;
			int *tempdata=new int;
			string *tempAddress=new string;
			*tempnext=NextNode[y+1];
			NextNode[y+1]=NextNode[searchaddress(NextNode[y],Address)];
			NextNode[searchaddress(NextNode[y],Address)]=*tempnext;
			delete tempnext;
			tempnext=NULL;
			//cout<<"下一地址交换完毕"<<endl;
			*tempdata=Data[y+1];
			Data[y+1]=Data[searchaddress(NextNode[y],Address)];
			Data[searchaddress(NextNode[y],Address)]=*tempdata;
			delete tempdata;
			tempdata=NULL;
			//cout<<"数据交换完毕"<<endl;
			*tempAddress=Address[y+1];
			Address[y+1]=NextNode[y];
			Address[searchaddress(NextNode[y],Address)]=*tempAddress;
			cout<<endl<<*tempAddress<<endl;
			delete tempAddress;
			tempAddress=NULL;
			cout<<"地址交换完毕"<<Address[searchaddress(NextNode[y],Address)]<<endl;
			y++;
			cout<<endl<<y<<endl; 
			for(int i=0;i<Address.size();i++)
			{
				cout<<endl<<Address[i]<<' '<<Data[i]<<' '<<NextNode[i]<<endl;
			}
			system("pause");
		}
	}
	for(int i=0;i<Address.size();i++)
	{
		cout<<Address[i]<<' '<<Data[i]<<' '<<NextNode[i]<<endl;
	}

	
	return 0;
}

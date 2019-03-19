#include<iostream>
//#include<stdlib.h>
using namespace std;
class Elevator{
	public:
		Elevator():TotalTime(0),Floor(0){};
		void Up(){
			TotalTime+=6;
			Floor++;
		}
		void Down(){
			TotalTime+=4;
			Floor--;
		}
		void To(int floor){
			if(Floor==floor)
				return;
			while(Floor!=floor){
				if(floor>Floor)
					Up();
				else
					Down();
			}
			TotalTime+=5;
		}
		void Show_Time(){
			cout<<TotalTime;
		}
	private:
		int TotalTime;
		int Floor;
};

/*typedef struct Node{
	int order;
	struct Node *next;
}LinkQueueNode;

typedef struct{
	LinkQueueNode *front;
	LinkQueueNode *rear;
}LinkQueue;

bool InitQueue(LinkQueue *Q){
	Q->front=(LinkQueueNode *)malloc(sizeof(LinkQueueNode));
	if(Q->front!=NULL){
		Q->rear=Q->front;
		Q->front->next=NULL;
		return true;
	}
	else
		return false;
}

bool EnterQueue(LinkQueue *Q,int order){
	LinkQueueNode *NewNode;
	NewNode=(LinkQueueNode *)malloc(sizeof(LinkQueueNode));
	NewNode->order=order;
	NewNode->next=NULL;
	Q->rear->next=NewNode;
	Q->rear=NewNode;
	return true;
}

bool DeleteQueue(LinkQueue *Q,int &order){
	LinkQueueNode *p;
	if(Q->front==Q->rear)
		return false;
	p=Q->front->next;
	Q->front->next=p->next;
	if(Q->rear==p)
		Q->rear=Q->front;
	order=p->order;
	free(p);
	return true;
}
*/
int main(){
	Elevator Ele;
	int n,temp;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>temp;
		Ele.To(temp);
	}
	Ele.Show_Time();
	return 0;
}

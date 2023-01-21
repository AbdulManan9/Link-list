#include<iostream>
using namespace std;
class Node
{
	public:
		int data;
		Node*next;
		Node*prev;
		Node(int data)
		{
			this->data=data;
			this->next=NULL;
			this->prev=NULL;
		}
};
void insertAtHead(Node*& head,int data)
{
	Node*temp=new Node(data);
	temp->next=head;
	head->prev=temp;
	head=temp;
}
void insertAtTail(Node*&tail,int data)
{
	Node*temp=new Node(data);
	tail->next=temp;
	temp->prev=tail;
	tail=temp;
}
void insertAtPosition(Node*&head,Node*&tail,int position,int data)
{
	if(position==1)
	{
		insertAtHead(head,data);
		return;
	}
	Node*temp=head;
	int cnt=1;
	while(cnt<position-1)
	{
		temp=temp->next;
		cnt++;
	}
	if(temp->next==NULL)
	{
		insertAtTail(tail,data);
		return;
	}
	Node*nodeToInsert=new Node(data);
	nodeToInsert->next=temp->next;
	temp->next->prev=nodeToInsert;
	temp->next=nodeToInsert;
	nodeToInsert->prev=temp;
}
void print(Node* head)
{
	Node*temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data;
		temp=temp->next;
	}
	cout<<endl;
}

int main()
{
	Node*node1=new Node(10);
	Node*head=node1;
	Node*tail=head;
	print(head);
	insertAtHead(head,12);
	print(head);
	insertAtHead(head,100);
	print(head);
	cout<<"Insertion from tal is"<<endl;
	insertAtTail(tail,12);
	print(head);
	cout<<"Insert At position is"<<endl;
	insertAtPosition(head,tail,4,900);
	print(head);
}

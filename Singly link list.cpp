#include<iostream>
using namespace std;
class Node
{
	public:
		int data;
		Node*next;
		Node(int data)
		{
			this->data=data;
			this->next=NULL;
		}
		~Node()
		{
			int value=this->data;
			if(this->next!=NULL)
			{
				delete next;
				this->next=NULL;
			}
			cout<<"MEMORY IS FREE WITH NODE WITH DATA "<<value<<endl;
		}
};
void insertionToHead(Node *&head,int data)
{
	Node*temp=new Node(data);
	temp->next=head;
	head=temp;
}
void insertToTail(Node*& tail,int data)
{
	Node*temp=new Node(data);
	tail->next=temp;
	tail=temp;
}
void insertToPosition(Node*&head,int position,int data)
{
		Node*temp=head;
	if(position==1)
	{
		insertionToHead(head,data);
		return;
	}

	int count=1;
	while(count<position-1);
	{
		temp=temp->next;
		count++;
	}
	Node*nodeToHead=new Node(data);
	nodeToHead->next=temp->next;
	temp->next=nodeToHead;
}
void deleteNode(Node*&head,int da)
{
	Node*prev=NULL;
	Node*temp=head;
	while(temp->next!=NULL)
	{
		prev=temp;
		temp=temp->next;
		if(temp->data==da)
		{
			prev->next=temp->next;
			delete temp;
		}
		
	}
}
void print(Node*&head)
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
	Node*node1=new Node(1);
	Node*head;
	head=node1;
	Node*tail;
	tail=head;
	print(head);
	insertionToHead(head,33);
	print(head);
	insertionToHead(head,22);
	print(head);
	insertToTail(tail,21);
	print(head);
	insertToTail(tail,31);
	print(head);
//	cout<<"Insertion at position is"<<endl;
//	insertToPosition(head,4,34);
//	print(head);
	cout<<"Enter data you can delete"<<endl;
	int d;
	cin>>d;
	deleteNode(head,d);     
	print(head);
}

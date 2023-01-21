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
			next=NULL;
		}
};

class List{
	private:
		Node *head;
	public:
			List()
			{
				head=NULL;
			}
			
			
};
void insertionAtHead(Node*& head,int data)
{
	Node* n=new Node(data);
	if(head=NULL)
	{
		n->next=n;
		n->next=NULL;
		head=n;
		return;
	}
	Node*temp=head;
	while(temp->next!=head)
	{
		temp=temp->next;
	}
	temp->next=n;
	n->next=head;
	head=n;
}
void insertAtTail(Node* &head,int data)
{
	if(head=NULL)
	{
		insertionAtHead(head,data);
		return;
	}
	Node*n=new Node(data);
	Node*temp=head;
	while(temp->next!=head){
		temp=temp->next;
	}
	temp->next=n;
	n->next=head;
}

void display(Node* &head)
{
	Node*temp=head;
	do{
		cout<<temp->data;
		temp=temp->next;
	}while(temp->next!=head);
	cout<<endl;
}
int main()
{
	Node*head=NULL;
	insertionAtHead(head,12);
	display(head);
}

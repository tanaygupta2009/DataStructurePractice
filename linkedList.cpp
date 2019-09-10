#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};
void print(Node *head)
{
	Node *temp = head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}
int main(int argc, char const *argv[])
{
	cout<<"Enter positive Elements , enter -1 to exit "<<endl;
	int n,k=0;
	Node *head , *temp;
	while(1)
	{
		cin>>n;
		if(n==-1)
			break;
		Node *t = new Node(n);
		if(k==0)
		{
			head = t;
			temp = t;
		}
		else
		{
			if(k==1)
			{
				head -> next = t;
				temp -> next = t;
				temp = temp ->next;
			}
			else
			{
				temp -> next = t;
				temp = temp -> next;
			}
		}
		k++;
	}
	print(head);
	return 0;
}
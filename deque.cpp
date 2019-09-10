#include<bits/stdc++.h>
using namespace std;
//Code is working fine, but it doesn't work properly with delRear , and getRear. Needs some fixes.
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
class Deque 
{
public:
	int size;
	Node *front , *rear;
	Deque()
	{
		this->front = NULL;
		this->rear = NULL;
		this->size = 0;
	}
	bool isEmpty()
	{
		return size==0;
	}
	int getSize()
	{
		return size;
	}
	void setFront(int n)
	{
		Node *d = new Node(n);
		if(front==NULL)
		{
			front = d;
			rear = d;
		}
		else
		{
			d->next = front;
			front = d;
		}
		size++;
	}
	void setRear(int n)
	{
		Node *d = new Node(n);
		if(rear==NULL)
		{
			front = d;
			rear = d;
		}
		else
		{
			rear->next = d;
			rear = d;
		}
		size++;
	}
	void delFront()
	{
		if(isEmpty())
		{
			cout<<"Queue is Empty"<<endl;
			return;
		}
		front = front->next;
		size--;
	}
	void delRear()
	{
		if(isEmpty())
		{
			cout<<"Queue is Empty"<<endl;
			return;
		}
		Node *temp = front;
		while(temp->next!=rear || temp!=rear)
		{
			temp = temp->next;
		}
		temp->next = NULL;
		rear = temp;
		size--;
	}
	int getFront()
	{
		if(isEmpty())
		{
			cout<<"Queue is Empty"<<endl;
			return -1;
		}
		return front->data;
	}
	int getRear()
	{
		if(isEmpty())
		{
			cout<<"Queue is Empty"<<endl;
			return -1;
		}
		return rear->data;
	}
};
int main(int argc, char const *argv[])
{
	Deque d;
	while(1)
	{
		cout<<"1.Insert @ Front | 2.Insert @ Rear | 3. Delete @ front | 4.Delete @ rear | 5.GetSize | 6.isEmpty() | 7.getFront() | 8.getRear() | 9. Exit."<<endl;		
		int x;
		cin>>x;
		switch(x)
		{
			case 1:
			{	
				int n;
				cout<<"Enter element: ";
				cin>>n;
				d.setFront(n);
				break;
			}
			case 2:
			{	
				int n;
				cout<<"Enter element: ";
				cin>>n;
				d.setRear(n);
				break;
			}
			case 3: d.delFront(); break;
			case 4: d.delRear(); break;
			case 5: cout<<d.getSize()<<endl; break;
			case 6: cout<<d.isEmpty()<<endl;break;
			case 7: cout<<d.getFront()<<endl;break;
			case 8: cout<<d.getRear()<<endl;break;
			case 9: exit(1);
			default: cout<<"Wrong Input , try again"<<endl;
		}
	}
	return 0;
}
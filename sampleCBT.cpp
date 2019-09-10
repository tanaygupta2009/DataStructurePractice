//Complete Binary Tree (CBT) 
#include<bits/stdc++.h>
using namespace std;
class CBT 
{
public:
	int data;
	CBT *left;
	CBT *right;
	CBT(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right =NULL;
	}
	~CBT() //destructor
	{
		delete left;
		delete right;
	}
};
void printInOrder(CBT *head)
{
	if(head == NULL)
		return;
	printInOrder(head->left);
	cout<<head->data<<" ";
	printInOrder(head->right);
}
/*
Generating Complete Binary tree using an array with childs located @ 2i+1 , 2i+2 , here , i = index of parent
parent of any child is located @ (i-1)/2; , here, i = index of child
*/
CBT* generateCBT(int *a , int size , int curr) 
{
	if(curr>(size-1))
		return NULL;
	CBT *head = new CBT(a[curr]);
	int first = (2*curr) + 1;
	int second = (2*curr) + 2;
	if(first>(size-1) || second > (size-1))
	{
		if(first>(size-1))
		{
			head->left = NULL;
			head->right =NULL;
		}
		else
		{
			head->left = new CBT(a[first]);
			head->right = NULL;
		}
		return head;
	}
	head->left = generateCBT(a,size,first);
	head->right = generateCBT(a,size,second);
	return head;
}
int main(int argc, char const *argv[])
{
	int nodes;
	cin>>nodes;
	int *a = new int[nodes];
	for(int i=0;i<nodes;i++)
		cin>>a[i];
	CBT *head = generateCBT(a,nodes,0);
	cout<<"InOrder Traversal: \n";
	printInOrder(head);
	cout<<endl;
	return 0;
}
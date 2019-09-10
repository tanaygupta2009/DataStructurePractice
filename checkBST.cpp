#include<bits/stdc++.h>
using namespace std;
#include"BinaryTreeNode.h"
int maximum(BinaryTreeNode<int>*root)
{
	if(root == NULL)
		return 0;
	return max(root->data , max(maximum(root->left) , maximum(root->right)));
}
int minimum(BinaryTreeNode<int>*root)
{
	if(root == NULL)
		return INT_MAX;
	return min(root->data , min(minimum(root->left) , minimum(root->right)));
}
bool isBST(BinaryTreeNode<int> *root)
{
	if(root==NULL)
		return true;
    if(((root->left==NULL) || (root->data > maximum(root->left)) && ((root->right==NULL) || (root->data <= minimum(root->right)))))
    	return isBST(root->left) && isBST(root->right);
    return false;
}
BinaryTreeNode<int> * takeInput()
{
	int rootData;
	cin>>rootData;
	if(rootData == -1)
		return NULL;
	BinaryTreeNode<int>*root  = new BinaryTreeNode<int>(rootData);
	BinaryTreeNode<int>*left = takeInput();
	BinaryTreeNode<int>*right = takeInput();
	root->left = left;
	root->right = right;
	return root;
}
queue<BinaryTreeNode<int>*>pendingNodes;
BinaryTreeNode<int>* takeInputLevelWise()
{
	int rootData;
	cin>>rootData;
	if(rootData == -1)
		return NULL;
	BinaryTreeNode<int>*root = new BinaryTreeNode<int>(rootData);
	pendingNodes.push(root);
	while(pendingNodes.size()!=0)
	{
		BinaryTreeNode<int>*front = pendingNodes.front();
		pendingNodes.pop();
		int left;
		cin>>left;
		if(left!=-1)
		{
			BinaryTreeNode<int>*leftNode = new BinaryTreeNode<int>(left);
			front->left = leftNode;
			pendingNodes.push(leftNode);
		}
		int right;
		cin>>right;
		if(right!=-1)
		{
			BinaryTreeNode<int>*rightNode = new BinaryTreeNode<int>(right);
			front->right = rightNode;
			pendingNodes.push(rightNode);
		}
	}
	return root;
}
BinaryTreeNode<int>* constructTree(int *input, int n) 
{
    int x;
	if(n%2==0)
		x = (n/2) - 1;
	else
		x = n/2;
    if(n==0)
        return 0;
	BinaryTreeNode<int>*root = new BinaryTreeNode<int>(input[x]);
    if(n==1)
        return root;
	BinaryTreeNode<int>*left = constructTree(input , x);   
	BinaryTreeNode<int>*right = constructTree(input + x + 1 , n - x -1);
	root->left = left;
	root->right = right;
	return root;
}
int main(int argc, char const *argv[])
{
	BinaryTreeNode<int>*root =  takeInputLevelWise();
	cout<<isBST(root)<<endl;
	return 0;
}
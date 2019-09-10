#include<iostream>
#include"BinaryTreeNode.h"
#include<queue>
using namespace std;
void printTree(BinaryTreeNode<int>*root)
{
	if(root == NULL)
		return;
	cout<<root->data<<": ";
	if(root->left!=NULL)
		cout<<root->left->data<<" ";
	if(root->right!=NULL)
		cout<<root->right->data<<" ";
	cout<<endl;
	printTree(root->left);
	printTree(root->right);
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
queue<BinaryTreeNode<int>*>rest;
void printLevelWise(BinaryTreeNode<int>*root)
{
	rest.push(root);
	while(rest.size()!=0)
	{
		BinaryTreeNode<int>*temp = rest.front();
		cout<<temp->data<<":";
		rest.pop();
		if(temp->left!=NULL)
		{
			cout<<"L:"<<temp->left->data<<",";
			rest.push(temp->left);
		}
		if(temp->left==NULL)
			cout<<"L:-1"<<",";
		if(temp->right!=NULL)
		{
			cout<<"R:"<<temp->right->data;
			rest.push(temp->right);
		}
		if(temp->right==NULL)
			cout<<"R:-1";
		cout<<endl;
	}
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
int countNodes(BinaryTreeNode<int>*root)
{
	if(root==NULL)
		return 0;
	return 1 + countNodes(root->left) + countNodes(root->right);
}
bool isNodePresent(BinaryTreeNode<int>*root , int x)
{
	if(root->left == NULL && root->right == NULL)
    {
        if(root->data == x)
            return true;
        return false;
    }
    if(root->left == NULL)
	{
		if(root->data == x)
			return true;
		return isNodePresent(root->right , x);
	}
    if(root->right == NULL)
	{
		if(root->data == x)
			return true;
		return isNodePresent(root->left , x);
	}
	return isNodePresent(root->left , x) || isNodePresent(root->right , x);
}
int height(BinaryTreeNode<int> *root) 
{
	if(root==NULL)
		return 0;
	//int n = 0;
	int l = height(root->left);
	int r = height(root->right);
	if(l>r)
		return 1 + l;
	return 1 + r;
}
void mirrorBinaryTree(BinaryTreeNode<int>* root) 
{
    if(root==NULL)
    	return;
    BinaryTreeNode<int>*temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);
}
int getRootIndex(int *inorder , int inLength , int rootData)
{
	for(int i=0;i<inLength;i++)
		if(inorder[i]==rootData)
			return i;
}
BinaryTreeNode<int>* buildTree(int *preorder, int preLenght, int *inorder, int inLength) 
{
	if(preLenght == 0 && inLength == 0)
        return 0;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(preorder[0]);
    int rootPos = getRootIndex(inorder , inLength , preorder[0]);
    root->left = buildTree(preorder+1 , rootPos , inorder , rootPos);
    root->right = buildTree(preorder+rootPos+1 , preLenght-1-rootPos , inorder+1+rootPos , inLength - 1 -rootPos);
    return root;
}
class PairAns {
public :
    int min;
    int max;
    PairAns()
    {
    	this->min = 999999;
    	this->max = 0;
    }
 };
PairAns minMax(BinaryTreeNode<int>*root)
{
	PairAns a;
    a.max = 0;
    a.min = 999999;
	if(root==NULL)
		return a;
	if(root->data > a.max)
		a.max = root->data;
	if(root->data < a.min)
		a.min = root->data;
	PairAns b = minMax(root->left);
	PairAns c = minMax(root->right);
    if(b.max > a.max || c.max > a.max)
    {
        if(b.max>c.max)
            a.max = b.max;
        else
            a.max = c.max;
    }
    if(b.min < a.min || c.min < a.min)
    {
        if(b.min<c.min)
            a.min = b.min;
        else
            a.min = c.min;
    }
	return a;
}
BinaryTreeNode<int>* searchInBST(BinaryTreeNode<int> *root , int k)
{
    if(root==NULL)
    	return 0;
    if(root->data == k)
    	return root;
    if(root->data > k)
    	return searchInBST(root->left,k);
    else
    	return searchInBST(root->right,k);
}
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
    //PairAns l = minMax(root->left);
    //PairAns r = minMax(root->right);
    if(((root->left==NULL) || (root->data > maximum(root->left)) && ((root->right==NULL) || (root->data <= minimum(root->right)))))
    	return isBST(root->left) && isBST(root->right);
    return false;
}
int main(int argc, char const *argv[])
{
	/*
	BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
	BinaryTreeNode<int> *left = new BinaryTreeNode<int>(2);
	BinaryTreeNode<int> *right = new BinaryTreeNode<int>(3);
	root->left = left;
	root->right = right;
	*/
	BinaryTreeNode<int>*root = takeInputLevelWise();
	printLevelWise(root);
	//cout<<height(root)<<endl;
	PairAns m = minMax(root);
	cout<<m.max<<" "<<m.min<<endl;
	return 0;
}
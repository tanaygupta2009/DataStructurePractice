//Code for inorder successor
#include<bits/stdc++.h>
using namespace std;
class Tree
{
public:
	int data;
	Tree *left;
	Tree *right;
	Tree(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};
Tree *takeInput()
{
	int rootData;
	cin>>rootData;
	if(rootData == -1)
		return NULL;
	Tree *root = new Tree(rootData);
	Tree *left = takeInput();
	Tree *right = takeInput();
	root->left = left;
	root->right = right;
	return root;
}
vector<int>v;
void printInOrderSuccessor(Tree *root)
{
	if(root == NULL)
		return;
	printInOrderSuccessor(root->left);
	v.push_back(root->data);
	//cout<<root->data<<" ";
	printInOrderSuccessor(root->right);
}
int main(int argc, char const *argv[])
{
	Tree *root = takeInput();
	int node;
	cin>>node;
	printInOrderSuccessor(root);
	for(int i=0;i<v.size()-1;i++)
		if(v[i] == node)
			cout<<v[i+1]<<endl;
	return 0;
}
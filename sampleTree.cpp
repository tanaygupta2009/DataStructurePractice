#include<iostream>
#include"Tree.h"
#include<queue>
//using namespace std;
int nodesGreaterThanX(Tree<int> *root, int x) 
{
	if(root==NULL)
		return 0;
	if(root->children.size()==0)
	{
		if(root->data > x)
			return 1;
		return 0;
	}   
	int n = 0;
	for(int i=0;i<root->children.size();i++)
	{
		if(root->children[i]->data > x)
			n++;
	}
	cout<<root->data<<" "<<n<<endl;
	for(int i=0;i<root->children.size();i++)
	{
		n = n + nodesGreaterThanX(root->children[i] , x);
	}
	
	return n;
}
bool containsX(Tree<int>* root, int x) 
{
    if(root==NULL)
        return false;
    if(root->children.size()==0)
    {
        if(root->data == x)
            return true;
        return false;
    }
    for(int i=0;i<root->children.size();i++)
    {
        if(root->children[i]->data == x)
            return true;
    }
    for(int i=0;i<root->children.size();i++)
    {
        if(containsX(root->children[i] , x))
            return true;
    }
    return false;
}
int getWholeSum(Tree<int>*root)
{
	int sum = root->data;
    for(int i=0;i<root->children.size();i++)
    	sum = sum + root->children[i]->data;
    return sum;
}
Tree<int>* maxSumNode(Tree<int> *root)
{
    if(root==NULL)
    	return 0;
    if(root->children.size()==0)
    	return root;
    int sum = getWholeSum(root);
    root->data = sum;
    Tree<int>*temp , *max;
    max = root;
    for(int i=0;i<root->children.size();i++)
    {
    	temp = maxSumNode(root->children[i]);
    	if(temp->data > root->data)
    		max = temp;
    }
    return temp;
}
void postOrder(Tree<int>*root)
{
	for(int i=0;i<root->children.size();i++)
		postOrder(root->children[i]);
	cout<<root->data<<endl;
}
void printAtLevelK(Tree<int>*root, int k)
{
	if(root==NULL)
		return;
	if(k==0)
	{
		cout<<root->data<<endl;
		return;
	}
	for(int i=0;i<root->children.size();i++)
		printAtLevelK(root->children[i] , k - 1);
}
int numLeafNodes(Tree<int>*root)
{
	if(root==NULL)
		return 0;
	if(root->children.size()==0)
		return 1;
	int num = 0;
	for(int i=0;i<root->children.size();i++)
	{
		if(root->children[i]->children.size()==0)
			num++;
		else
			num = num + numLeafNodes(root->children[i]);
	}
	return num;
}
int height(Tree<int>* root) 
{
    if(root==NULL)
    	return 0;
    if(root->children.size()==0)
    	return 1;
    int max=0;
    for(int i=0;i<root->children.size();i++)
    {	
    	int h=0;
    	h =  h + 1 + height(root->children[i]);
    	if(h>max)
    		max = h;
    }
    return max;
}
void takeInputLevelWise(Tree<int>*root)
{
	//cout<<"Enter Number of children for "<<root->data<<": ";
	int n;
	cin>>n;
	//if(n!=0)
	//	cout<<"Enter childs : "<<endl;
	for(int i=0;i<n;i++)
	{
		int temp;
		cin>>temp;
		Tree<int> *node = new Tree<int>(temp);
		root->children.push_back(node);
	}
	for(int i=0;i<root->children.size();i++)
		takeInputLevelWise(root->children[i]);
	return;
}
Tree<int>* takeInput()
{
	int rootData;
	//cout<<"Enter Data : ";
	cin>>rootData;
	Tree<int> *root = new Tree<int>(rootData);
	//cout<<"Enter Number of children for "<<root->data<<": ";
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{	
		//cout<<"Enter children of "<<root->data<<endl;
		root->children.push_back(takeInput());
	}
	return root;
}
void printTree(Tree <int>*node)
{
	if(node==NULL)
		return;
	cout<<"Node : "<<node->data<<"-> ";
	for(int i=0;i<node->children.size();i++)
		cout<<node->children[i]->data<<" ";
	cout<<endl;
	for(int i=0;i<node->children.size();i++)
		printTree(node->children[i]);
	return;
}
void printTreeLevelWise(Tree<int>*root)
{
	if (root==NULL) 
		return;
    queue < Tree<int>* > q;  
    q.push(root);
    while (!q.empty()) 
    { 
        int n = q.size(); 
        while (n > 0) 
        { 
            Tree<int>* p = q.front(); 
            q.pop(); 
            cout << p->data<<":";
            for (int i=0; i<p->children.size(); i++)
            { 
                q.push(p->children[i]);
                cout<<p->children[i]->data;
                if(i!=p->children.size()-1)
                	cout<<",";
            } 
            cout<<endl;
            n--; 
        } 
   	} 
    /*
    cout<<root->data<<":";
	for(int i=0;i<root->children.size();i++)
		cout<<root->children[i]->data<<",";
	cout<<endl;
	for(int i=0;i<root->children.size();i++)
		printTreeLevelWise(root->children[i]);
	*/
}
int countNodes(Tree<int>*root)
{
	if(root==NULL || root->children.size()==0)
		return 0;
	int size = 0;
	for(int i=0;i<root->children.size();i++)
		size=size+ 1 + countNodes(root->children[i]);
	return size;
}
int sumOfNodes(Tree<int>*root)
{
	if(root==NULL)
		return 0;
	if(root->children.size()==0)
		return root->data;
	int rootData = root->data;
	for(int i=0;i<root->children.size();i++)
		rootData+=sumOfNodes(root->children[i]);
	return rootData;
}
Tree<int>* maxDataNode(Tree<int>*root)
{
	if(root==NULL)
		return 0;
	Tree<int>*max = root;
	for(int i=0;i<root->children.size();i++)
	{
		if(root->children[i]->data>max->data)
			max = root->children[i];
	}
	Tree<int>*temp = max;
	for(int i=0;i<root->children.size();i++)
	{
		temp = maxDataNode(root->children[i]);
		if(temp->data > max->data)
			max = temp;
	}
	return max;
}
int main(int argc, char const *argv[])
{
	/*
	Tree<int> *root = new Tree<int>(0);
	Tree<int> *node1 = new Tree<int>(1);
	Tree<int> *node2 = new Tree<int>(2);
	Tree<int> *node3 = new Tree<int>(3);
	root->children.push_back(node1);
	root->children.push_back(node2);
	node2->children.push_back(node3);
	*/
	int rootData;
	cout<<"Enter Root Data : ";
	cin>>rootData;
	Tree<int> *root = new Tree<int>(rootData);
	takeInputLevelWise(root);
	//printTreeLevelWise(root);
	//cout<<sumOfNodes(root)<<endl;
	//cout<<maxDataNode(root)->data<<endl;
	//cout<<height(root)<<endl;
	//cout<<numLeafNodes(root)<<endl;
	//printAtLevelK(root,1);
	//cout<<endl;
	//postOrder(root);
	//cout<<maxSumNode(root)->data<<endl;
	cout<<nodesGreaterThanX(root,10)<<endl;
	//delete root;
	return 0;
}
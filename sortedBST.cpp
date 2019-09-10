#include <iostream>
#include <queue>
using namespace std;
template <typename T>
class Node{public:
    T data;
    Node<T> *next;
    Node(T data){
        this -> data = data;
        this -> next = NULL;
    }};
template <typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }};
BinaryTreeNode<int>* takeInput() {
    int rootData;
    //cout << "Enter root data : ";
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;
        //cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        //cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;}
Node<int>* constructBST(BinaryTreeNode<int>* root)
{
    if(root==NULL)
        return 0;
    Node<int>*link = new Node<int>(root->data);
    if(root->left!=NULL && root->right!=NULL)
    {
        cout<<"1st "<<root->data<<" "<<root->left->data<<" "<<root->right->data<<endl;
        Node<int>*left = constructBST(root->left);
        left->next = link;
        Node<int>*right = constructBST(root->right);
        link->next = right;
        return left;
    }
    else if(root->left==NULL)
    {
        cout<<"2nd"<<" "<<root->data<<endl;
        if(root->right==NULL)
            return link;
        else
        {
            cout<<"3rd "<<endl;
            Node<int>*right = constructBST(root->right);
            link->next = right;
            return link;
        }
    }
    else if(root->right==NULL)
    {
        cout<<"4th"<<endl;
        Node<int>*left = constructBST(root->left);
        left->next = link;
        return left;
    }
    return link;
}
int main() {
    BinaryTreeNode<int>* root = takeInput();
    Node<int>* head = constructBST(root);
    while(head != NULL) {
        cout << head -> data << " ";
        head = head -> next;
    }}

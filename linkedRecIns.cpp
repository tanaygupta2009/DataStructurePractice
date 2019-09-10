#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
 };

void insNode(Node *head , Node *temp , int i , int data)
{
    if(i==1)
    {
        Node *n = new Node(data);
        //cout<<temp->data<<endl;
        Node *t = temp->next;
        temp->next = n;
        n->next = t;
        return;
    }
    insNode(head, temp->next , i-1 , data);
}
Node* insertNodeRec(Node *head, int i, int data)
{
    if(i==0)
    {
        Node *n = new Node(data);
        n->next = head;
        head = n;
        return head;
    }
    Node *temp = head;
    //cout<<head->data<<" "<<i<<" "<<data<<endl;
    insNode(head,temp,i,data);
    return head;
}
Node* takeinput() {
    int data;
    cin >> data;
    Node* head = NULL, *tail = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL)                  {
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main() {
    Node *head = takeinput();
    int pos, data;
    cin >> pos >> data;
    head = insertNodeRec(head, pos, data);
    print(head);
    return 0;
}




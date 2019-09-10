//Append the last n elements of a linked list to the front
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node * next;
    node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};
node* takeinput()
{
    int data;
    cin>>data;
    node* head=NULL,*tail=NULL;
    while(data!=-1)
    {
        node *newnode=new node(data);
        if(head==NULL)
        {
            head=newnode;
            tail=newnode;
        }
        else
        {
            tail->next=newnode;
            tail=newnode;
        }
        cin>>data;
    }
    return head;
}
void print(node *head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int getLength(node *n)
{
    if(n->next == NULL)
        return 0;
    return 1 + getLength(n->next);
}
node* append_LinkedList(node* head,int n)
{
    if(n==0)
        return head;
    node* temp = head;
    int length = getLength(head);
    int front = length - n;
    for(int i=0;i<front;i++)
        temp = temp->next;
    node *temp2 = head;
    node *head2;
    head = temp->next;
    head2 = head;
    //cout<<head->data<<endl;
    temp->next = NULL;
    while(1)
    {   
        if(head->next==NULL)
            break;
        head = head->next;
    }
    head->next = temp2;
    head = head2;
    return head;
}
int main()
{
    node* head=takeinput();
    int n;
    cin>>n;
    head=append_LinkedList(head,n);
    print(head);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
class node{public:
    int data;
    node * next;
    node(int data)
    {
        this->data=data;
        this->next=NULL;
    }};
node* takeinput(){
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
    return head;}
void print(node *head){
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;}
node *reverse_linked_list_rec(node *head)
{
    node *current = head; 
    node *prev = NULL, *next = NULL; 


    while (current != NULL) 
    { 
        next = current->next; 
        current->next = prev; 
        prev = current; 
        current = next; 
    } 
    head = prev;    
    return head;
}
int main()
{
    node* head=takeinput();
    head= reverse_linked_list_rec(head);
    print(head);
    return 0;
}
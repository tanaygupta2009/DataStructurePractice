//merge sort recursive
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
node* mergeTwoLLs(node *head1, node *head2){
    node *combined , *head , *temp;
    if(head1->data <= head2->data)
    {
        combined = new node(head1->data);
        head1 = head1->next;
        head = combined;
        temp = combined;
    }
    else
    {
        combined = new node(head2->data);
        head2 = head2->next;
        head = combined;
        temp = combined;
    }
    while(1)
    {   
        //97087
        if(head1 == NULL)
        {
            if(head2==NULL)
                break;
            else
            {
                while(head2!=NULL)
                {
                    combined = new node(head2->data);
                    temp->next = combined;
                    temp = combined;
                    head2 = head2->next;
                }
                break;
            }
        }
        if(head2 == NULL)
        {
            if(head1 == NULL)
                break;
            else
            {
                while(head1!=NULL)
                { 
                    combined = new node(head1->data);
                    temp->next = combined;
                    temp = combined;
                    head1 = head1->next;
                }
                break;
            }
        }
        if(head1->data <= head2->data)
        {
            combined = new node(head1->data);
            head1 = head1->next;
            temp->next = combined;
            temp = combined;
        }
        else
        {
            combined = new node(head2->data);
            head2 = head2->next;
            temp->next = combined;
            temp = combined;
        }
    }   
    return head;     }
node* getMidPoint(node *head){
    node * slow = head;
    node * fast = slow->next;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;}
node* mergeSort(node *head)
{
    if(head->next == NULL)
        return head;
    node *mid = getMidPoint(head);
    node *second = mergeSort(mid->next);
    mid->next = NULL;
    node *first = mergeSort(head);
    node *final = mergeTwoLLs(first , second);
    return final;
}
int main(){
    node* head=takeinput();
    head= mergeSort(head);
    print(head);
    return 0;}


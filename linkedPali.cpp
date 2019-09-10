//Check if a linked list is a palindrome
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node * next;
    node(int data){
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
        else{
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
string print_linkedlist_spl(node*head)
{
    if(head->next == NULL)
    {
        //cout<<head->data<<" ";

        return to_string(head->data);
    }
    string s = print_linkedlist_spl(head->next);
    string final = s + to_string(head->data);
    return final;
}
bool check_palindrome(node* head)
{
    if(head->next==NULL)
        return head;
    string temp = print_linkedlist_spl(head);
    string s;
    while(head!=NULL)
    {
        s = s + to_string(head->data);
        head=head->next;
    }
    return (temp==s);
}
int main()
{
    node*head=takeinput();
    bool ans=check_palindrome(head);
    if(ans)
        cout<<"true"<<endl;
    else 
        cout << "false"<<endl;
    return 0;
}

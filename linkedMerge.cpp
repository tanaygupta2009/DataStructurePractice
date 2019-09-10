#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this -> data = data;
        this -> next = NULL;
    }
};
Node* takeinput()
{
    int data;
    cin >> data;
    Node* head = NULL, *tail = NULL;
    while(data != -1)
    {
        Node *newNode = new Node(data);
        if(head == NULL)                  
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail -> next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head) 
{
    Node *temp = head;
    while(temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}
Node* mergeTwoLLs(Node *head1, Node *head2)
{
    Node *combined , *head , *temp;
    if(head1->data <= head2->data)
    {
        combined = new Node(head1->data);
        head1 = head1->next;
        head = combined;
        temp = combined;
    }
    else
    {
        combined = new Node(head2->data);
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
                    combined = new Node(head2->data);
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
                    combined = new Node(head1->data);
                    temp->next = combined;
                    temp = combined;
                    head1 = head1->next;
                }
                break;
            }
        }
        if(head1->data <= head2->data)
        {
            combined = new Node(head1->data);
            head1 = head1->next;
            temp->next = combined;
            temp = combined;
        }
        else
        {
            combined = new Node(head2->data);
            head2 = head2->next;
            temp->next = combined;
            temp = combined;
        }
    }   
    return head;     
}
int main()
{
    Node *head1 = takeinput();
    Node *head2 = takeinput();
    Node *head3 = mergeTwoLLs(head1, head2);
    print(head3);
    return 0;
}


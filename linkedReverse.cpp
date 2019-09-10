void print_linkedlist_spl(node*head)
{
    if(head->next == NULL)
    {
        cout<<head->data<<" ";
        return;
    }
    print_linkedlist_spl(head->next);
    cout<<head->data<<" ";
}
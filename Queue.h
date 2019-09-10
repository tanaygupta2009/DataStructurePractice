template<typename T>
class Queue 
{
private:
    int size;
    Node <T> *head;
    Node <T> *curr;
public :
    Queue() 
    {
        this->size=0;
        this->head = NULL;
        this->curr  = NULL;
    }
    void enqueue(T data) 
    {
        Node<T> *temp = new Node<T>(data);
        if(head == NULL)
        {
            head = temp;
            curr = temp;
        }
        else
        {   
            if(head->next == NULL)
            {
                head->next = temp;
                curr = temp;
            }
            else
            {
                curr->next = temp;
                curr = temp;
            }
        }
        size++;
    }
    int getSize() 
    {
        return size;
    }
    bool isEmpty() 
    {
        return size==0;
    }
    T dequeue() 
    {
        // Return 0 if queue is empty
        if(isEmpty())
            return 0;
        int n = head->data;
        head = head->next;
        size--;
        return n;
    }
    T front()  
    {
        // Return 0 if queue is empty
        if(isEmpty())
            return 0;
        return head->data;
    }
};

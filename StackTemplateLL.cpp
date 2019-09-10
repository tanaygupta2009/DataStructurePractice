template <typename T>
class Node
{
public :
    T data;
    Node<T> *next;
    
    Node(T data) {
        this -> data = data;
        next = NULL;
    }
};
template <typename T>
class StackTemplateLL 
{
    Node<T> *head;
    int size;
    
public :
    
    StackTemplateLL() 
    {
        this->head = NULL;
        this->size = 0;
    }
    int getSize() 
    {
        return size;
    }
    bool isEmpty() 
    {
        return head==NULL;
    }
    void push(T element) 
    {
    	Node<T> *n = new Node<T>(element);
    	if(head==NULL)
    		head = n;
    	else
    	{
    		n->next = head;
    		head = n;
    	}
    	size++;
    }
    T pop()
    {
        // Return 0 if stack is empty. Don't display any other message
        if(isEmpty())
        	return 0;
        int temp= head->data;
        head = head->next;
        size--;
        return temp;
    }
    T top() 
    {
        // Return 0 if stack is empty. Don't display any other message
        if(isEmpty())
        	return 0;
        return head->data;
    }
};
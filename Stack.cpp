class Stack
{
private:
	int *arr;
	int index=0;
	int capacity;
public:
	Stack()
	{
		arr = new int[4];
		this->capacity = 4;
	}
	bool isEmpty()
	{
		return index==0;
	}
	void push(int n)
	{
		if(index == capacity)
		{
			int *newData = new int[capacity*2];
			int i;
			for(i=0;i<capacity;i++)
				newData[i] = arr[i];
			newData[i] = n;
			arr = newData;
			index++;
			capacity = capacity*2;
		}
		else
		{
			*(arr+index) = n;
			index++;
		}
	}
	void pop()
	{
		if(!isEmpty())
			index--;
		else
		{
			cout<<"Array is Empty! Can't pop!"<<endl;
			return;
		}
	}
	string top()
	{
		if(isEmpty())
		{
			return "Array is Empty!";
		}
		return to_string(*(arr+index-1));
	}
	int size()
	{
		return index;
	}
};
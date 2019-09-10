#include<bits/stdc++.h>
using namespace std;
#include"StackTemplate.cpp"
int main(int argc, char const *argv[])
{
	StackTemplate<int>s;
	while(1)
	{
		cout<<"1 . Push | 2. Pop | 3. Top Element | 4 . isEmpty() | 5. size | 6. Exit"<<endl;
		int x;
		cin>>x;
		switch(x)
		{
			case 1: 
			{
				cout<<"Enter Element: ";
				int n;
				cin>>n;
				s.push(n);
				break;
			}
			case 2:
			{
				s.pop();
				break;
			}
			case 3:
			{
				cout<<s.top()<<endl;
				break;
			}
			case 4:
			{
				if(s.isEmpty())
					cout<<"Stack is Empty"<<endl;
				else
					cout<<"Stack is not Empty"<<endl;
				break;
			}
			case 5:
			{
				cout<<s.size()<<endl;
				break;
			}
			case 6: cout<<"Exiting\n"<<endl; exit(1); break;
			default : cout<<"Wrong input, try again"<<endl;	
		}
	}
}
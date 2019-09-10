#include<iostream>
using namespace std;

int main()
{	
	//trying to change the constant integer 'b' by accessing its address manually.
	int a = 10;
	const int b = 12;
	int *p = (int *)0x60fe84; //change this to actual address of b(can be obtained by cout<<&b;)
	(*p)--; // altering the variable stored in location 
	cout<<*p<<" "<<&b<<endl; // variable successfully changed   
	cout<<b<<endl; // but 'b' is still the same.... HOW?????? (*p is changed, but 'b' is still same..howtf?) 
}
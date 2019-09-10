#include<iostream>
using namespace std;
int stringToNumber(char input[]) 
{
    return atoi(input);
}
int main() 
{
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}
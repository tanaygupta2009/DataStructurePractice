#include<bits/stdc++.h>
using namespace std;
char* getFinalString(char *s , long long size , long long toRemove)
{
	cout<<s<<" "<<toRemove<<endl;
	if(toRemove==0)
		return s;
	if(s[0]<=s[size-1])
		return getFinalString(s+1,size-1,toRemove-1);
	s[size-1]='\0';
	return getFinalString(s,size-1,toRemove-1);
}
long long getFinalNum(char *s , long long size , long long start , long long end, long long sum)
{
	//cout<<start<<" "<<end<<" "<<sum + (s[end] - '0')<<endl;
	if(end == (size - 1))
		return sum + (s[end]-'0');
	return max(sum + (s[end]-'0') , getFinalNum(s , size , start+1 , end+1 , sum - (s[start]-'0') + (s[end]-'0')));
}
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	int p = 0;
	while(t--)
	{
		long long n;
		cin>>n;
		char *s = new char[n];
		cin>>s;
		long long subLength = n - (n/2);
		long long sum = 0;
		/*
		long long toRemove = n/2;
		char *temp = getFinalString(s,n,toRemove);
		//cout<<temp<<endl;
		long long sum = 0;
		for(long long i=0;i<strlen(temp);i++)
			sum = sum + (temp[i] - '0');
		*/
		for(long long i=0;i<subLength-1;i++)
			sum = sum + (s[i] - '0');
		sum = getFinalNum(s,n,0,subLength-1,sum);
		cout<<"Case #"<<p+1<<": "<<sum<<endl;
		p++;
	}
	return 0;
}
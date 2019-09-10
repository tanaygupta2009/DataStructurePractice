#include<bits/stdc++.h>
using namespace std;
string getCombinedString(int a)
{
	string s = "";
	while(a>0)
	{
		int mod = a%10;
		if(mod==1)
			s = "" + s;
		else
			if(mod==2)
				s = "abc" + s;
			else 
				if(mod == 3)
					s = "def" + s;
				else
					if(mod == 4)
						s = "ghi" + s;
					else
						if(mod==5)
							s = "jkl" + s;
						else
							if(mod==6)
								s = "mno" + s;
							else
								if(mod==7)
									s = "pqrs" + s;
								else
									if(mod==8)
										s = "tuv" + s;
									else
										if(mod==9)
											s = "wxyz" + s;
										else
											s = "" + s;
		a=a/10;
	}
	return s;
}
int getLength(int a)
{	
	int count=0;
	while(a>0)
	{
		int mod = a%10;
		if(mod==2 || mod==3 ||mod==4 || mod==5 ||mod==6 || mod==8)
			count+=3;
		else
		{
			if(mod==7 || mod==9)
				count+=4;
			else
				if(mod==1)
					count+=0;
				else
					count+=0;
		}
		a=a/10;
	}
	return count;
}
int getLengthString(string *output)
{
	int i=0;
	while(output[i]!="\0")
		++i;
	return i;
}
int keypad(int n, string *output)
{
	if(n<=0)
	{
		output[0]= '\0';
		return 1;
	}	
	int mod = n % 10;
	if(mod==1 || mod==0)
	{
		for(int i=0 ; i <getLengthString(output) ; i++)
			output[i]='\0';
	}
	else
	{
		string s = getCombinedString(mod);
		//cout<<n<<" "<<mod<<" "<<s<<endl;
		int num = keypad(n/10 , output);
		int numberOfCopies = s.size()-1;
		int length = getLengthString(output);
		int k=length;
		//cout<<length<<" "<<numberOfCopies<<" "<<s<<" "<<n<<endl;
		cout<<num<<" "<<length<<endl;
		for(int i=0;i<numberOfCopies;i++)
		{
			for(int j=0 ; j<length;j++)
			{
				output[k] = output[j] + s[i+1];
				k++;
			}
		}
		for(int i=0;i<length;i++)
			output[i] = output[i] + s[0];
	}
	return getLengthString(output);
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	string *output = new string[1000];
	int num = keypad(n,output);
	//cout<<num<<endl;
	for(int i=0;i<num;i++)
		cout<<output[i]<<" ";
	cout<<endl;
	return 0;
}
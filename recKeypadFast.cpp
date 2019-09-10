#include <bits/stdc++.h>
using namespace std;
string getCombinedString(int a){
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
	return s;}
void printCombo(int num , string output)
{
	if(num==0)
	{
		cout<<output<<" ";
		return;
	}
	string s = getCombinedString(num%10);
	for(int i=0 ; i<s.size() ; i++)
		printCombo(num/10 , output + s[i]);
}
void printKeypad(int num)
{
	printCombo(num , "");    
}
int main()
{
	int num;
	cin >> num;
	printKeypad(num);
	return 0;
}
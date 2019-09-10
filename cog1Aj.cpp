#include <bits/stdc++.h>
using namespace std;
string counter(string s)
{
    string str;
    int cnt=1;
    if(s.length()==1)
    {              //for length 1
        str = str+s[0];
        return str;
    }
    for(int i=1;i<s.length();i++)
    {  //for big length
        if(s[i-1]!=s[i])
        {
            if(cnt>1)
            {
                str = str + s[i-1];
                stringstream t;
                t<<cnt;
                string c;
                t>>c;
                str = str+c;
                cnt=1;
            }
            else
                str = str + s[i-1];
        }
        else
            cnt++;
    }
    if(cnt>1)
    {
        str = str + s[s.length()-1];
        stringstream t;
        t<<cnt;
        string c;
        t>>c;
        str = str+c;
        cnt=1;
    }
    return str;
}

int main() {
	string s;
	cin>>s;
	string h = counter(s);
	cout<<h;
	return 0;
}
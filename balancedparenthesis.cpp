#include <bits/stdc++.h>
using namespace std;

bool balanced(char s, stack<char> st)
{
    if(st.top()=='(' && s==')')
    return true;
    if(st.top()=='{' && s=='}')
    return true;
    if(st.top()=='[' && s==']')
    return true;

    return false;
}
int main() {
	//code
	int t;
	cin>>t;
	cin.ignore();
	while(t--)
	{
	    string s;
	    getline(cin,s);
	    int n=s.length();

	    stack<char> st;
	    int k=0;
	    for(int i=0;i<n;i++)
	    {
	        if(s[i]=='(' || s[i]=='{' || s[i]=='[')
	        {
	            st.push(s[i]);
	        }
	        else if(s[i]==')' || s[i]=='}' || s[i]==']')
	        {
	            if(st.empty())
	            {
	                k=1;
	                break;
	            }
	            else if(balanced(s[i], st))
	            st.pop();
	            else
	            {
	                k=1;
	                break;
	            }

	        }
	        if(k==1)
	        break;
	    }
	    if(st.empty() && k==0)
	    cout<<"balanced"<<endl;
	    else
	    cout<<"not balanced"<<endl;
	}
	return 0;
}

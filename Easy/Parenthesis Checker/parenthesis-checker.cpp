//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        int n=x.length();
        if(n%2!=0)
            return false;
        stack<char> s;
        if(x[0]=='{' || x[0]=='[' || x[0]=='(')
        {
            s.push(x[0]);
        }
        else
            return false;
        for(int i=1;i<n;i++)
        {
            if(x[i]=='{' || x[i]=='[' || x[i]=='(')
                s.push(x[i]);
            else
            {
                if(s.empty())
                    return false;
                char top=s.top();
                if((top=='{' && x[i]=='}') || (top=='(' && x[i]==')') || (top=='[' && x[i]==']'))
                {
                    s.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends
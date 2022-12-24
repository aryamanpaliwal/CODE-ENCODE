//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

/*
str: string in which pattern we have to find pattern.
text: pattern needs to searched.
*/

bool searchPattern(string str, string pat)
{
    // your code here
    int n=str.length();
    int pn=pat.length();
    for(int i=0;i<n;i++)
    {
        if(str[i]==pat[0])
        {
            bool flag=true;
            int x=0;
            int y=i;
            while(x<pn)
            {
                if(pat[x]!=str[y])
                {
                    flag=false;
                    break;
                }
                x++;
                y++;
            }
            if(flag)
                return true;
        }
    }
    return false;
}



//{ Driver Code Starts.
int main()
{
    int t; cin>>t;
    
    while(t--)
    {
        string str, pat;
        cin>>str;
        cin>>pat;
        
        if(searchPattern(str, pat) == true)
            cout << "Present" <<endl;
        else cout << "Not present" <<endl;
    }
}


// } Driver Code Ends
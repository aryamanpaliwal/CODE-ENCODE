//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string longestPalindrome(string s){
        // code here 
        string temp="";
        int len=0;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            int l=i,r=i;
            while(l>=0 && r<n && s[l]==s[r])
            {
                if((r-l+1)>len)
                {
                    len=r-l+1;
                    temp=s.substr(l, len);
                }
                l--;
                r++;
            }
            l=i;
            r=i+1;
            while(l>=0 && r<n && s[l]==s[r])
            {
                if((r-l+1)>len)
                {
                    len=r-l+1;
                    temp=s.substr(l, len);
                }
                l--;
                r++;
            }
        }
        return temp;
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.longestPalindrome(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends
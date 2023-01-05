//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
// int maxArea(int A[], int len);

// } Driver Code Ends
//User function template for C++

long long maxArea(long long height[], int n)
{
    // Your code goes here
    long long area=0;
    long long l=0;
    long long h=n-1;
    while(l<h)
    {
        area=max(area,(h-l)*min(height[l],height[h]));
        if(height[l]<height[h])
        {
            l++;
        }
        else if(height[l]>height[h])
        {
            h--;
        }
        else
        {
            l++;h--;
        }
    }
    return area;
}

//{ Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<maxArea(arr,n)<<endl;
    }
return 0;
}

// } Driver Code Ends
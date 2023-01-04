//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minLaptops(int N, int start[], int end[]) {
        sort(start, start+N);
        sort(end, end+N);
        int res=1;
        int s=1;
        int e=0;
        while(e<s && s<N)
        {
            if(start[s]<end[e])
            {
                res++;
                s++;
            }
            else
            {
                s++;
                e++;
            }
        }
        return res;
        
        
        // Code here
        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // for(int i=0;i<N;i++)
        // {
        //     pq.push({end[i], start[i]});
        // }
        // int prev_s=pq.top().second;
        // int prev_e=pq.top().first;
        // pq.pop();
        // int res=1;
        // while(pq.empty()==false)
        // {
        //     int curr_s=pq.top().second;
        //     int curr_e=pq.top().first;
        //     pq.pop();
        //     if(curr_s>=prev_e)
        //     {
        //         prev_e=curr_e;
        //     }
        //     else
        //     {
        //         res++;
        //         prev_e=curr_e;
        //     }
        // }
        // return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int start[N], end[N];
        for(int i=0; i<N; i++)
            cin>>start[i];
        for(int i=0; i<N; i++)
            cin>>end[i];
            
        Solution ob;
        cout << ob.minLaptops(N, start, end) << endl;
    }
}
// } Driver Code Ends
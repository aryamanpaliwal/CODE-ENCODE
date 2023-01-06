//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void solve2(vector<vector<int>> &res, vector<int> temp, int k, int sum, int index, int curr_num)
    {
        if(sum == 0 && k == 0)
        {
            res.push_back(temp);
            return;
        }
        if(sum<=0 || k<=0)
        {
            return;
        }
        for(int num=curr_num; num<=9; num++)
        {
            temp[index]=num;
            solve2(res, temp, k-1, sum-num, index+1, num+1);
        }
    }
    vector<vector<int>> combinationSum(int k, int n) {
        // code here
        vector<vector<int>> res;
        // vector<int> temp;
        // solve(res, temp, 0, 1, n, k, 0);
        vector<int> temp(k);
        solve2(res, temp, k, n, 0, 1);
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K >> N;

        Solution obj;
        vector<vector<int>> ans = obj.combinationSum(K, N);
        sort(ans.begin(), ans.end());
        for (auto &arr : ans) {
            for (auto it : arr) cout << it << ' ';
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:

    static bool cmp(pair<int, pair<int, int>>& a, pair<int, pair<int, int>>& b) {
        return a.second.second < b.second.second;
    }

    vector<int> maxMeetings(int N, vector<int>& S, vector<int>& F) {
        if (N == 1) return {1};
        vector<pair<int, pair<int, int>>> meet;
        for (int i = 0; i < N; i++) {
            int idx = i + 1;
            meet.push_back({idx, make_pair(S[i], F[i])});
        }
        sort(meet.begin(), meet.end(), cmp);
        vector<int> ans;
        ans.push_back(meet[0].first);
        int already = meet[0].second.second;
        for (int i = 1; i < N; i++) {
            if (meet[i].second.first > already) {
                ans.push_back(meet[i].first);
                already = meet[i].second.second;
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
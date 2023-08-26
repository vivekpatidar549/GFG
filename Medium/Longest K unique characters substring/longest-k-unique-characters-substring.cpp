//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
    unordered_map <char,int> mp;
        queue <char> q;
        int ans = 0 ;
        int unique_in_substring = 0;
        
        for(int i = 0 ;i<s.size();i++)
        {
            q.push(s[i]);
            mp[s[i]]++;
            
            if(mp[s[i]] == 1)
            unique_in_substring++;
            
            while(unique_in_substring > k )
            {
                char ch = q.front();
                mp[ch]--;
                
                if(mp[ch] ==0 )
                unique_in_substring--;
                
                q.pop();
                
            }
            
            if(unique_in_substring == k and ans < q.size())
            {
                ans = q.size();
            }
        }
        
        if(ans == 0)return -1;
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here   
        unordered_set<char>sets;
        for(int i=0;i<str.size();i++) sets.insert(str[i]);
        unordered_map<char,int>maps;
        int size=INT_MAX;
        int idx=0;
        for(int i=0;i<str.size();i++){
            maps[str[i]]++;
            while(maps.size()==sets.size() && idx<=i){
                size=min(size,i-idx+1);
                maps[str[idx]]--;
                if(maps[str[idx]]<=0) maps.erase(str[idx]);
                idx++;
            }
        }
        return size;
        
    }
};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends
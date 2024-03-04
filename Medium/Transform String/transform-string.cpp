//{ Driver Code Starts
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int transform (string A, string B)
    {
        //code here.
        if(A.size()!=B.size()) return -1;
        unordered_map<char,int>map1;
        int count=0;
        unordered_map<char,int>map2;
        for(int i=0;i<A.size();i++) map1[A[i]]++;
        for(int i=0;i<B.size();i++) map2[B[i]]++;
        for(auto it:map1){
            if(it.second!=map2[it.first]) return -1;
        }
        int i=A.size()-1;
        int j=B.size()-1;
        while(i>=0 && j>=0){
            if(A[i]!=B[j]){
                i--;
                count++;
            }
            else{
                i--;
                j--;
            }
        }
        return count;
    }
};


//{ Driver Code Starts.

int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution ob;
        cout <<ob.transform (A, B) << endl;
    }
}
// } Driver Code Ends
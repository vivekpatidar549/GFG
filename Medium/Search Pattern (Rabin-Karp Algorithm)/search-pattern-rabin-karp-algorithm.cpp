//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pattern, string text)
        {
            //code here.
            const int p = 31; // base
            const int m = 1e9 + 7;  // modulus
            
            int pat = pattern.size(), txt = text.size();  // storing the sizes of the string 
            
            vector<long long> p_pow(max(pat, txt));  // to store the power of the base
            p_pow[0] = 1;
            for(int i = 1; i < (int)p_pow.size(); i++)
                p_pow[i] = (p_pow[i - 1] * p) % m;    // calculating the power of base for every i
                
            vector<long long> hash_txt(txt + 1, 0); // calculating the hashes for text string first
            for(int i = 0; i < txt; i++)
                hash_txt[i + 1] = (hash_txt[i] + (text[i] - 'a' + 1) * p_pow[i]) % m;
            
            long long hash_pat = 0;   // calculating hashes for pattern string
            for(int i = 0; i < pat; i++)
                hash_pat = (hash_pat + (pattern[i] - 'a' + 1) * p_pow[i]) % m;
                
            vector<int> occurences;  // ans vector
            for(int i = 0; i + pat - 1 < txt; i++) {
                long long cur_hash = (hash_txt[i + pat] - hash_txt[i] + m) % m;  // + m is to balance the term 
                                                                                 // if value becomes negative
                if(cur_hash == hash_pat * p_pow[i] % m)
                    occurences.push_back(i + 1);
            }
            
            return occurences;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends
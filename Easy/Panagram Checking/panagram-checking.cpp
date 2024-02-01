//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to check if a string is Pangram or not.
    bool checkPangram (string s) 
{
    map<char,int> mp;
    for(int i=0;i<s.size();i++)
    {
       if(s[i]>=97 && s[i]<=122) mp[s[i]]++;
       if(s[i]>=65 && s[i]<=90) mp[(s[i]+32)]++;
    }
    return mp.size()==26;
}

};

//{ Driver Code Starts.

// Driver Program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--){
        string s;
        getline(cin, s);
        Solution obj;
        if (obj.checkPangram(s) == true)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return(0);
}

// } Driver Code Ends
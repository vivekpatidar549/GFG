//{ Driver Code Starts
//Initial Template for C++

// CPP program for implementation of efficient 
// approach to find length of last word 
#include <bits/stdc++.h> 
using namespace std; 

int findLength(string s);

// Driver code 
int main() 
{ 
	int t;
	cin>>t;
	t+=1;
	bool flag = false;
	while(t--){
	    string s;
	    getline(cin,s);
	    if(!flag){
	        flag = true;
	        continue;
	    }
	    cout<<findLength(s)<<endl;
	}
	return 0;
} 

// } Driver Code Ends


//User function Template for C++

int findLength(string s){
    //code
    
    int n=s.length();
        int i=n-1;
        int count=0;
        //ignoring last spaces
        if(n==1 && s[i] !=' ') return 1;
        if(n==1 && s[i] ==' ') return 0;
        while(i>=0 &&s[i]==' '){
            i--;
        }
        while(i>=0 && s[i]!=' '){
            count=count+1;
            i--;
        }
        return count;
    
}
//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{ 
    vector<bool> prime;
public:
    Solution(){
        prime.resize(10001, true);
        for(int p = 2; p*p<=10001; p++)
        {
            if(prime[p])
            {
                for(int i = p*p; i<=10001; i+=p)
                {
                    prime[i] = false;
                }
            }
        }
    }
    
    int bfs(int a, int b)
    {
        vector<int> ans(10001, -1);
        
        ans[a] = 0;
        queue<int> q;
        q.push(a);
        while(!q.empty())
        {
            int p = q.front();
            q.pop();
            if(p==b)break;
            string nxt = to_string(p);
            for(int i = 0; i<4; i++)
            {
                for(char c = '0'; c<='9'; c++)
                {
                    if(c==nxt[i] || (i==0 &&c=='0'))continue;
                    string next = nxt;
                    next[i] = c;
                    int t = stoi(next);
                    if(ans[t]==-1 && prime[t])
                    {
                        q.push(t);
                        ans[t] = ans[p]+1;
                    }
                }
            }
        }
        
        return ans[b];
    }
    int solve(int num1,int num2)
    {   
      //code here
      return bfs(num1, num2);
    }
};

//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int num1,num2;
      cin>>num1>>num2;
      Solution obj;
      int answer=obj.solve(num1,num2);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends
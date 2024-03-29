//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       vector<int>ans(n,0);
       stack<pair<int,int>>s;
       int count=0;
       for(int i=0;i<n;i++){
           count=1;
           if(s.empty()){
               s.push({price[i],count});
               ans[i]=count;
           }
           else if(s.top().first>price[i]){
               s.push({price[i],count});
               ans[i]=count;
           }
           else{
               while(!s.empty() && s.top().first<=price[i]){
                   count+=s.top().second;
                   s.pop();
               }
               s.push({price[i],count});
               ans[i]=count;
           }
           
       }
       return ans;
    }
};



//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    long long divide(long long dividend, long long divisor) 
    {
        //code here
        if(dividend==divisor){
            return 1;
        }
        bool isPositive=(dividend<0 == divisor<0);
       long long a = abs(dividend);
        long long int b = abs(divisor);
        long long ans = 0;
        while(a>=b){
            int q=0;
            while(a>(b<<(q+1))){
                q++;
            }
            ans+=(1<<q);
            a-=(b<<q);
        }
        return isPositive ? ans : -ans;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin >> t;

	while (t--)
	{

		long long a, b;
		cin >> a >> b;
		
		Solution ob;
		cout << ob.divide(a, b) << "\n";
	}

	return 0;
}

// } Driver Code Ends
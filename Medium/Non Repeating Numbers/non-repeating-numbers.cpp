//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        int n=nums.size();
        vector<int>ans;
        int result=0;
        for(int i=0;i<n;i++){
            result ^=nums[i];
        }
        // getting at what index my first bit is set bit
        int rightmostset=result & -result;

        int temp=result;
        for(int i=0;i<n;i++){
            if(nums[i]&rightmostset){
                temp^=nums[i];
            }
        }
        result^=temp;
        if(result>temp){
            ans.push_back(temp);
            ans.push_back(result);
        }
        else{
            ans.push_back(result);
            ans.push_back(temp);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends
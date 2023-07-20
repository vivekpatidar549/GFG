//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++

class node{
    public : 
    int data;
    int row;
    int col;
    node(int val , int row, int col){
        this->data=val;
        this->row=row;
        this->col=col;
    }
};
class compare{
    public:
    bool operator()(node*a, node*b){
        return a->data > b->data;
    }

};

class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
       priority_queue<node* , vector<node*> , compare> pq;
    vector<int> ans;
    // push first element of all k array in pq;
    for(int i=0;i<K;i++){
        node * temp= new node(arr[i][0] ,i,0);
        pq.push(temp);
    }
    while(pq.size()>0){
        node* temp=pq.top();
        ans.push_back(temp->data);
        pq.pop();
        int row=temp->row;
        int col = temp->col;
        if(col+1< arr[row].size()){
            node* temp = new node(arr[row][col +1], row, col+1);
            pq.push(temp);
        }
        delete temp;
        
    }
    return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends
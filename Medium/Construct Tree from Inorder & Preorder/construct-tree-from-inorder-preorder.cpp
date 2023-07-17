//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    int findposition(int in[], int element, int start, int end) {
    for (int i = start; i <= end; i++) {
        if (in[i] == element) {
            return i;
        }
    }
    return -1;
}

    Node * solve(int in[],int pre[], int &preorderindex, int inorderstart, int inorderend,int size){
        if(preorderindex>=size || inorderstart>inorderend){
            return NULL;
        }
        int element= pre[preorderindex];
        preorderindex+=1;
        Node * temp=new Node(element);
        int position = findposition(in, element, inorderstart, inorderend);
 // position of element in inorder
        // recursive calls
        temp->left= solve(in,pre,preorderindex,inorderstart,position-1,size);
        temp->right = solve(in,pre,preorderindex,position+1,inorderend, size);
        return temp;
        
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        int preorderindex=0;
        Node * ans= solve(in,pre,preorderindex, 0,n-1,n);
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
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends
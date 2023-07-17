//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    Node * mappingandtargetfind(Node* root,int target,map<Node*,Node*> & nodetoparent){
        // applying Level order traversal;
        Node * position= NULL;
        queue<Node* >q;
        q.push(root);
        nodetoparent[root]=NULL;
        while(!q.empty()){
            Node * front= q.front();
            q.pop();
            if(front->data ==target){
                position=front;
            }
            if(front->left){
                nodetoparent[front->left]=front;
                q.push(front->left);
            }
            if(front->right){
                nodetoparent[front->right]=front;
                q.push(front->right);
            }
        }
        return position;
        
    }
    
    int burntree(Node* root,map<Node*,Node*> nodetoparent ){
        map<Node*,bool> visi;
        queue<Node*>q;
        q.push(root);
        visi[root] =1;
        int ans=0;
        while(!q.empty()){
            int n=q.size();
            bool change=0;
            for(int i=0;i<n;i++){
                
                Node*front=q.front();
                q.pop();
                if(front->left && visi[front->left]!=1){
                    change=1;
                    q.push(front->left);
                    visi[front->left]=1;
                }
                if(front->right && visi[front->right]!=1){
                    change=1;
                    q.push(front->right);
                    visi[front->right]=1;
                }
                if(nodetoparent[front] && visi[nodetoparent[front]]!=1){
                    change=1;
                    q.push(nodetoparent[front]);
                    visi[nodetoparent[front]]=1;
                }
            }
            if(change==1){
                ans++;
            }
        }
        return ans;
    }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        // map node with parent
        // find target node
        // start burning tree
        map<Node*,Node*> nodetoparent;
        Node * position = mappingandtargetfind(root,target,nodetoparent);   // it will give us the mappng and give target node
        int ans= burntree(position, nodetoparent);
        return ans;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends
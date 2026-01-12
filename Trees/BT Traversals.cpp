#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class Node{
    public:
    int data;
    Node* left,*right;
    Node(int x = 0){
        data = x;
        left = right = NULL;
    }
};

Node* createTree(Node* root){
    //Recursively creating a tree structure 
    cout<<"Enter data for node: "<<endl;
    int x ;
    cin >> x;
    if(x == -1){
        root = NULL;
        return root;
    }
    root = new Node(x);
    cout<<"Enter the data for left of "<<x<<endl;
    root->left = createTree(root->left);
    cout<<"Enter the data for right of "<<x<<endl;
    root->right = createTree(root->right);
    return root;
}

void levelOrderTrav(Node* root){
    //Root is at level 0
    queue<Node*> q;
    q.push(root);
    q.push(NULL); // Separator
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }

        else{
            cout<<temp->data<<" ";
            
            if(temp->left != NULL){
                q.push(temp->left);
            }

            if(temp->right != NULL){
                q.push(temp->right);
            }
        }
    }    
}

vector<int> reverseLevelOrder(Node *root)
{   
    stack<Node*> st;
    queue<Node*> q;
    vector<int> ans;
    q.push(root);
    
    while(!q.empty()){
        
        Node* curr = q.front();
        q.pop();
        if(curr->right){
            q.push(curr->right);
        }
        if(curr->left){
            q.push(curr->left);
        }
        st.push(curr);
    }
    
    while(!st.empty()){
        ans.push_back(st.top()->data);
        st.pop();
    }
    
    return ans;
}

void inOrderTraversal(Node* root){

    //LNR approach
    if(root == NULL){
        return;
    }
    if(root->left){
        inOrderTraversal(root->left);
    }
    cout<<root->data<<" ";
    if(root->right){
        inOrderTraversal(root->right);
    }
}

void preOrderTraversal(Node* root){

    //NLR
    if(root == NULL) return;
    cout<<root->data<<" ";
    if(root->left){
        preOrderTraversal(root->left);
    }
    if(root->right){
        preOrderTraversal(root->right);
    }
}

void postOrderTraversal(Node* root){
    //LRN
    if(root == NULL) return;
    if(root->left){
        postOrderTraversal(root->left);
    }
    if(root->right){
        postOrderTraversal(root->right);
    }
    cout<<root->data<<" ";
}

int main(){

    Node* root;
    root = createTree(root);
    //1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 8 -1 -1
    inOrderTraversal(root);
    cout<<endl;
    preOrderTraversal(root);
    cout<<endl;
    postOrderTraversal(root);
    cout<<endl;
}
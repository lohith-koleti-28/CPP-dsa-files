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

Node* buildFromLevelOrder(Node* &root){

    queue<Node*> q;
    cout<<"Enter data for node:\n";
    int x;
    cin >> x;
    root = new Node(x);
    q.push(root);

    while(!q.empty()){
        Node* curr = q.front();
        q.pop();

        cout<<"Enter data for left of "<<curr->data<<endl;
        cin >> x;
        if(x != -1){
            curr->left = new Node(x);
            q.push(curr->left);
        }
        cout<<"Enter data for right of "<<curr->data<<endl;
        cin >> x;
        if(x != -1){
            curr->right = new Node(x);
            q.push(curr->right);
        }
    }
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

int main(){

    Node* root;
    root = buildFromLevelOrder(root);
    //1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 8 -1 -1
    levelOrderTrav(root);
}   
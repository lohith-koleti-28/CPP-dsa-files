#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node * next;
    Node(int x =0){
        data = x;
        next =NULL;
    }
};

void insertFirst(Node* &head,int x){
    //x is the value 
    Node *n = new Node(x);
    n->next = head;
    head = n;
}

void insertAtPos(Node* &head,int k,int x){
    //k is the position 
    //Assuming 0 based indexing
    Node* new_node = new Node(x);
    Node *temp = head;
    if(k==0){
        new_node->next = head;
        head =new_node;
    }
    else{
        while(k-1){
            temp = temp->next;
            k--;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

void updateKPos(Node* &head,int k , int x){
    Node* temp = head;
    while(k){
        temp = temp->next;
        k--;
    }
    temp->data = x;

}

void insertLast(Node* &head,int x){
    Node *new_node = new Node (x);
    Node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->next = NULL;
}

void deleteAtPos(Node* &head,int k){
    // here k should be strictly less than the size-1
    if(k == 0){
        Node* temp = head->next;
        delete head;
        head = temp;
    }
    else{
        Node* temp = head;
        while(k - 1){
            temp = temp->next;
            k--;
        }
        //temp points to node b4 kth one
        Node * del = temp->next;
        temp->next = temp->next->next;
        delete del;
    }
}

void deleteAtTail(Node* &head){
    Node* temp = head;
    if(temp->next = NULL){
        delete head;
        head->next = NULL;
    }
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
}

void print(Node* head){
    Node *temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

int main(){
    Node *head;
    head = NULL;
    int n;
    cin >> n;
    int t;
    cin >> t;
    insertFirst(head,t);
    for(int i=1;i<n;i++){
        int t;
        cin >> t;
        insertLast(head,t);
    }
    print(head);
    // int k;
    // cin >> k;
    // cin >> t;
    deleteAtTail(head);
    print(head);
}

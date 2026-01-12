#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int x=0){
        data = x;
        next = NULL;
    }
};

class LinkedList{
    public:
    Node* head;
    LinkedList(){
        head = NULL;
    }
    LinkedList(Node* &ptr){
        head = ptr;
    }
    
    void insertAtTail(int x){
        Node* new_node = new Node (x);
        if(head == NULL){
            head = new_node;
            new_node->next = NULL;
            return;
        }
        Node * temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->next = NULL;
    }

    void insertAtHead(int x){
        Node *new_node = new Node(x);
        new_node->next = head;
        head = new_node;
    }

    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"NULL\n";
    }
};

int getLength(Node* head){
    int ans = 0;
    while(head != NULL){
        head = head->next;
        ans++;
    }
    return ans;
}

Node* removeHead(Node* &head){
    if(head == NULL){
        return head;
    }
    else{
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    return head;
}

bool palindromeLL(Node* head){
    Node* sl,*f;
    sl = f = head;
    while(f != NULL && f->next != NULL){
        sl = sl->next;
        f = f->next->next;
    }
    Node* curr = sl->next;
    sl->next = NULL;
    Node* prev = sl;
    while(curr != NULL){
        Node* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    //prev is head of reversed ll
    Node* h1 = head,*h2 = prev;
    while(h1 && h2){
        if(h1->data != h2->data){
            return false;
        }
        h1 = h1->next;
        h2 = h2->next;
    }
    return true;
}

int main(){
    LinkedList l1;
    l1.insertAtTail(1);
    l1.insertAtTail(2);
    l1.insertAtTail(3);
    // l1.insertAtTail(3);
    l1.insertAtTail(2);
    l1.insertAtTail(1);
    // l1.insertAtTail(4);
    // l1.head->next->next->next->next->next->next = l1.head->next->next;
    // l1.display();
    l1.display();
    cout<<palindromeLL(l1.head)<<"\n";
}


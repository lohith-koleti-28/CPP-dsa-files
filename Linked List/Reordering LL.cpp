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

Node* reOrder(Node* &head){
    //Orders like 
    //L1LnL2Ln-2...
    if(head == NULL || head->next == NULL){
        return head;
    }
    //Find middle element
    Node* s = head,*f = head;
    while(f && f->next){
        s = s->next;
        f = f->next->next;
    }
    Node* curr = s->next;
    s->next = NULL;
    Node* prev = NULL;
    //Reverse the List after slow ptr
    while(curr){
        Node* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    //prev has tail ptr
    //of reversed from mid
    curr = head;
    while(prev ){
        Node* temp = curr->next;
        curr->next = prev;
        Node* t2 = prev->next;
        prev->next = temp;
        curr = temp;
        prev = t2;
    }
    return head;
}

int main(){
    LinkedList l1;
    l1.insertAtTail(1);
    l1.insertAtTail(2);
    l1.insertAtTail(3);
    l1.insertAtTail(4);
    l1.insertAtTail(5);
    // l1.insertAtTail(6);
    // l1.insertAtTail(4);
    // l1.display();
    // int k;
    // cin >> k;
    // // l1.head = kRotations(l1.head,k);
    // l1.head = kRotations2(l1.head,k);
    l1.display();
    reOrder(l1.head);
    l1.display();
}


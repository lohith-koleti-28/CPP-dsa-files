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

Node* intersection(Node* head1,Node* head2){
    int len1 = getLength(head1);
    int len2 = getLength(head2);
    // Node* lenptr = head1;
    // while(lenptr != NULL){
    //     len1++;
    //     lenptr = lenptr->next;
    // }
    // lenptr = head2;
    // while(lenptr != NULL){
    //     len2++;
    //     lenptr = lenptr->next;
    // }
    int forward = (len1 >= len2) ? len1 - len2 : len2 - len1;
    Node* hLong = (len1 >= len2) ? head1 : head2;
    Node* hShort = (len1 >= len2) ? head2 : head1;
    while(forward--){
        hLong = hLong->next;
    }
    while(hLong != NULL){
        if(hLong == hShort){
            return hLong;
        }
        hLong = hLong->next;
        hShort = hShort->next;
    }
    return NULL;
}

int main(){
    LinkedList l1,l2;
    l1.insertAtTail(1);
    l1.insertAtTail(2);
    l1.insertAtTail(3);
    l2.insertAtTail(6);
    l2.head->next = l1.head->next;
    cout<<intersection(l1.head,l2.head)<<endl;
    cout<<l1.head->next<<endl;
}


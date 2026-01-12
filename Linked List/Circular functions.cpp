#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int x = 0){
        next = NULL;
        data = x;
    }
    ~Node(){
        delete this;
    }
};

class circularLinkedList{

    public:
    Node* head,*tail;
    circularLinkedList(){
        head = NULL;
        tail = NULL;
    }

    void insertAtStart(int x){

        Node* newNode = new Node(x);
        if(head == NULL){
            head = newNode;
            head->next = head;
            //As it is a circularLL
            return;
        }
        Node* tail = head;
        while(tail->next != head){
            tail = tail->next;
        }
        tail->next = newNode;
        newNode->next = head;
        head = newNode;
        return;
    }

    void insertAtTail(int x){

        Node* newNode = new Node(x);
        if(head == NULL){
            head = newNode;
            head->next = head;
            return;
        }

        Node *tail = head;
        while(tail->next != head){
            tail = tail->next;
        }
        tail->next = newNode;
        newNode->next = head;
    }

    void display(){
        if(head == NULL){
            return;
        }
        cout<<head->data<<" ";
        Node* curr = head->next;

        while(curr != head){
            cout<<curr->data<<" ";
            curr = curr->next;
        }
        cout<<"\n";
    }

    void insertAtKthPos(int k, int x){
        //For 0 based indexing
        if(k==0){
            insertAtStart(x);
            return;
        }
        Node* curr = head;
        while(k-1){
            curr = curr->next;
            k--;
        }
        //Node is to be put after curr
        Node* newNode = new Node(x);
        newNode->next = curr->next;
        curr->next = newNode;

    }

    void deleteAtStart(){
        if(head == NULL){
            return;
        }
        Node* tail = head;
        while(tail->next != head){
            tail = tail->next;
        }
        Node* temp = head;
        tail->next = head->next;
        head = head->next;
        free(temp);
    }

    void deleteAtTail(){
        if(head == NULL){
            return;
        }

        if(head->next == head){
            free(head);
            head = NULL;
            return;
        }

        Node* before = head;
        while(before->next->next != head){
            before = before->next;
        }
        Node* temp = before->next;
        before->next = head;
        free(temp);
    }

    void deleteAtKthPos(int k){
        if(k==0){
            deleteAtStart();
            return;
        }

        Node* curr = head;
        while(k-1 >0){
            curr = curr->next;
            k--;
        }
        Node* temp = curr->next;
        curr->next = temp->next;
        free(temp);
    }
};

int main(){

    circularLinkedList c;
    c.insertAtTail(4);
    c.insertAtTail(3);
    c.insertAtTail(2);
    c.insertAtTail(1);
    c.display();
    int k;
    cin >> k;
    c.deleteAtKthPos(k);
    c.display();
}
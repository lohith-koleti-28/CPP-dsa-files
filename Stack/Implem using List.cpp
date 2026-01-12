#include<iostream>
#include<vector>
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

class Stack{

    //using LinkedList and 0 based indexing
    Node* head;
    int capacity;
    int idx;

    public:
    Stack(int c=0){
        capacity = c;
        idx = 0;
        head = NULL;
    }
    void push(int x){
        if(idx == capacity-1){
            cout<<"Overflow\n";
            return;
        }

        Node* newNode = new Node(x);
        newNode->next = head;
        head = newNode;
        idx++;
    }

    void pop(){
        if(head == NULL){
            cout<<"Underflow\n";
            return;
        }

        Node* temp = head;
        head = head->next;
        free(temp);
        idx--;
    }

    int top(){
        if(head == NULL){
            cout<<"EMPTY\n";
            return INT32_MAX;
        }
        return head->data;
    }

    bool isEmpty(){
        return !head;
    }
    bool isFull(){
        return idx == capacity-1;
    }

};

int main(){

    Stack s(11);
    for(int i=1;i<11;i++){
        s.push(i);
    }
    cout<<s.top()<<endl;
    for(int i=1;i<11;i++){
        s.pop();
    cout<<s.top()<<endl;
    }
    
}
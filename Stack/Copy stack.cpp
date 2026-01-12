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
    int idx;

    public:
    int capacity;
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
        return head == NULL;
    }
    bool isFull(){
        return idx == capacity-1;
    }

};

void copyStack(Stack &in,Stack &result){
    if(result.capacity < in.capacity){
        cout<<"Resultant stack has less capacity\n";
        return;
    }

    Stack temp(in.capacity);
    while(!in.isEmpty()){
        temp.push(in.top());
        in.pop();
    }
    
    while(!temp.isEmpty()){
        result.push(temp.top());
        temp.pop();
    }
}

void copyStackRec(Stack &in, Stack &res){
    //Recursive function
    //Here the temp stack is the call
    //stack itself
    if(in.isEmpty()){
        return;
    }

    int curr = in.top();
    in.pop();
    copyStackRec(in,res);
    res.push(curr);
}


int main(){

    Stack s(11),r(11);
    for(int i=1;i<11;i++){
        s.push(i);
    }
    
    copyStackRec(s,r);
    for(int i=0;i<10;i++){
        cout<<r.top()<<"\n";
        r.pop();
    }
}
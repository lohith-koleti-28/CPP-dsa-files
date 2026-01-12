#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int x = 0){
        data = x;
        next = NULL;
    }
};

class Queue{

    Node* head,*tail;
    int size;
    public:
    //Constructor
    Queue(){
        head = tail = NULL;
        size = 0;
    }

    void enqueue(int x){
        Node* new_node = new Node(x);
        if(head == NULL){
            head = new_node;
            tail = head;
        }
        else{
            tail->next = new_node;
            tail = tail->next;
        }
        size++;
    }

    void dequeue(){
        if(head == NULL){
            cout<<"UnderFlow\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        free(temp);
        size--;
        if(head == NULL){
            tail = NULL;
        }
    }

    int front(){
        if(head == NULL){
            cout<<"UnderFlow\n";
            return INT32_MAX;
        }
        return head->data;
    }

    bool isEmpty(){
        return size == 0;
    }

    int getSize(){
        return size;
    }

    void display(){
        Queue temp = *this;
        while(!temp.isEmpty()){
            cout<<temp.front()<<" ";
            temp.dequeue();
        }
        cout<<endl;
    }
};

int main(){

    Queue q;
    for(int i=1;i<4;i++){
        q.enqueue(10*i);
    }
    q.dequeue();
    q.enqueue(40);
    q.display();
}
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Queue{
    vector<int> v;
    int front,back;
    public:
    Queue(){
        front = back = -1;
    }

    void enqueue(int x){
        if(front == -1){
            front++;
        }
        v.push_back(x);
        back++;
    }

    void dequeue(){
        front++;
    }

    int head(){
        if(front == -1){
            return INT32_MAX;
        }
        return v[front];
    }

    bool isEmpty(){
        return front == back;
    }

    void display(){
        Queue t = *this;
        while(!t.isEmpty()){
            cout<<(t.head())<<" ";
            t.dequeue();
        }
        cout<<endl;
    }
};

void reverseQueue(queue<int> &qu){
    if(qu.empty()){
        return;
    }
    int curr = qu.front();
    qu.pop();
    reverseQueue(qu);
    qu.push(curr);
}

int main(){
    queue<int> qu;
    for(int i=10;i>0;i--){
        qu.push(i*10);
    }
    reverseQueue(qu);
    while(!qu.empty()){
        cout<<qu.front()<<" ";
        qu.pop();
    }
    cout<<endl;
}
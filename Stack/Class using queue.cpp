#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Stack1{
    //Push efficient
    //Here didnt used recursion as using a queue with call stack
    queue<int> q;
    public:
    void push(int x){
        q.push(x);
    }

    void pop(){
        if(q.empty()) return;
        queue<int> temp;
        while(q.size() > 1){
            temp.push(q.front());
            q.pop();
        }
        q.pop();
        while(!temp.empty()){
            q.push(temp.front());
            temp.pop();
        }
    }

    int top(){
        if(q.empty()) return INT32_MAX;
        queue<int> temp;
        while(q.size() > 1){
            temp.push(q.front());
            q.pop();
        }
        int ans = q.front();
        q.pop();
        while(!temp.empty()){
            q.push(temp.front());
            temp.pop();
        }
        q.push(ans);
        return ans;
    }

    bool empty(){
        return q.empty();
    }

};

class Stack2{
    //Pop efficient
    queue<int> q;
    public:
    void pop(){
        if(q.empty()) return;
        q.pop();
    }

    void push(int x){
        queue<int> temp;
        while(!q.empty()){
            temp.push(q.front());
            q.pop();
        }
        q.push(x);
        while(!temp.empty()){
            q.push(temp.front());
            temp.pop();
        }
    }

    int top(){
        if(q.empty()) return INT32_MAX;
        return q.front();
    }

    bool empty(){
        return q.empty();
    }
};

int main(){
    Stack2 st;
    for(int i=1;i<11;i++){
        st.push(10*i);
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}
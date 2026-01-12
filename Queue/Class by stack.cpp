#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Queue1{
    //Push efficient implementation
    //Push is of O(1)
    //Pop is of O(n)
    stack<int> st;
    public:

    bool empty(){
        return st.size() == 0;
    }

    void push(int x){
        st.push(x);
    }

    void pop(){
        if(st.size() == 0){
            return;
        }
        if(st.size() == 1){
            st.pop();
            return;
        }
        int curr = st.top();
        st.pop();
        this->pop();
        st.push(curr);
    }

    int top(){
        if(st.size() == 1){
            return st.top();
            st.pop();
        }
        int curr = st.top();
        st.pop();
        int n = this->top();
        st.push(curr);
        return n;
    }

};

class Queue2{
    //Pop efficient
    stack<int> st;
    public:
    void pop(){
        if(st.empty()) return;
        st.pop();
    }

    void push(int x){
        if(st.empty()){
            st.push(x);
            return;
        }
        int curr = st.top();
        st.pop();
        this->push(x);
        st.push(curr);
    }

    int top(){
        if(st.empty()) return INT32_MAX;
        return st.top();
    }

    bool empty(){
        return st.empty();
    }
};

int main(){
    Queue2 q;
    for(int i=0;i<10;i++){
        q.push(i*10);
    }
    while(!q.empty()){
        cout<<q.top()<<" ";
        q.pop();
    }
    cout<<"\n";
}
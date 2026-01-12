#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &st , int x){

    stack<int> temp;
    while(!st.empty()){
        temp.push(st.top());
        st.pop();
    }
    st.push(x);
    while(!temp.empty()){
        st.push(temp.top());
        temp.pop();
    }
}

void reverseStackRec(stack<int> &st){
    //Time complexity = O(n2)
    if(st.empty()){
        return;
    }
    int curr = st.top();
    st.pop();
    reverseStackRec(st);
    insertAtBottom(st,curr);
}

void reverseStack(stack<int> &st){
    stack<int> t1,t2;
    while(!st.empty()){
        t1.push(st.top());
        st.pop();
    }
    while(!t1.empty()){
        t2.push(t1.top());
        t1.pop();
    }
    while(!t2.empty()){
        st.push(t2.top());
        t2.pop();
    }
}

int main(){
    stack<int> st;
    for(int i=1;i<11;i++){
        st.push(i);
    }
    reverseStack(st);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<"\n";
}
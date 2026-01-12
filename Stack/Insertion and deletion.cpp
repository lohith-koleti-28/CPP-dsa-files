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

void insertAtKthPos(stack<int> &st,int k , int x){
    //Assuming top element has index = 0;
    stack<int> temp;
    while(k > 0 && !st.empty()){
        temp.push(st.top());
        st.pop();
        k--;
    }
    st.push(x);
    while(!temp.empty()){
        st.push(temp.top());
        temp.pop();
    }
}

void insertAtKthPosRec(stack<int> &st , int k, int x){
    //Recursive function
    if(k <= 0 || st.empty()){
        st.push(x);
        return;
    }
    int curr = st.top();
    st.pop();
    insertAtKthPosRec(st,k-1,x);
    st.push(curr);
}

void deleteAtBottom(stack<int> &st){
    //Recursive soltion
    if(st.size() == 1){
        st.pop();
        return;
    }
    int curr = st.top();
    st.pop();
    deleteAtBottom(st);
    st.push(curr);
}

void deleteAtKthPos(stack<int> &st , int k){
    //Recursive and bottom element of stack
    //has index 0
    if(k == 0){
        deleteAtBottom(st);
        return;
    }
    if(st.size() - k == 1){
        st.pop();
        return;
    }
    int curr = st.top();
    st.pop();
    deleteAtKthPos(st,k);
    st.push(curr);
}

//For iterative solution create a temp stack
//copy elements till needed then perform operation
//then reverse it back

int main(){
    stack<int> st;
    for(int i=1;i<11;i++){
        st.push(i);
    }
    int k;
    cin >> k;
    deleteAtKthPos(st,k);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<"\n";
}
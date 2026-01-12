#include<iostream>
#include<vector>
using namespace std;

class Stack{
    
    vector<int> v;
    int topIdx;

    public:
    //Following 0 based indexing for stack indices
    int size;
    Stack(int siz = 0){
        topIdx = -1;
        v = vector<int> (siz);
        size = siz;
    }

    void push(int x){
        if(topIdx >= size-1){
            cout<<"Overflow\n";
            return;
        }
        else{
            topIdx++;
            v[topIdx] = x;
        }
    }
    void pop(){
        if(topIdx == -1){
            cout<<"Underflow\n";
            return;
        }
        else{
            topIdx--;
        }
    }
    bool isEmpty(){
        if(topIdx == -1){
            return true;
        }
        return false;
    }
    bool isFull(){
        if(topIdx == size-1){
            return true;
        }
        return false;
    }
    int top(){
        if(topIdx == -1){
            return INT32_MAX;
        }
        return v[topIdx];
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
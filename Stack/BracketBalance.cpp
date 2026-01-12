#include<iostream>
#include<stack>
using namespace std;

bool bracketBalanced(string s){
    //Assuming s contain only parenthesis
    stack<bool> st;
    for(int i=0;i<s.size();i++){
        if(s[i] == '('){
            st.push(1);
        }
        else if(s[i] == ')'){
            if(st.empty()){
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}

bool bracBal(string s){
    //Taking s has ( , [, {
    //Assuming that s has only brackets open or close
    stack<char> st;
    for(int i=0;i<s.size();i++){
        if(s[i] == '(' || s[i] =='[' || s[i] == '{'){
            st.push(s[i]);
        }
        else{
            if(st.empty()){
                    return false;
                }
            if((st.top() == '{' && s[i] == '}') || (st.top() == '[' && s[i] == ']') || (st.top() == '(' && s[i] == ')')){
                
                st.pop();
            }
            else return false;
        }
    }
    return st.empty();
}

int main(){

    string s;
    cin >> s;
    cout<<bracBal(s)<<"\n";
}
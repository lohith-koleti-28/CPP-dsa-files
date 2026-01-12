#include<iostream>
#include<stack>
#include<cmath>
using namespace std;

int numberOfBrac(string s){
    //Gives the number of brackets required 
    //to complete the bracket seq
    stack<int> st;
    int ans = 0;
    for(int i=0;i<s.size();i++){
        if(s[i] == '{' || s[i] == '[' || s[i] == '('){
            st.push(s[i]);
        }
        else if(st.empty()){
            ans++;
            continue;
        }
        else if ((st.top() == '{' && s[i] == '}') || 
                (st.top() == '[' && s[i] == ']') || (st.top() == '(' && s[i] == ')') ){
            st.pop();
        }
        else{
            ans++;
        }
    }
    // cout<<"Size of stack is: "<<st.size()<<endl;
    return ans + st.size();
}

int postFix(string &s){

    stack<int> st;
    for(int i=0;i<s.size();i++){
        if(s[i] >='0' && s[i] <='9'){
            st.push(s[i] - '0');
        }
        else{
            //Assuming operator
            int op2 = st.top();
            st.pop();
            int op1 = st.top();
            st.pop();
            int res;
            if(s[i] == '*'){
                res = op1 * op2;
            }
            else if(s[i] == '+'){
                res = op1 + op2;
            }
            else if(s[i] == '-'){
                res = op1 - op2;
            }
            else if(s[i] == '/'){
                res = op1 / op2;
            }
            st.push(res);
        }
    }
    return st.top();
}

int preFix(string &s){
    //Just reversed the order of iteration
    stack<int> st;
    for(int i=s.size()-1;i>=0;i--){
        if(s[i] >='0' && s[i] <='9'){
            st.push(s[i] - '0');
        }
        else{
            //Assuming operator
            int op2 = st.top();
            st.pop();
            int op1 = st.top();
            st.pop();
            int res;
            if(s[i] == '*'){
                res = op1 * op2;
            }
            else if(s[i] == '+'){
                res = op1 + op2;
            }
            else if(s[i] == '-'){
                res = op1 - op2;
            }
            else if(s[i] == '/'){
                res = op1 / op2;
            }
            st.push(res);
        }
    }
    return st.top();
}

int calc(int n1, int n2, char op){
    if(op == '+'){
        return n1 + n2;
    }
    else if(op == '/'){
        return n1 / n2;
    }
    else if(op == '*'){
        return n1 * n2;
    }
    else if(op == '^'){
        return pow(n1,n2);
    }
    else{
        return n1 - n2;
    }
}

int precedence(char c){
    //defining the precedence of operators
    if(c == '^') return 3;
    else if(c == '*' || c == '/') return 2;
    else if(c == '+' || c == '-') return 1;
    else return 0;
}

int infix(string &s){
    //Includes BODMAS
    stack<int> num;
    stack<char> op;
    for(int i=0;i<s.size();i++){
        if(s[i] >= '0' && s[i] <= '9'){
            num.push(s[i]- '0');
        }
        else if(s[i] == '('){
            op.push(s[i]);
        }
        else if(s[i] == ')'){
            while(!op.empty() && op.top() != '('){
                char c = op.top();
                op.pop();
                int op2 = num.top();
                num.pop();
                int op1 = num.top();
                num.pop();
                num.push(calc(op1,op2,c));
            }
            if(!op.empty()) op.pop();
        }
        else {
            while(!op.empty() && (s[i]) < precedence(op.top())){
                char c = op.top();
                op.pop();
                int op2 = num.top();
                num.pop();
                int op1 = num.top();
                num.pop();
                num.push(calc(op1,op2,c));
            }
            op.push(s[i]);
        }
    }
    while(! op.empty()){
        char c = op.top();
        op.pop();
        int op2 = num.top();
        num.pop();
        int op1 = num.top();
        num.pop();
        num.push(calc(op1,op2,c));
    }
    if(num.empty()) return INT32_MIN;
    return num.top();
}

string prefixToPostfix(string &s){
    stack<string> st;
    //Taking ASCII instead of Char
    for(int i=s.size()-1;i>=0;i--){
        if(s[i]>='0' && s[i] <= '9'){
            st.push(to_string(s[i]));
        }
        else{
            string s1 = st.top();
            st.pop();
            string s2 = st.top();
            st.pop();
            string res = s1 + s2 + s[i];
            cout<<s1<<" "<<s2<<" "<<res<<endl;
            st.push(res);
            cout<<st.top()<<endl;
        }
    }
    return st.top();
}

int main(){
    string s;
    cin >> s;
    // cout<<postFix(s)<<"\n";
    cout<<prefixToPostfix(s)<<"\n";
}
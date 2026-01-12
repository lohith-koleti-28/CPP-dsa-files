#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> stockSpan(vector<int> &v){
    //Bruteforce solution
    vector<int> span(v.size(),1);
    for(int i=1;i<v.size();i++){
        for(int j=i-1;j>=0;j--){
            if(v[i] >= v[j]){
                span[i]++;
            }
            else break;
        }
    }
    return span;
}

vector<int> nGE(vector<int> &v){
    int n = v.size();
    stack<int> st;
    st.push(0);
    vector<int> ans(n);
    for(int i=1;i<n;i++){
        while(!st.empty() && v[i] > v[st.top()]){
            ans[st.top()] = v[i];
            st.pop();
        }
        st.push(i);
    }
    return ans;
}

vector<int> pGE(vector<int> v){
    int n = v.size();
    reverse(v.begin(),v.end());
    stack<int> st;
    st.push(0);
    vector<int> ans(n);
    for(int i=1;i<n;i++){
        while(!st.empty() && v[i] > v[st.top()]){
            ans[st.top()] = v[i];
            st.pop();
        }
        st.push(i);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> in(n);
    for(int i=0;i<n;i++){
        cin >> in[i];
    }
    vector<int> r = stockSpan(in);
    for(int i=0;i<n;i++){
        cout << r[i]<<" ";
    }
    cout<<"\n";
}
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int max(vector<int> &v){
    int m = v[0];
    for(int i=1;i<v.size();i++){
        if(m < v[i]){
            m = v[i];
        }
    }
    return m;
}

vector<int> reverse(vector<int> v){
    int n = v.size();
    for(int i=0;i<n/2;i++){
        swap(v[i],v[n-i-1]);
    }
    return v;
}

vector<int> nSE(vector<int> &v){
    int n = v.size();
    vector<int> ans(n,n);
    stack<int> st;
    st.push(0);
    for(int i =1;i<n;i++){
        while(!st.empty() && v[i] < v[st.top()]){
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    return ans;
}

vector<int> pSE(vector<int> &v){
    int n = v.size();
    vector<int> ans(n,-1);
    stack<int> st;
    st.push(0);
    vector<int> p = reverse(v);
    for(int i =1;i<n;i++){
        while(!st.empty() && v[i] < v[st.top()]){
            ans[n - st.top() - 1] = n-i;
            st.pop();
        }
        st.push(i);
    }
    reverse(ans);
    return ans;
}
int maxR(vector<int> &ht){
    //Get the prev small and next small indices
    //and then use formula
    vector<int> area(ht.size(),0);
    vector<int> prev = pSE(ht);
    vector<int> next = nSE(ht);
    for(int i=0;i<ht.size();i++){
        area[i] = (next[i] - prev[i] - 1) * ht[i];
    }
    return max(area);
}

int main(){
    int n;
    cin >> n;
    vector<int> in(n);
    for(int i=0;i<n;i++){
        cin >> in[i];
    }
    // vector<int> r = pSE(in);
    // for(int i=0;i<n;i++){
    //     cout << r[i] << " ";
    // }
    // cout<<endl;
    cout<<maxR(in)<<endl;
}
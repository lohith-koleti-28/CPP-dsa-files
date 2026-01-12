#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void f(string &s ,unsigned int idx,string result , vector<string> &v){
    if(idx == s.size()){
        v.push_back(result);
        return;
    }
    f(s,idx+1,result + s[idx] , v);
    f(s,idx+1,result,v);
}
bool check(string &a,string &b){
    return a.size()<b.size();
}
int main(){
    string a;
    cin >> a;
    vector<string> v;
    f(a,0,"",v);
    sort(v.begin(),v.end(),check);
    // for(string i:v) cout<<i<<" ";
    for(int i=1;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
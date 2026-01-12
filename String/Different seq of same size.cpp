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
    f(s,idx+1,s[idx] + result, v);
}
void eraser(vector<string> &v){
    for(auto i = v.begin();i<v.end();i++){
        for(auto j = i+1;j<v.end();j++){
            if(*i == *j){
                v.erase(j);
            }
        }
    }
}
int main(){
    string a;
    cin >> a;
    vector<string> v;
    f(a,0,"",v);
    for(int i=0;i<v.size()/2;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
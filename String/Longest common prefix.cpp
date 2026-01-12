#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;   

string longestPrefix(vector<string> &v){
    if(v.empty()) return "";
    string current = v[0];
    for(int i=1;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            if(current[j] != v[i][j]){
                current  = current.substr(0,j);
                break;
            }
        }
    }
    return current;
}

string longestPrefix2(vector<string> &v){
    sort(v.begin(),v.end());
    string current = v[0];
    int n = v.size();
    for(int i=0;i<v[n-1].size();i++){
        if(current[i] != v[n-1][i]){
            current = current.substr(0,i);
            break;
        }
    }
    return current;
}   

int main(){
    int n;
    cin >> n;
    vector<string> v(n);
    for(string &i : v) cin >> i;
    cout<<longestPrefix(v)<<"\n";
    cout<<longestPrefix2(v)<<"\n";
}
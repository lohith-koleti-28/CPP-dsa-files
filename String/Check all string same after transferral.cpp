#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main(){

    int n;
    cin >> n;
    vector<string> v(n);
    for(auto &t : v){
        cin >> t;
    }
    unordered_map<char , int> m;
    for(int i=0;i<26;i++){
        m[i+'a'] = 0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<v[i].size();j++){
            m[v[i][j]]++;
        }
    }
    for(auto i : m){
        if(i.second % n != 0){
            cout<<"No\n";
            return 0;
        }
    }
    cout<<"Yes\n";
    string ans;

    for(auto i : m){
        if(i.second != 0){
            int j = i.second/n;
            while(j--){
                ans += i.first;
            }
        }
    }
    cout<<ans<<endl;
}
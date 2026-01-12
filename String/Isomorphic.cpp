#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

bool areIsomorphic(string &s1 , string &s2){
    if(s1.size() != s2.size()) return false;
    unordered_map<char,char> m;
    for(int i=0;i<26;i++){
        m[i + 'a'] = 0;
    }
    for(int i=0;i<s1.size();i++){
        if(m[s1[i]] == 0){
            m[s1[i]] = s2[i];
        }
        else if(s2[i] != m[s1[i]]){
            return false;
        }
    }

    //Now exchanging the keys with value
    for(int i=0;i<26;i++){
        m[i + 'a'] = 0;
    }
    for(int i=0;i<s2.size();i++){
        if(m[s2[i]] == 0){
            m[s2[i]] = s1[i];
        }
        else if(s1[i] != m[s2[i]]){
            return false;
        }
    }
    return true;
}

int main(){

    string s1,s2;
    cin >> s1 >> s2;
    cout<<boolalpha<<areIsomorphic(s1,s2)<<"\n";
}
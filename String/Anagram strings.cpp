#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

bool areAnagrams(string &s1 , string &s2){
    if(s1.size() != s2.size()) return false;
    unordered_map<char,int> m;
    for(int i=0;i<26;i++){
        m[i+'a'] = 0;
    }
    for(int i=0;i<s1.size();i++){
        m[s1[i]]++;
        m[s2[i]]--;
    }
    for(auto i : m){
        if(i.second != 0) return false;
    }
    return true;
}

int main(){

    string s1,s2;
    cin >> s1 >> s2;
    cout<<boolalpha<<areAnagrams(s1,s2)<<"\n";
}
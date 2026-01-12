#include<iostream>
#include<vector>
#include<string>
using namespace std;

string reverse(string &s){
    int n = s.size();
    for(int i=0;i<n/2;i++){
        swap(s[i],s[n-i-1]);
    }
    return s;
}

string decoded(string s){
    string result = "";
    for(int i=0;i<s.size();i++){
        //Traversing the string;

        if(s[i] != ']'){
            result.push_back(s[i]);
        }
        else{
            string str("");
            while( (!result.empty()) && result.back() != '['){
                str.push_back(result.back());
                result.pop_back();
            }

            reverse(str);
            result.pop_back();
            string n("");
            while((!result.empty()) && result.back()>='0' && result.back() <= '9'){
                n.push_back(result.back());
                result.pop_back();
            }
            reverse(n);
            int num = stoi(n);
            while(num){
                result += str;
                num--;
            }
        }
    }
    return result;
}

int main(){
    string s;
    cin >> s;
    cout<<decoded(s)<<endl;
}
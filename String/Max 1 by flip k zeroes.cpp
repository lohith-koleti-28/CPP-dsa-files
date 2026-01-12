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

int kFlip(string s,int k){
    //Bruteforce solution
    //Longest string of consecutive 1's st you can
    //flip at most k zeroes
    for(int i=0;i<s.size();i++){
        int zeroes = 0;
        int len = 0;
        bool breaked = false;
        for(int j = i;j<s.size();j++){
            len++;
            if(s[j] == '0'){
                zeroes++;
            }
            if(zeroes > k){
                breaked = true;
                break;
            }
        }
        if(!breaked){
        return len;
        }
    }
    return 0;
}

int kFlip2(string str,int k){
    //Sliding window approach
    if(str.empty()){
        //Handling empty string
        return 0;
    }
    //for negative k
    k = max(0,k);
    int s=0,e=0;
    int zeroes = 0;
    int len = 0;
    while( s<=e && e<str.size()){
        if(str[e] == '0'){
            zeroes++;
        }
        len++;
        e++;
        while(zeroes > k){
            if(str[s] == '0'){
                zeroes--;
            }
            len--;
            s++;
        }
    }
    return len;
}

int main(){
    string s;
    cin >> s;
    int k;
    cin >> k;
    cout<<kFlip(s,k)<<endl;
    cout<<kFlip2(s,k)<<endl;
}
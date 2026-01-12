#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

vector<int> twoSum(vector<int> &v , int k){
    //Bruteforce approach
    vector<int> ans(2,-1);
    for(int i=0;i<v.size()-1;i++){
        for(int j = i+1;j<v.size();j++){
            if(v[i] + v[j] == k){
                ans[0] = i;
                ans[1] = j;
                return ans;
            }
        }
    }
    
    return ans;
}

vector<int> twoSumOpt(vector<int> &v , int k){

    //2 Pointer approach
    //Keys are values in array and value as their indices
    //Has time complexity O(1)
    unordered_map<int,int> m;
    vector<int> ans(2,-1);
    for(int i=0;i<v.size();i++){
        m[v[i]] = i;
        if(m.find(k - v[i]) != m.end()){
            ans[0] = m[v[i]];
            ans[1] = m[k - v[i]];
            if(ans[0] > ans[1]){
                swap(ans[0],ans[1]);
            }
            return ans;
        }
    }
    return ans;
}


int main(){

    int n;
    cin >> n;
    vector<int> v(n);
    for(int &i : v){
        cin >> i;
    }
    int k;
    cin >> k;
    vector<int> r = twoSum(v,k);
    vector<int> s = twoSumOpt(v,k);
    cout<<"BruteForce: ";
    cout<<r[0]<<" "<<r[1]<<endl;
    cout<<"2 Pointer:  ";
    cout<<s[0]<<" "<<s[1]<<endl;
}